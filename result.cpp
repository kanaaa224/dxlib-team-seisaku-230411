#include "DxLib.h"
#include "resourceLoad.h"
#include "main.h"

extern Image image;
extern Font font;

extern Game game;

/********************************
* リザルト画面
********************************/
void DrawResult() {
	// 背景表示
	DrawGraph(0, 0, image.title, TRUE);

	DrawStringToHandle(340, 140, "リザルト画面", 0x000000, font.handle_1_32, 0xffffff);

	// 戻る表示
	DrawStringToHandle(420, 670, "ESCキーまたはBボタンでもどる", 0x000000, font.handle_1_32, 0xffffff);

	// Space でタイトル
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		game.mode = TITLE;
	};
};