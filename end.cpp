#include "DxLib.h"
#include "resourceLoad.h"

#include "main.h"

extern Image image;
extern Font font;

extern Game game;

int FPSCount = 0;

/********************************
* エンド画面
********************************/
void DrawEnd() { // 未完成
	if (FPSCount++ < 300) {

		// 背景表示
		DrawGraph(0, 0, image.title, TRUE);

		// Thank you for playing
		DrawStringToHandle(10, 10, "Thank you for playing", 0x000000, font.handle_1_128, 0xffffff);

		//製作者
		DrawStringToHandle(10, 150, "製作者", 0x000000, font.handle_1_64, 0xffffff);
		DrawStringToHandle(10, 230, "新里滉規　北村隼士 島袋 叶望　玉城流叶　豊元一成",0x000000, font.handle_1_32, 0xffffff);

		// 謝辞
		//SetFontSize(40); FPS低下問題発生中
		//DrawFormatString(20, 200, 0x000000, "使用した素材のクレジット");
		//SetFontSize(32);
		DrawStringToHandle(10, 270, "使用した素材", 0x000000, font.handle_1_64, 0xffffff);
		DrawStringToHandle(10, 350, "プレイヤー画像：AAA様", 0x000000, font.handle_1_32, 0xffffff);
		DrawStringToHandle(10, 390, "リンゴ画像：AAA様", 0x000000, font.handle_1_32, 0xffffff);
		DrawStringToHandle(10, 430, "フォント：AAA様", 0x000000, font.handle_1_32, 0xffffff);

		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			game.mode = EXIT;
		};

		if (FPSCount == 300) {
			game.mode = EXIT;
		}
	}
};