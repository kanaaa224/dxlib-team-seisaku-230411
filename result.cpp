#include "DxLib.h"
#include "resourceLoad.h"
#include "main.h"
#include"UI.h"

extern Image image;
extern Font font;

extern Game game;
extern UI ui;

/********************************
* リザルト画面
********************************/
void DrawResult() { // 未完成
	// 背景表示
	DrawGraph(0, 0, image.title, TRUE);

	DrawStringToHandle(160, 180, "赤リンゴ", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(160, 250, "青リンゴ", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(160, 320, "黄リンゴ", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(160, 390, "毒リンゴ", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(220, 460, "スコア", 0x000000, font.handle_1_64, 0xffffff);

	// 戻る表示
	DrawStringToHandle(530, 670, "Aボタンでもどる", 0x000000, font.handle_1_32, 0xffffff);

	// Space でタイトル
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		game.mode = TITLE;
	};
};