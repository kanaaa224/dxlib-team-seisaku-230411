// 作：島袋

#include "DxLib.h"
#include "resourceLoad.h"

extern Image image;
extern Font font;

// タイトル画像表示
void drawHelp() {
	DrawGraph(0, 0, image.title, TRUE);
	DrawGraph(0, 0, image.controller, TRUE);
	DrawGraph(0, 0, image.controller_s, TRUE);
	DrawStringToHandle(340, 140, "操作説明", 0x000000, font.handle_1, 0xffffff);
};