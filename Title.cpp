/********************************
* タイトル画面
* 作者：玉城、島袋
********************************/
#include "DxLib.h"
#include "title.h"
#include "resourceLoad.h"
#include "main.h"
#include "PadInput.h"


int title_selectstate;
int title_stickflg = 0;


/********************************
* タイトル変数初期化
********************************/
int Title::state = 0;


/********************************
* タイトル画面描画
********************************/
void Title::Draw() {
	// 背景表示
	DrawGraph(0, 0, Image::GetImages(IMG_TITLE, 0), TRUE);

	// タイトル表示
	DrawStringToHandle(330, 150, "りんごおとし", 0x000000, Font::GetFonts(FONT_1_128), 0xffffff);

	// バージョン表示（仮）
	DrawStringToHandle(20, 690, "v1.2.3", 0x000000, Font::GetFonts(FONT_0_16), 0xffffff);

	// ゲームモードセレクトの項目
	DrawStringToHandle(630, 350, "スタート", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	DrawStringToHandle(630, 400, "ヘルプ", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	DrawStringToHandle(630, 450, "ランキング", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	DrawStringToHandle(630, 500, "終わる", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

	DrawStringToHandle(380, 670, "左スティックで選たく、Bボタンで決定", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	
	// ゲームモードセレクトのカーソル処理
	if (state == 0) {
		DrawStringToHandle(570, 350, "→", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	}
	else if (state == 1) {
		DrawStringToHandle(570, 400, "→", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	}
	else if (state == 2) {
		DrawStringToHandle(570, 450, "→", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	}
	else if (state == 3) {
		DrawStringToHandle(570, 500, "→", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	};

	/********************************
	* ゲームモードセレクト処理
	********************************/
	// コントローラー入力
	if (title_selectstate = PAD_INPUT::GetStickY() > 32000 && title_stickflg == 0) {
		PlaySoundMem(Sound::GetSounds(SND_SE_CURSOR), DX_PLAYTYPE_BACK, TRUE);
		if (state <= 0) {
			state = 3;
		}
		else {
			state -= 1;
		};
		title_stickflg = 1;
	}
	else if (title_selectstate = PAD_INPUT::GetStickY() < -32000 && title_stickflg == 0) {
		PlaySoundMem(Sound::GetSounds(SND_SE_CURSOR), DX_PLAYTYPE_BACK, TRUE);
		if (state >= 3) {
			state = 0;
		}
		else {
			state += 1;
		};
		title_stickflg = 1;
	};
	// スティックが戻ると操作受付
	if (title_selectstate = PAD_INPUT::GetStickY() < 32000 && title_stickflg == 1) {
		if (title_selectstate = PAD_INPUT::GetStickY() > -32000) {
			title_stickflg = 0;
		};
	};
	// Bボタンで選択
	if (PAD_INPUT::JudgeButton(XINPUT_BUTTON_B) == 1) {
		if (CheckSoundMem(Sound::GetSounds(SND_SE_SELECT)) == 0) {
			PlaySoundMem(Sound::GetSounds(SND_SE_SELECT), DX_PLAYTYPE_BACK, TRUE);
		};
		if (state == 0) {
			// スタート選択
            Game::ModeSet(INIT);
		}
		else if (state == 1) {
			// ヘルプ選択
            Game::ModeSet(HELP);
		}
		else if (state == 2) {
			// ランキング選択
            Game::ModeSet(RANKING);
		}
		else if (state == 3) {
			// 終わる選択
            Game::ModeSet(END);
		};
	};

	// キーボード入力対応
	if (CheckHitKey(KEY_INPUT_1)) {
		state = 0;
	} else if (CheckHitKey(KEY_INPUT_2)) {
		state = 1;
	} else if (CheckHitKey(KEY_INPUT_3)) {
		state = 2;
	} else if (CheckHitKey(KEY_INPUT_4)) {
		state = 3;
	};
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		if (CheckSoundMem(Sound::GetSounds(SND_SE_SELECT)) == 0) {
			PlaySoundMem(Sound::GetSounds(SND_SE_SELECT), DX_PLAYTYPE_BACK, TRUE);
		};
		if (state == 0) {
			// スタート選択
            Game::ModeSet(INIT);
		}
		else if (state == 1) {
			// ヘルプ選択
            Game::ModeSet(HELP);
		}
		else if (state == 2) {
			// ランキング選択
            Game::ModeSet(RANKING);
		}
		else if (state == 3) {
			// 終わる選択
            Game::ModeSet(END);
		};
	};
	if (CheckHitKey(KEY_INPUT_T)) {
		if (CheckSoundMem(Sound::GetSounds(SND_SE_SELECT)) == 0) {
			PlaySoundMem(Sound::GetSounds(SND_SE_SELECT), DX_PLAYTYPE_BACK, TRUE);
		};
        Game::ModeSet(TEST);
	};
};