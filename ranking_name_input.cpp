// 作：島袋

#include "DxLib.h"

#include "resourceLoad.h"
extern Image image;
extern Font font;

#include "ranking_name_input.h"

#include "main.h"
extern Game game;

#include "PadInput.h"
int rni_selectstateX;
int rni_selectstateY;
int rni_stickflgX = 0;
int rni_stickflgY = 0;

char rni_alphabet[][26] = {
	{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
	{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' },
	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }
};
//char rni_qwerty[] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };

std::string rni_inputName = "";
int rni_selector[] = { 90, 440, 35, 30, 0, 0 };
int rni_state = 0;

#include "Apple.h"
#include "ranking.h"

/********************************
* ランキング入力処理
********************************/
void DrawRankingNameInput() { // 島袋が担当中、入力された名前を返す関数と、SetFontSize使用によるFPS低下問題以外完成
	// 開始フラグ設定
	rni_state = 1;

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
	//DrawFormatString(600, 20, 0x000000, "%d - %d / %d - %d / %d - %d / %c / %d", rni_selector[0], rni_selector[1], rni_selector[2], rni_selector[3], rni_selector[4], rni_selector[5], rni_alphabet[rni_selector[4]][rni_selector[5]], strlen(rni_inputName.c_str()));
	//DrawFormatString(600, 20, 0x000000, "%d - %d", GetStickX(), GetStickY());

	/********************************
	* キーボード描画
	********************************/
	// キーボードエリアの背景
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawBox(0, 330, 1280, 640, 0x000000, TRUE);
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
	DrawStringToHandle(250, 380, "左スティックでカーソル移動、Aボタンで入力", 0xffffff, font.handle_0_16, 0xffffff);
	DrawStringToHandle(250, 400, "Bボタンで一字削除", 0xffffff, font.handle_0_16, 0xffffff);

	DrawStringToHandle(700, 370, rni_inputName.c_str(), 0xffffff, font.handle_0_16, 0xffffff);

	SetFontSize(32);
	// アルファベット大文字・小文字の表示
	for (int i = 0; i < 26; i++) {
		//DrawStringToHandle(100 + (i * 42), 440, rni_alphabet[0][i], 0xffffff, font.handle_0_32, 0xffffff); // 問題
		DrawFormatString(100 + (i * 42), 440, 0xffffff, "%c", rni_alphabet[0][i]);
		DrawFormatString(100 + (i * 42), 490, 0xffffff, "%c", rni_alphabet[1][i]);
	};
	// 数字キーパッド表示
	for (int i = 0; i < 10; i++) {
		DrawFormatString(435 + (i * 42), 540, 0xffffff, "%c", rni_alphabet[2][i]);
	};
	// 入力確定ボタン
	if (rni_inputName.length() > 0) {
		DrawStringToHandle(597, 595, "入力確定", 0xffffff, font.handle_0_16, 0xffffff);
	}
	else {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawStringToHandle(597, 595, "入力確定", 0xffffff, font.handle_0_16, 0xffffff);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	};

	// セレクター表示
	DrawBox(rni_selector[0], rni_selector[1], (rni_selector[0] + rni_selector[2]), (rni_selector[1] + rni_selector[3]), 0xffffff, FALSE);

	/********************************
	* セレクター・入力処理
	********************************/
	if (rni_selectstateY = GetStickY() > 20000 && rni_stickflgY == 0) { // 左スティック上
		if (rni_selector[1] != 440) { // 最上段じゃないなら
			if (rni_selector[1] == 540) { // ３段目から２段目へ
				rni_selector[5] = (rni_selector[5] + 8); // ３段目から２段目へ移動したら差を足す
			}
			else if (rni_selector[1] == 590) { // ４段目から３段目へ
				rni_selector[2] = 35; // カーソル幅を修正
				rni_selector[5] = 4;
			};
			rni_selector[1] -= 50; // 前（上）の段へ
			rni_selector[4] -= 1; // 文字配列指定用アドレスの更新
		};
		rni_stickflgY = 1;
	}
	else if (rni_selectstateY = GetStickY() < -20000 && rni_stickflgY == 0) { // 左スティック下
		if (rni_selector[1] != 590) { // 最下段じゃないなら
			if (rni_selector[1] == 490) { // ２段目から３段目へ
				rni_selector[5] = (rni_selector[5] - 8); // ２段目から３段目へ移動したら差を引く
				if (rni_selector[0] >= 846) {
					// ９より右にカーソルがあったら文字配列指定用アドレスを９に
					rni_selector[0] = 804;
					rni_selector[5] = 9;
				}
				else if (rni_selector[0] <= 384) {
					//	０より左にカーソルがあったら文字配列指定用アドレスを０に
					rni_selector[0] = 426;
					rni_selector[5] = 0;
				};
			}
			else if (rni_selector[1] == 540) { // ３段目から４段目へ
				rni_selector[2] = 75; // カーソル幅をボタンに合わせて更新
				// 「入力確定」ボタンに合わせて
				rni_selector[0] = 594;
				rni_selector[5] = 0;
			};
			rni_selector[1] += 50; // 次（下）の段へ
			rni_selector[4] += 1; // 文字配列指定用アドレスの更新
		};
		rni_stickflgY = 1;
	}
	else if (rni_selectstateX = GetStickX() > 20000 && rni_stickflgX == 0) { // 左スティック左
		if (rni_selector[1] == 440) { // １段目のとき
			if (rni_selector[0] < 1140) {
				// 右端なら破棄、それ以外なら移動
				rni_selector[0] += 42;
				rni_selector[5] += 1;
			};
		}
		else if (rni_selector[1] == 490) { // ２段目のとき
			if (rni_selector[0] < 1140) {
				// 右端なら破棄、それ以外なら移動
				rni_selector[0] += 42;
				rni_selector[5] += 1;
			};
		}
		else if (rni_selector[1] == 540) { // ３段目のとき
			if (rni_selector[0] < 804) {
				// 右端なら破棄、それ以外なら移動
				rni_selector[0] += 42;
				rni_selector[5] += 1;
			};
		};
		rni_stickflgX = 1;
	}
	else if (rni_selectstateX = GetStickX() < -20000 && rni_stickflgX == 0) { // 左スティック右
		if (rni_selector[1] == 440) { // １段目のとき
			if (rni_selector[0] > 90) {
				// 左端なら破棄、それ以外なら移動
				rni_selector[0] -= 42;
				rni_selector[5] -= 1;
			};
		}
		else if (rni_selector[1] == 490) { // ２段目のとき
			if (rni_selector[0] > 90) {
				// 左端なら破棄、それ以外なら移動
				rni_selector[0] -= 42;
				rni_selector[5] -= 1;
			};
		}
		else if (rni_selector[1] == 540) { // ３段目のとき
			if (rni_selector[0] > 426) {
				// 左端なら破棄、それ以外なら移動
				rni_selector[0] -= 42;
				rni_selector[5] -= 1;
			};
		};
		rni_stickflgX = 1;
	};

	// スティックが戻ると操作受付
	if (rni_selectstateY = GetStickY() < 1200 && rni_stickflgY == 1) {
		if (rni_selectstateY = GetStickY() > -1200) {
			rni_stickflgY = 0;
		};
	};
	if (rni_selectstateX = GetStickX() < 1200 && rni_stickflgX == 1) {
		if (rni_selectstateX = GetStickX() > -1200) {
			rni_stickflgX = 0;
		};
	};

	// Aボタンでキーボードカーソル位置ボタンの決定
	if (JudgeReleaseButton(XINPUT_BUTTON_A) == 1) {
		// 入力確定が押されたら
		if (rni_selector[4] == 3) {
			if (rni_inputName.length() > 0) {
				game.mode = RANKING;
			}
			else {
				// 何も入力されていないので警告
			};
		}
		else {
			// Char１文字を１バイトとして考えて１０バイトまで
			if (GetInputedNameLength() < 10) {
				rni_inputName += rni_alphabet[rni_selector[4]][rni_selector[5]];
			}
			else {
				// 10文字超えてるので警告
			};
		};
	};

	// Bボタンで一文字削除
	if (JudgeReleaseButton(XINPUT_BUTTON_B) == 1) {
		// １文字削除
		if (rni_inputName.length() > 0) {
			rni_inputName.erase(rni_inputName.length() - 1);
		};
	};

	/********************************
	* セレクター・入力処理（キーボード）
	********************************/
	if (CheckHitKey(KEY_INPUT_UP)) { // 上
		if (rni_selector[1] != 440) { // 最上段じゃないなら
			if (rni_selector[1] == 540) { // ３段目から２段目へ
				rni_selector[5] = (rni_selector[5] + 8); // ３段目から２段目へ移動したら差を足す
			}
			else if (rni_selector[1] == 590) { // ４段目から３段目へ
				rni_selector[2] = 35; // カーソル幅を修正
				rni_selector[5] = 4;
			};
			rni_selector[1] -= 50; // 前（上）の段へ
			rni_selector[4] -= 1; // 文字配列指定用アドレスの更新
		};
	}
	else if (CheckHitKey(KEY_INPUT_DOWN)) { // 下
		if (rni_selector[1] != 590) { // 最下段じゃないなら
			if (rni_selector[1] == 490) { // ２段目から３段目へ
				rni_selector[5] = (rni_selector[5] - 8); // ２段目から３段目へ移動したら差を引く
				if (rni_selector[0] >= 846) {
					// ９より右にカーソルがあったら文字配列指定用アドレスを９に
					rni_selector[0] = 804;
					rni_selector[5] = 9;
				}
				else if (rni_selector[0] <= 384) {
					//	０より左にカーソルがあったら文字配列指定用アドレスを０に
					rni_selector[0] = 426;
					rni_selector[5] = 0;
				};
			}
			else if (rni_selector[1] == 540) { // ３段目から４段目へ
				rni_selector[2] = 75; // カーソル幅をボタンに合わせて更新
				// 「入力確定」ボタンに合わせて
				rni_selector[0] = 594;
				rni_selector[5] = 0;
			};
			rni_selector[1] += 50; // 次（下）の段へ
			rni_selector[4] += 1; // 文字配列指定用アドレスの更新
		};
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT)) { // 左
		if (rni_selector[1] == 440) { // １段目のとき
			if (rni_selector[0] < 1140) {
				// 右端なら破棄、それ以外なら移動
				rni_selector[0] += 42;
				rni_selector[5] += 1;
			};
		}
		else if (rni_selector[1] == 490) { // ２段目のとき
			if (rni_selector[0] < 1140) {
				// 右端なら破棄、それ以外なら移動
				rni_selector[0] += 42;
				rni_selector[5] += 1;
			};
		}
		else if (rni_selector[1] == 540) { // ３段目のとき
			if (rni_selector[0] < 804) {
				// 右端なら破棄、それ以外なら移動
				rni_selector[0] += 42;
				rni_selector[5] += 1;
			};
		};
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) { // 右
		if (rni_selector[1] == 440) { // １段目のとき
			if (rni_selector[0] > 90) {
				// 左端なら破棄、それ以外なら移動
				rni_selector[0] -= 42;
				rni_selector[5] -= 1;
			};
		}
		else if (rni_selector[1] == 490) { // ２段目のとき
			if (rni_selector[0] > 90) {
				// 左端なら破棄、それ以外なら移動
				rni_selector[0] -= 42;
				rni_selector[5] -= 1;
			};
		}
		else if (rni_selector[1] == 540) { // ３段目のとき
			if (rni_selector[0] > 426) {
				// 左端なら破棄、それ以外なら移動
				rni_selector[0] -= 42;
				rni_selector[5] -= 1;
			};
		};
	};

	// エンターキーでキーボードカーソル位置ボタンの決定
	if (CheckHitKey(KEY_INPUT_RETURN)) {
		// 入力確定が押されたら
		if (rni_selector[4] == 3) {
			if (rni_inputName.length() > 0) {
				game.mode = RANKING;
			}
			else {
				// 何も入力されていないので警告
			};
		}
		else {
			// Char１文字を１バイトとして考えて１０バイトまで
			if (GetInputedNameLength() < 10) {
				rni_inputName += rni_alphabet[rni_selector[4]][rni_selector[5]];
			}
			else {
				// 10文字超えてるので警告
			};
		};
	};

	// バックキーで一文字削除
	if (CheckHitKey(KEY_INPUT_BACK)) {
		// １文字削除
		if (rni_inputName.length() > 0) {
			rni_inputName.erase(rni_inputName.length() - 1);
		};
	};

	// ESCキーで強制終了
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		game.mode = TITLE;
	};
};

/********************************
* リセット
********************************/
void ResetRankingNameInput() {
	// 名前入力値のリセット
	rni_inputName = "";
	// カーソル位置のリセット
	rni_selector[0] = 90;
	rni_selector[1] = 440;
	rni_selector[2] = 35;
	rni_selector[3] = 30;
	rni_selector[4] = 0;
	rni_selector[5] = 0;
	// 開始フラグのリセット
	rni_state = 0;
};

/********************************
* 入力された名前の指定した文字を返す
********************************/
char GetInputedName(int i) {
	if (GetInputedNameLength() > 0) {
		char name[10];
		for (int i = 0; i < GetInputedNameLength() - 1; i++) {
			name[i] = rni_inputName[i];
		};
		return rni_inputName.c_str()[i];
	}
	else {
		return -1;
	};
};

/********************************
* 入力された名前の桁数を返す
********************************/
int GetInputedNameLength() {
	return strlen(rni_inputName.c_str());
};

/********************************
* 名前入力されたか
********************************/
int GetRankingNameInputState() {
	return rni_state;
};