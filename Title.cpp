// 作：島袋、玉城

#include "DxLib.h"
#include "resourceLoad.h"

#include "main.h"
#include "PadInput.h"

extern Image image;
extern Font font;

extern Game game;
extern Sound sound;

int title_state = 0;

int title_selectstate;
int title_stickflg = 0;

/********************************
* タイトル
********************************/
void DrawTitle() {
	// 背景表示
	DrawGraph(0, 0, image.title, TRUE);

	// タイトル表示
	DrawStringToHandle(350, 150, "りんごおとし", 0x000000, font.handle_1_128, 0xffffff);

	// ゲームモードセレクトの項目
	DrawStringToHandle(630, 350, "スタート", 0x000000, font.handle_1_32, 0xffffff);
	DrawStringToHandle(630, 400, "ヘルプ", 0x000000, font.handle_1_32, 0xffffff);
	DrawStringToHandle(630, 450, "ランキング", 0x000000, font.handle_1_32, 0xffffff);
	DrawStringToHandle(630, 500, "終わる", 0x000000, font.handle_1_32, 0xffffff);

	DrawStringToHandle(380, 670, "左スティックで選たく、Bボタンで決定", 0x000000, font.handle_1_32, 0xffffff);
	//DrawStringToHandle(500, 640, "Tキーでりそーすテスト", 0x000000, font.handle_1_32, 0xffffff);

	// ゲームモードセレクトのカーソル処理
	if (title_state == 0) {
		DrawStringToHandle(570, 350, "→", 0x000000, font.handle_1_32, 0xffffff);
	}
	else if (title_state == 1) {
		DrawStringToHandle(570, 400, "→", 0x000000, font.handle_1_32, 0xffffff);
	}
	else if (title_state == 2) {
		DrawStringToHandle(570, 450, "→", 0x000000, font.handle_1_32, 0xffffff);
	}
	else if (title_state == 3) {
		DrawStringToHandle(570, 500, "→", 0x000000, font.handle_1_32, 0xffffff);
	};

	/********************************
	* ゲームモードセレクト処理
	********************************/
	// コントローラー入力
	if (title_selectstate = GetStickY() > 32000 && title_stickflg == 0) {
		if (CheckSoundMem(sound.se_corsor) == 0) {
			PlaySoundMem(sound.se_corsor, DX_PLAYTYPE_BACK, TRUE);
		}
		if (title_state <= 0) {
			title_state = 3;
		}
		else {
			title_state -= 1;
		};
		title_stickflg = 1;
	}
	else if (title_selectstate = GetStickY() < -32000 && title_stickflg == 0) {
		if (CheckSoundMem(sound.se_corsor) == 0) {
			PlaySoundMem(sound.se_corsor, DX_PLAYTYPE_BACK, TRUE);
		}
		if (title_state >= 3) {
			title_state = 0;
		}
		else {
			title_state += 1;
		};
		title_stickflg = 1;
	};
	// スティックが戻ると操作受付
	if (title_selectstate = GetStickY() < 1200 && title_stickflg == 1) {
		if (title_selectstate = GetStickY() > -1200) {
			title_stickflg = 0;
		};
	};
	// Bボタンで選択
	if (JudgeButton(XINPUT_BUTTON_B) == 1) {
		if (CheckSoundMem(sound.se_selct) == 0) {
			PlaySoundMem(sound.se_selct, DX_PLAYTYPE_BACK, TRUE);
		}
		if (title_state == 0) {
			// スタート選択
			game.mode = INIT;
		}
		else if (title_state == 1) {
			// ヘルプ選択
			game.mode = HELP;
		}
		else if (title_state == 2) {
			// ランキング選択
			game.mode = RANKING;
		}
		else if (title_state == 3) {
			// 終わる選択
			game.mode = END;
		};
	};

	// キーボード入力対応
	if (CheckHitKey(KEY_INPUT_1)) {
		title_state = 0;
	} else if (CheckHitKey(KEY_INPUT_2)) {
		title_state = 1;
	} else if (CheckHitKey(KEY_INPUT_3)) {
		title_state = 2;
	} else if (CheckHitKey(KEY_INPUT_4)) {
		title_state = 3;
	};
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		if (title_state == 0) {
			// スタート選択
			game.mode = INIT;
		}
		else if (title_state == 1) {
			// ヘルプ選択
			game.mode = HELP;
		}
		else if (title_state == 2) {
			// ランキング選択
			game.mode = RANKING;
		}
		else if (title_state == 3) {
			// 終わる選択
			game.mode = END;
		};
	};
	if (CheckHitKey(KEY_INPUT_T)) {
		game.mode = TEST;
	};


	// BGM SE ここに書くか、bgm.cppで画面別に制御させる？
	
};



















// ごめん、、

//int Image;				//背景画像

//int SoundTitle;			//タイトルの音楽
//int SoundMoveCorsor;	//カーソル移動の効果音
//int	SoundDecision;		//決定の効果音

//int LoadImages(void)
//{
//	if ((Image = LoadGraph("images/TitleImage.png")) == -1)return -1;
//}
//int FontHandle;

//int LoadImages(void)
//{
//	LPCSTR font_path = "Resources/font/しょかきうたげ（無料版）.ttf"; // 読み込むフォントファイルのパス
//
//	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
//	}
//	else {
//		// フォント読込エラー処理
//		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
//	}
//
//	//if ((Image = LoadGraph("images/TitleImage.png")) == -1)return -1;
//}

//int LoadSounds(void)
//{
//
//}

//void DrawTitle(void)
//{
//
//	//FontHandle= CreateFontToHandle("しょかきうたげ（無料版）", 128,9 , DX_FONTTYPE_EDGE);
//
//	//DrawGraph(0, 0, Image, TRUE);
//
//	///*ChangeFont("しょかきうたげ（無料版）");
//	//ChangeFontType(DX_FONTTYPE_EDGE);
//	//SetFontSize(128);
//	//DrawString(340, 140, "りんごおとし", 0x000000, 0xffffff);*/
//
//	//DrawStringToHandle(340, 140, "りんごおとし", 0x000000, FontHandle, 0xffffff);
//	//	
//
//	//DrawGraph(0, 0, image.title, FALSE);
//}
