// 作：島袋

#include "DxLib.h"
#include "resourceLoad.h"

extern Image image;
extern Font font;

// タイトル画像表示
void drawTest() {
    DrawGraph(0, 0, image.title, TRUE);
	
	DrawStringToHandle(400, 40, "りんごおとし", 0x000000, font.handle_1_32, 0xffffff);
	DrawStringToHandle(400, 90, "りんごおとし", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(400, 150, "りんごおとし", 0x000000, font.handle_1_128, 0xffffff);

	DrawRotaGraph(100, 150, 0.5f, 0, image.player[0], TRUE);
	DrawRotaGraph(150, 400, 0.5f, 0, image.apple[0], TRUE);

	/*
	ChangeFont("しょかきうたげ（無料版）");
	ChangeFontType(DX_FONTTYPE_EDGE);
	SetFontSize(128);
	DrawString(340, 140, "りんごおとし", 0x000000, 0xffffff);
	*/
};