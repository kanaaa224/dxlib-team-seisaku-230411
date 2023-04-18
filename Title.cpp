// 作：島袋、玉城

#include "DxLib.h"
#include <stdlib.h>
#include "title.h"
#include "resourceLoad.h"
#include "PadInput.h"
#include "main.h"

extern Image image;
extern Font font;

extern Game game;

Title title;

/********************************
* タイトル
********************************/
void DrawTitle() {
	// 背景表示
	DrawGraph(0, 0, image.title, TRUE);

	// タイトル表示
	DrawStringToHandle(350, 150, "りんごおとし", 0x000000, font.handle_1_128, 0xffffff);

	// ゲームモードセレクトの項目
	DrawStringToHandle(630, 350, "1.スタート", 0x000000, font.handle_1_32, 0xffffff);
	DrawStringToHandle(630, 400, "2.ヘルプ", 0x000000, font.handle_1_32, 0xffffff);
	DrawStringToHandle(630, 450, "3.ランキング", 0x000000, font.handle_1_32, 0xffffff);
	DrawStringToHandle(630, 500, "4.終わる", 0x000000, font.handle_1_32, 0xffffff);

	DrawStringToHandle(300, 600, "スティック操作対応に修正予定・スペースで決定", 0x000000, font.handle_1_32, 0xffffff);
	DrawStringToHandle(500, 640, "Tキーでりそーすテスト", 0x000000, font.handle_1_32, 0xffffff);

	// ゲームモードセレクトのカーソル処理
	if (title.state == 0) {
		DrawStringToHandle(570, 350, "→", 0x000000, font.handle_1_32, 0xffffff);
	}
	else if (title.state == 1) {
		DrawStringToHandle(570, 400, "→", 0x000000, font.handle_1_32, 0xffffff);
	}
	else if (title.state == 2) {
		DrawStringToHandle(570, 450, "→", 0x000000, font.handle_1_32, 0xffffff);
	}
	else if (title.state == 3) {
		DrawStringToHandle(570, 500, "→", 0x000000, font.handle_1_32, 0xffffff);
	};


	//if (CheckHitKey(KEY_INPUT_DOWN)) {
	//	if (title.state >= 3) {
	//		title.state = 0;
	//	}
	//	else {
	//		title.state += 1;
	//	};
	//};

	if (CheckHitKey(KEY_INPUT_1)) {
		title.state = 0;
	} else if (CheckHitKey(KEY_INPUT_2)) {
		title.state = 1;
	} else if (CheckHitKey(KEY_INPUT_3)) {
		title.state = 2;
	} else if (CheckHitKey(KEY_INPUT_4)) {
		title.state = 3;
	};

	if (CheckHitKey(KEY_INPUT_SPACE)) {
		if (title.state == 0) {
			// スタート選択
			game.mode = INIT;
		}
		else if (title.state == 1) {
			// ヘルプ選択
			game.mode = HELP;
		}
		else if (title.state == 2) {
			// ランキング選択
			game.mode = RANKING;
		}
		else if (title.state == 3) {
			// 終わる選択
			game.mode = END;
		};
	};

	if (CheckHitKey(KEY_INPUT_T)) {
		game.mode = TEST;
	};






	//if ((selector_current_value = GetStickY()) <= -32000) { //CheckHitKey(KEY_INPUT_M) != 0
	//	

	//	if (selector_current_value >= 1) {
	//		if (title.state >= 3) {
	//			title.state = 0;
	//		}
	//		else {
	//			title.state += 1;
	//		};
	//	};
	//};

	//if ((title.selector_current_value = GetStickY()) <= -32000) { //CheckHitKey(KEY_INPUT_M) != 0
	//	title.selector_current_value = abs(title.selector_current_value);

	//	if (title.selector_current_value - title.selector_prev_value > 1) {
	//		

	//		if (title.state >= 3) {
	//			title.state = 0;
	//		}
	//		else {
	//			title.state += 1;
	//		};
	//	};
	//	title.selector_prev_value = abs(GetStickY());
	//};

	// ゲームモードセレクト処理

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
