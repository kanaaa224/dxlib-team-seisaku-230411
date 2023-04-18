#include "DxLib.h"
#include "resourceLoad.h"
#include "main.h"

extern Image image;
extern Font font;

extern Game game;

/********************************
* エンド画面
********************************/
void DrawEnd() {
	// 背景表示
    DrawGraph(0, 0, image.title, TRUE);
	
	// Thank you for playing
	DrawStringToHandle(10, 10, "Thank you for playing", 0x000000, font.handle_1_128, 0xffffff);

	// 謝辞
	//SetFontSize(40); FPS低下問題発生中
	//DrawFormatString(20, 200, 0x000000, "使用した素材のクレジット");
	//SetFontSize(32);
	DrawStringToHandle(10, 200, "使用した素材のクレジット", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(10, 280, "プレイヤー画像：AAA様", 0x000000, font.handle_1_32, 0xffffff);
	DrawStringToHandle(10, 320, "リンゴ画像：AAA様", 0x000000, font.handle_1_32, 0xffffff);
	DrawStringToHandle(10, 360, "フォント：AAA様", 0x000000, font.handle_1_32, 0xffffff);

	DrawStringToHandle(520, 670, "ESC キーで閉じる", 0x000000, font.handle_1_32, 0xffffff);

	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		game.mode = EXIT;
	};
};