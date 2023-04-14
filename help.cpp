// 作：島袋

#include "DxLib.h"
#include "resourceLoad.h"
#include "help.h"

extern Image image;
extern Font font;

Help help;

/********************************
* ヘルプ画面描画
********************************/
void DrawHelp() {
	// 背景表示
	DrawGraph(0, 0, image.title, TRUE);

	// コントローラー画像表示
	DrawExtendGraph(0, 0, 200, 100, image.controller, TRUE);
	DrawExtendGraph(0, 0, 100, 100, image.controller_s, TRUE);

	// 文字サイズ指定
	SetFontSize(10);

	// タイトル表示
	DrawStringToHandle(340, 140, "操作説明", 0x000000, font.handle_1_64, 0xffffff);

	help.state = 0;
	if (help.state == 0) {
		// コントローラーのヘルプ表示


	}
	else if (help.state == 1) {
		// ゲーム内容のヘルプ表示
		

		// 文字サイズ指定
		SetFontSize(10);
	}

	
};