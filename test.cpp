// 作：島袋

#include "DxLib.h"
#include "resourceLoad.h"

extern Image image;
extern Font font;

// タイトル画像表示
void drawTest() {
    DrawGraph(0, 0, image.title, TRUE);
	
	DrawStringToHandle(340, 140, "りんごおとし", 0x000000, font.handle_1, 0xffffff);

	/*
	ChangeFont("しょかきうたげ（無料版）");
	ChangeFontType(DX_FONTTYPE_EDGE);
	SetFontSize(128);
	DrawString(340, 140, "りんごおとし", 0x000000, 0xffffff);
	*/
};