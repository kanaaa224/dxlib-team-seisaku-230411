/********************************
* ランキング入力処理
* 作者：島袋
********************************/
#include "DxLib.h"
#include "resourceLoad.h"
#include "ranking_name_input.h"
#include "main.h"
#include "Apple.h"
#include "ranking.h"
#include "PadInput.h"


/********************************
* ランキング入力変数初期化
********************************/
int RankingNameInput::state = 0;
int RankingNameInput::selector[] = { 90, 440, 35, 30, 0, 0 };
std::string RankingNameInput::inputName = "";
char RankingNameInput::alphabet[][26] = {
   { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
   { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' },
   { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }
};
//const char rni_qwerty[] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };
int RankingNameInput::ctrl_state[] = {0, 0, 0, 0};


/********************************
* ランキング入力関数
********************************/
void RankingNameInput::Draw() {
	// 開始フラグ設定
	state = 1;

    // 背景表示
    DrawGraph(0, 0, Image::GetImages(IMG_TITLE, 0), TRUE);

	// タイトル
	DrawStringToHandle(270, 50, "ランキングに登録", 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);

	// 本文
	std::string str = "スコア：" + std::to_string(AppleCount::ReturnScore());
	DrawStringToHandle(750, 70, str.c_str(), 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

	DrawStringToHandle(140, 150, "あなたのスコアが上位５位内に入りました！おめでとうございます。", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

	DrawStringToHandle(110, 200, "ということで、ランキングに追加します。あなたの名前をどうぞ（強制）", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

	/********************************
	* キーボード描画
	********************************/
	// キーボードエリアの背景
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawBox(0, 330, 1280, 640, 0x000000, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// キーボードの要素を表示
	// テキストボックスの幅を入力文字数に追従
	int inputName_Box_Width = 900;
	if (inputName.length() > 12) {
		int len = (inputName.length()) - 12;
		inputName_Box_Width += (9 * len);
	};
	DrawBox(770, 360, inputName_Box_Width, 398, 0xffffff, FALSE);

	DrawStringToHandle(760, 370, ">", 0xffffff, Font::GetFonts(FONT_0_16), 0xffffff);
	DrawStringToHandle(350, 360, "名前を英数字で入力してください", 0xffffff, Font::GetFonts(FONT_0_16), 0xffffff);
	DrawStringToHandle(350, 380, "十字キー・左スティックでカーソル移動、", 0xffffff, Font::GetFonts(FONT_0_16), 0xffffff);
	DrawStringToHandle(350, 400, "Aボタンで入力、Bボタンで一字削除", 0xffffff, Font::GetFonts(FONT_0_16), 0xffffff);

	DrawStringToHandle(780, 370, inputName.c_str(), 0xffffff, Font::GetFonts(FONT_0_16), 0xffffff);

	// アルファベット大文字・小文字の表示
	for (int i = 0; i < 26; i++) {
		str = alphabet[0][i];
		DrawStringToHandle(100 + (i * 42), 440, str.c_str(), 0xffffff, Font::GetFonts(FONT_0_32), 0xffffff);
		str = alphabet[1][i];
		DrawStringToHandle(100 + (i * 42), 490, str.c_str(), 0xffffff, Font::GetFonts(FONT_0_32), 0xffffff);
	};
	// 数字キーパッド表示
	for (int i = 0; i < 10; i++) {
		str = alphabet[2][i];
		DrawStringToHandle(435 + (i * 42), 540, str.c_str(), 0xffffff, Font::GetFonts(FONT_0_32), 0xffffff);
	};
	// 入力確定ボタン
	if (inputName.length() > 0) {
		DrawStringToHandle(597, 595, "入力確定", 0xffffff, Font::GetFonts(FONT_0_16), 0xffffff);
	}
	else {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawStringToHandle(597, 595, "入力確定", 0xffffff, Font::GetFonts(FONT_0_16), 0xffffff);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	};

	// セレクター表示
	DrawBox(selector[0], selector[1], (selector[0] + selector[2]), (selector[1] + selector[3]), 0xffffff, FALSE);

	/********************************
	* セレクター・入力処理
	********************************/
	if ((PAD_INPUT::JudgeButton(XINPUT_BUTTON_DPAD_UP) == 1) || (ctrl_state[1] = PAD_INPUT::GetStickY() > 20000 && ctrl_state[3] == 0)) { // 左スティック上
		if (selector[1] != 440) { // 最上段じゃないなら
			if (selector[1] == 540) { // ３段目から２段目へ
				selector[5] = (selector[5] + 8); // ３段目から２段目へ移動したら差を足す
			}
			else if (selector[1] == 590) { // ４段目から３段目へ
				selector[2] = 35; // カーソル幅を修正
				selector[5] = 4;
			};
			selector[1] -= 50; // 前（上）の段へ
			selector[4] -= 1; // 文字配列指定用アドレスの更新
		};
		ctrl_state[3] = 1;
	}
	else if ((PAD_INPUT::JudgeButton(XINPUT_BUTTON_DPAD_DOWN) == 1) || (ctrl_state[1] = PAD_INPUT::GetStickY() < -20000 && ctrl_state[3] == 0)) { // 左スティック下
		if (selector[1] != 590) { // 最下段じゃないなら
			if (selector[1] == 490) { // ２段目から３段目へ
				selector[5] = (selector[5] - 8); // ２段目から３段目へ移動したら差を引く
				if (selector[0] >= 846) {
					// ９より右にカーソルがあったら文字配列指定用アドレスを９に
					selector[0] = 804;
					selector[5] = 9;
				}
				else if (selector[0] <= 384) {
					//	０より左にカーソルがあったら文字配列指定用アドレスを０に
					selector[0] = 426;
					selector[5] = 0;
				};
			}
			else if (selector[1] == 540) { // ３段目から４段目へ
				selector[2] = 75; // カーソル幅をボタンに合わせて更新
				// 「入力確定」ボタンに合わせて
				selector[0] = 594;
				selector[5] = 0;
			};
			selector[1] += 50; // 次（下）の段へ
			selector[4] += 1; // 文字配列指定用アドレスの更新
		};
		ctrl_state[3] = 1;
	}
	else if ((PAD_INPUT::JudgeButton(XINPUT_BUTTON_DPAD_RIGHT) == 1) || (ctrl_state[0] = PAD_INPUT::GetStickX() > 20000 && ctrl_state[2] == 0)) { // 左スティック右
		if (selector[1] == 440) { // １段目のとき
			if (selector[0] < 1140) { // 右端ならマリオUSA、それ以外なら移動
				selector[0] += 42;
				selector[5] += 1;
			}
			else {
				selector[0] -= 42 * 25;
				selector[5] = 0;
			};
		}
		else if (selector[1] == 490) { // ２段目のとき
			if (selector[0] < 1140) { // 右端ならマリオUSA、それ以外なら移動
				selector[0] += 42;
				selector[5] += 1;
			}
			else {
				selector[0] -= 42 * 25;
				selector[5] = 0;
			};
		}
		else if (selector[1] == 540) { // ３段目のとき
			if (selector[0] < 804) { // 右端ならマリオUSA、それ以外なら移動
				selector[0] += 42;
				selector[5] += 1;
			}
			else {
				selector[0] -= 42 * 9;
				selector[5] = 0;
			};
		};
		ctrl_state[2] = 1;
	}
	else if ((PAD_INPUT::JudgeButton(XINPUT_BUTTON_DPAD_LEFT) == 1) || (ctrl_state[0] = PAD_INPUT::GetStickX() < -20000 && ctrl_state[2] == 0)) { // 左スティック左
		if (selector[1] == 440) { // １段目のとき
			if (selector[0] > 90) { // 左端ならマリオUSA、それ以外なら移動
				selector[0] -= 42;
				selector[5] -= 1;
			}
			else {
				selector[0] += 42 * 25;
				selector[5] = 25;
			};
		}
		else if (selector[1] == 490) { // ２段目のとき
			if (selector[0] > 90) { // 左端ならマリオUSA、それ以外なら移動
				selector[0] -= 42;
				selector[5] -= 1;
			}
			else {
				selector[0] += 42 * 25;
				selector[5] = 25;
			};
		}
		else if (selector[1] == 540) { // ３段目のとき
			if (selector[0] > 426) { // 左端ならマリオUSA、それ以外なら移動
				selector[0] -= 42;
				selector[5] -= 1;
			}
			else {
				selector[0] += 42 * 9;
				selector[5] = 9;
			};
		};
		ctrl_state[2] = 1;
	};

	// スティックが戻ると操作受付
	if (ctrl_state[1] = PAD_INPUT::GetStickY() < 1200 && ctrl_state[3] == 1) {
		if (ctrl_state[1] = PAD_INPUT::GetStickY() > -1200) {
			ctrl_state[3] = 0;
		};
	};
	if (ctrl_state[0] = PAD_INPUT::GetStickX() < 1200 && ctrl_state[2] == 1) {
		if (ctrl_state[0] = PAD_INPUT::GetStickX() > -1200) {
			ctrl_state[2] = 0;
		};
	};

	// 十字キーが戻ると操作受付
	if ((PAD_INPUT::JudgeReleaseButton(XINPUT_BUTTON_DPAD_UP) == 1) || (PAD_INPUT::JudgeReleaseButton(XINPUT_BUTTON_DPAD_DOWN) == 1) || (PAD_INPUT::JudgeReleaseButton(XINPUT_BUTTON_DPAD_LEFT) == 1) || (PAD_INPUT::JudgeReleaseButton(XINPUT_BUTTON_DPAD_RIGHT) == 1)) {
		ctrl_state[3] = 0;
		ctrl_state[2] = 0;
	};

	// Aボタンでキーボードカーソル位置ボタンの決定
	if (PAD_INPUT::JudgeReleaseButton(XINPUT_BUTTON_A) == 1) {
		// 入力確定が押されたら
		if (selector[4] == 3) {
			if (inputName.length() > 0) {
                Game::ModeSet(RANKING);
			}
			else {
				// 何も入力されていないので警告
			};
		}
		else {
			// Char１文字を１バイトとして考えて１０バイトまで
			if (GetNameLength() < 10) {
				inputName += alphabet[selector[4]][selector[5]];
			}
			else {
				// 10文字超えてるので警告
			};
		};
	};

	// Bボタンで一文字削除
	if (PAD_INPUT::JudgeReleaseButton(XINPUT_BUTTON_B) == 1) {
		// １文字削除
		if (inputName.length() > 0) {
			inputName.erase(inputName.length() - 1);
		};
	};

	/********************************
	* セレクター・入力処理（キーボード）
	********************************/
	if (CheckHitKey(KEY_INPUT_UP)) { // 上
		if (selector[1] != 440) { // 最上段じゃないなら
			if (selector[1] == 540) { // ３段目から２段目へ
				selector[5] = (selector[5] + 8); // ３段目から２段目へ移動したら差を足す
			}
			else if (selector[1] == 590) { // ４段目から３段目へ
				selector[2] = 35; // カーソル幅を修正
				selector[5] = 4;
			};
			selector[1] -= 50; // 前（上）の段へ
			selector[4] -= 1; // 文字配列指定用アドレスの更新
		};
	}
	else if (CheckHitKey(KEY_INPUT_DOWN)) { // 下
		if (selector[1] != 590) { // 最下段じゃないなら
			if (selector[1] == 490) { // ２段目から３段目へ
				selector[5] = (selector[5] - 8); // ２段目から３段目へ移動したら差を引く
				if (selector[0] >= 846) {
					// ９より右にカーソルがあったら文字配列指定用アドレスを９に
					selector[0] = 804;
					selector[5] = 9;
				}
				else if (selector[0] <= 384) {
					//	０より左にカーソルがあったら文字配列指定用アドレスを０に
					selector[0] = 426;
					selector[5] = 0;
				};
			}
			else if (selector[1] == 540) { // ３段目から４段目へ
				selector[2] = 75; // カーソル幅をボタンに合わせて更新
				// 「入力確定」ボタンに合わせて
				selector[0] = 594;
				selector[5] = 0;
			};
			selector[1] += 50; // 次（下）の段へ
			selector[4] += 1; // 文字配列指定用アドレスの更新
		};
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT)) { // 右
		if (selector[1] == 440) { // １段目のとき
			if (selector[0] < 1140) { // 右端ならマリオUSA、それ以外なら移動
				selector[0] += 42;
				selector[5] += 1;
			}
			else {
				selector[0] -= 42 * 25;
				selector[5] = 0;
			};
		}
		else if (selector[1] == 490) { // ２段目のとき
			if (selector[0] < 1140) { // 右端ならマリオUSA、それ以外なら移動
				selector[0] += 42;
				selector[5] += 1;
			}
			else {
				selector[0] -= 42 * 25;
				selector[5] = 0;
			};
		}
		else if (selector[1] == 540) { // ３段目のとき
			if (selector[0] < 804) { // 右端ならマリオUSA、それ以外なら移動
				selector[0] += 42;
				selector[5] += 1;
			}
			else {
				selector[0] -= 42 * 9;
				selector[5] = 0;
			};
		};
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) { // 左
		if (selector[1] == 440) { // １段目のとき
			if (selector[0] > 90) { // 左端ならマリオUSA、それ以外なら移動
				selector[0] -= 42;
				selector[5] -= 1;
			}
			else {
				selector[0] += 42 * 25;
				selector[5] = 25;
			};
		}
		else if (selector[1] == 490) { // ２段目のとき
			if (selector[0] > 90) { // 左端ならマリオUSA、それ以外なら移動
				selector[0] -= 42;
				selector[5] -= 1;
			}
			else {
				selector[0] += 42 * 25;
				selector[5] = 25;
			};
		}
		else if (selector[1] == 540) { // ３段目のとき
			if (selector[0] > 426) { // 左端ならマリオUSA、それ以外なら移動
				selector[0] -= 42;
				selector[5] -= 1;
			}
			else {
				selector[0] += 42 * 9;
				selector[5] = 9;
			};
		};
	};

	// エンターキーでキーボードカーソル位置ボタンの決定
	if (CheckHitKey(KEY_INPUT_RETURN)) {
		// 入力確定が押されたら
		if (selector[4] == 3) {
			if (inputName.length() > 0) {
                Game::ModeSet(RANKING);
			}
			else {
				// 何も入力されていないので警告
			};
		}
		else {
			// Char１文字を１バイトとして考えて１０バイトまで
			if (GetNameLength() < 10) {
				inputName += alphabet[selector[4]][selector[5]];
			}
			else {
				// 10文字超えてるので警告
			};
		};
	};

	// バックキーで一文字削除
	if (CheckHitKey(KEY_INPUT_BACK)) {
		// １文字削除
		if (inputName.length() > 0) {
			inputName.erase(inputName.length() - 1);
		};
	};

	// ESCキーで強制終了
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
        Game::ModeSet(TITLE);
	};
};

/********************************
* リセット
********************************/
void RankingNameInput::Reset() {
	// 名前入力値のリセット
	inputName = "";
	// カーソル位置のリセット
	selector[0] = 90;
	selector[1] = 440;
	selector[2] = 35;
	selector[3] = 30;
	selector[4] = 0;
	selector[5] = 0;
	// 開始フラグのリセット
	state = 0;
};

/********************************
* 入力された名前の指定した文字を返す
********************************/
char RankingNameInput::GetName(int i) {
	if (GetNameLength() > 0) {
		char name[10];
		for (int i = 0; i < GetNameLength() - 1; i++) {
			name[i] = inputName[i];
		};
		return inputName.c_str()[i];
	}
	else {
		return -1;
	};
};

/********************************
* 入力された名前の桁数を返す
********************************/
int RankingNameInput::GetNameLength() {
	return strlen(inputName.c_str());
};

/********************************
* 名前入力されたか
********************************/
int RankingNameInput::GetState() {
	return state;
};