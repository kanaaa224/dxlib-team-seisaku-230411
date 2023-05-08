// 作：島袋

#include <string>
using std::string;
using std::to_string;

#include "DxLib.h"

#include "resourceLoad.h"
extern Image image;
extern Font font;

#include "ranking_name_input.h"
NameInput nameInput;

#include "main.h"
extern Game game;

#include "PadInput.h"
int rni_selectstate;
int rni_stickflg = 0;

char rni_alphabet[][26] = {
	{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
	{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' },
	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }
};
//char rni_qwerty[] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };

std::string rni_inputName = "";
int rni_selecter[] = { 90, 440, 35, 30, 0, 0 };
int rni_state = 0;

#include "Apple.h"
#include "ranking.h"

/********************************
* ランキング入力処理
********************************/
void DrawRankingNameInput() { // 島袋が担当中、仮完成
    // 背景表示
    DrawGraph(0, 0, image.title, TRUE);

	// タイトル
	DrawStringToHandle(250, 50, "ランキングに登録", 0x000000, font.handle_1_64, 0xffffff);

	// 本文
	std::string str = "スコア：" + std::to_string(ReturnScore());
	DrawStringToHandle(750, 70, str.c_str(), 0x000000, font.handle_1_32, 0xffffff);

	DrawStringToHandle(140, 150, "あなたのスコアが上位５位内に入りました！おめでとうございます。", 0x000000, font.handle_1_32, 0xffffff);

	DrawStringToHandle(110, 200, "ということで、ランキングに追加します。あなたの名前をどうぞ（強制）", 0x000000, font.handle_1_32, 0xffffff);

	// フォントサイズの設定
	//ChangeFontSize(40); // ループ内で一回のみ機能、二回目は激重になる → バグ発生中、機能しません

	// 開発用
	//DrawFormatString(600, 20, 0x000000, "%d - %d / %d - %d / %c / %d", rni_selecter[0], rni_selecter[1], rni_selecter[4], rni_selecter[5], rni_alphabet[rni_selecter[4]][rni_selecter[5]], strlen(rni_inputName.c_str()));

	/********************************
	* キーボード描画
	********************************/
	// キーボードエリアの背景
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawBox(0, 330, 1280, 600, 0x000000, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// キーボードの要素を表示
	// テキストボックスの幅を入力文字数に追従
	int inputName_Box_Width = 820;
	if (rni_inputName.length() > 12) {
		int len = (rni_inputName.length()) - 12;
		inputName_Box_Width += (9 * len);
	}
	DrawBox(690, 360, inputName_Box_Width, 398, 0xffffff, FALSE);

	DrawStringToHandle(680, 370, ">", 0xffffff, font.handle_0_16, 0xffffff);
	DrawStringToHandle(250, 360, "名前を英数字で入力してください", 0xffffff, font.handle_0_16, 0xffffff);
	DrawStringToHandle(250, 380, "左スティックでカーソル移動、Bボタンで入力", 0xffffff, font.handle_0_16, 0xffffff);
	DrawStringToHandle(250, 400, "Xボタンで一字削除、Yボタンで入力確定", 0xffffff, font.handle_0_16, 0xffffff);

	DrawStringToHandle(700, 370, rni_inputName.c_str(), 0xffffff, font.handle_0_16, 0xffffff);

	SetFontSize(32);
	// アルファベット大文字・小文字の表示
	for (int i = 0; i < 26; i++) {
		//DrawStringToHandle(100 + (i * 42), 440, rni_alphabet[0][i], 0xffffff, font.handle_0_32, 0xffffff);
		DrawFormatString(100 + (i * 42), 440, 0xffffff,"%c", rni_alphabet[0][i]);
		DrawFormatString(100 + (i * 42), 490, 0xffffff, "%c", rni_alphabet[1][i]);
	}
	// 数字キーパッド表示
	for (int i = 0; i < 10; i++) {
		DrawFormatString(435 + (i * 42), 540, 0xffffff, "%c", rni_alphabet[2][i]);
	}

	// セレクター表示
	DrawBox(rni_selecter[0], rni_selecter[1], (rni_selecter[0] + rni_selecter[2]), (rni_selecter[1] + rni_selecter[3]), 0xffffff, FALSE);

	// セレクター処理
	/********************************
	* 入力処理
	********************************/
	// コントローラー入力
	if (rni_selectstate = GetStickY() > 32000 && rni_stickflg == 0) {
		// 左スティック上
		if (rni_selecter[1] != 440) {
			// １段目じゃないなら
			if (rni_selecter[1] == 540) {
				// ３段目から２段目へ移動したら差を足す
				rni_selecter[5] = (rni_selecter[5] + 8);
			}
			rni_selecter[1] -= 50;
			rni_selecter[4] -= 1;
		}
		rni_stickflg = 1;
	}
	else if (rni_selectstate = GetStickY() < -32000 && rni_stickflg == 0) {
		// 左スティック下
		if (rni_selecter[1] != 540) {
			// ３段目じゃないなら
			if (rni_selecter[1] == 490) {
				// ２段目から３段目へ移動したら差を引く
				rni_selecter[5] = (rni_selecter[5] - 8);
				if (rni_selecter[0] >= 846) {
					// ９より右にカーソルがあったら９にする
					rni_selecter[0] = 804;
					rni_selecter[5] = 9;
				}
				else if (rni_selecter[0] <= 384) {
					//	０より左にカーソルがあったら０にする
					rni_selecter[0] = 426;
					rni_selecter[5] = 0;
				}
			}
			rni_selecter[1] += 50;
			rni_selecter[4] += 1;
		}
		rni_stickflg = 1;
	}
	else if (rni_selectstate = GetStickX() > 32000 && rni_stickflg == 0) {
		// 左スティック左
		if (rni_selecter[1] == 440) {
			// １段目のとき
			if (rni_selecter[0] < 1140) {
				// 右端なら破棄、それ以外なら移動
				rni_selecter[0] += 42;
				rni_selecter[5] += 1;
			}
		}
		else if (rni_selecter[1] == 490) {
			// ２段目のとき
			if (rni_selecter[0] < 1140) {
				// 右端なら破棄、それ以外なら移動
				rni_selecter[0] += 42;
				rni_selecter[5] += 1;
			}
		}
		else if (rni_selecter[1] == 540) {
			// ３段目のとき
			if (rni_selecter[0] < 804) {
				// 右端なら破棄、それ以外なら移動
				rni_selecter[0] += 42;
				rni_selecter[5] += 1;
			}
		}
		rni_stickflg = 1;
	}
	else if (rni_selectstate = GetStickX() < -32000 && rni_stickflg == 0) {
		// 左スティック右
		if (rni_selecter[1] == 440) {
			// １段目のとき
			if (rni_selecter[0] > 90) {
				// 左端なら破棄、それ以外なら移動
				rni_selecter[0] -= 42;
				rni_selecter[5] -= 1;
			}
		}
		else if (rni_selecter[1] == 490) {
			// ２段目のとき
			if (rni_selecter[0] > 90) {
				// 左端なら破棄、それ以外なら移動
				rni_selecter[0] -= 42;
				rni_selecter[5] -= 1;
			}
		}
		else if (rni_selecter[1] == 540) {
			// ３段目のとき
			if (rni_selecter[0] > 426) {
				// 左端なら破棄、それ以外なら移動
				rni_selecter[0] -= 42;
				rni_selecter[5] -= 1;
			}
		}
		rni_stickflg = 1;
	};
	// スティックが戻ると操作受付
	if (rni_selectstate = GetStickY() < 1200 && rni_stickflg == 1) {
		if (rni_selectstate = GetStickY() > -1200) {
			rni_stickflg = 0;
		};
	};
	// Bボタンで入力
	if (JudgeReleaseButton(XINPUT_BUTTON_B) == 1) {
		// Char１文字を１バイトとして考えて１０バイトまで
		if (strlen(rni_inputName.c_str()) < 10) {
			rni_inputName += rni_alphabet[rni_selecter[4]][rni_selecter[5]];
		}
		else {
			// 10文字超えてるので警告
		}
	};
	// Xボタンで一文字削除
	if (JudgeReleaseButton(XINPUT_BUTTON_X) == 1) {
		// １文字削除
		if (rni_inputName.length() > 0) {
			rni_inputName.erase(rni_inputName.length() - 1);
		}
	};
	// Yボタンで入力終了
	if (JudgeReleaseButton(XINPUT_BUTTON_Y) == 1) {
		if (rni_inputName.length() > 0) {
			nameInput.inputedName = rni_inputName.c_str();
			game.mode = RANKING;
		}
		else {
			// 何も入力されていないので警告
		}
	};

	// キーボード入力
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		if (rni_selecter[1] == 440) {
			// １段目のとき
			if (rni_selecter[0] > 90) {
				// 左端なら破棄、それ以外なら移動
				rni_selecter[0] -= 42;
				rni_selecter[5] -= 1;
			}
		}
		else if (rni_selecter[1] == 490) {
			// ２段目のとき
			if (rni_selecter[0] > 90) {
				// 左端なら破棄、それ以外なら移動
				rni_selecter[0] -= 42;
				rni_selecter[5] -= 1;
			}
		}
		else if (rni_selecter[1] == 540) {
			// ３段目のとき
			if (rni_selecter[0] > 426) {
				// 左端なら破棄、それ以外なら移動
				rni_selecter[0] -= 42;
				rni_selecter[5] -= 1;
			}
		}
	} else if (CheckHitKey(KEY_INPUT_RIGHT)) {
		if (rni_selecter[1] == 440) {
			// １段目のとき
			if (rni_selecter[0] < 1140) {
				// 右端なら破棄、それ以外なら移動
				rni_selecter[0] += 42;
				rni_selecter[5] += 1;
			}
		}
		else if (rni_selecter[1] == 490) {
			// ２段目のとき
			if (rni_selecter[0] < 1140) {
				// 右端なら破棄、それ以外なら移動
				rni_selecter[0] += 42;
				rni_selecter[5] += 1;
			}
		}
		else if (rni_selecter[1] == 540) {
			// ３段目のとき
			if (rni_selecter[0] < 804) {
				// 右端なら破棄、それ以外なら移動
				rni_selecter[0] += 42;
				rni_selecter[5] += 1;
			}
		}
	} else if (CheckHitKey(KEY_INPUT_UP)) {
		if (rni_selecter[1] != 440) {
			// １段目じゃないなら
			if (rni_selecter[1] == 540) {
				// ３段目から２段目へ移動したら差を足す
				rni_selecter[5] = (rni_selecter[5] + 8);
			}
			rni_selecter[1] -= 50;
			rni_selecter[4] -= 1;
		}
	} else if (CheckHitKey(KEY_INPUT_DOWN)) {
		if (rni_selecter[1] != 540) {
			// ３段目じゃないなら
			if (rni_selecter[1] == 490) {
				// ２段目から３段目へ移動したら差を引く
				rni_selecter[5] = (rni_selecter[5] - 8);
				if (rni_selecter[0] >= 846) {
					// ９より右にカーソルがあったら９にする
					rni_selecter[0] = 804;
					rni_selecter[5] = 9;
				} else if(rni_selecter[0] <= 384) {
					//	０より左にカーソルがあったら０にする
					rni_selecter[0] = 426;
					rni_selecter[5] = 0;
				}
			}
			rni_selecter[1] += 50;
			rni_selecter[4] += 1;
		}
	}
	if (CheckHitKey(KEY_INPUT_RETURN)) {
		// Char１文字を１バイトとして考えて１０バイトまで
		if (strlen(rni_inputName.c_str()) < 10) {
			rni_inputName += rni_alphabet[rni_selecter[4]][rni_selecter[5]];
		}
		else {
			// １０文字超えてるので警告
		}
	}
	if (CheckHitKey(KEY_INPUT_BACK)) {
		if (rni_inputName.length() > 0) {
			rni_inputName.erase(rni_inputName.length() - 1);
		}
	}

	if(CheckHitKey(KEY_INPUT_SPACE)) {
		if (rni_inputName.length() > 0) {
			nameInput.inputedName = rni_inputName.c_str();
			game.mode = RANKING;
		}
		else {
			// 何も入力されていないので警告
		}
	}

	//RgScore = ReturnScore();

	//if (RgScore > 0) {
	//	for (int i = 0; i < 11; i++) {
	//		gRanking[i].name = nameInput.inputedName;
	//	}
	//	gRanking[RANKING_DATA - 1].score = RgScore;	//ランキングデータにスコアを登録
	//	SortRanking();								//ランキング並べ替え
	//	SaveRanking();								//ランキングデータの保存
	//	game.mode = RANKING;						//ゲームモードの変更
	//}

	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		game.mode = TITLE;
	}
};

