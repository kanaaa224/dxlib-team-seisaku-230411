/********************************
* テスト
* 作者：島袋
********************************/
#include "DxLib.h"
#include "test.h"
#include "resourceLoad.h"
#include "main.h"
#include "PadInput.h"


/********************************
* テスト
********************************/
void Test::Draw() {
    DrawGraph(0, 0, Image::GetImages(IMG_TITLE, 0), TRUE);
	
	DrawStringToHandle(400, 40, "りんごおとし", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	DrawStringToHandle(400, 90, "りんごおとし", 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);
	DrawStringToHandle(400, 150, "りんごおとし", 0x000000, Font::GetFonts(FONT_1_128), 0xffffff);

	DrawRotaGraph(150, 400, 0.5f, 0, Image::GetImages(IMG_APPLE,0), TRUE);

	// 戻る表示
	DrawStringToHandle(530, 670, "Aボタンでもどる", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

	// Aボタンで終了
	if (PAD_INPUT::JudgeReleaseButton(XINPUT_BUTTON_A) == 1) {
        Game::ModeSet(TITLE);
	};

	// ESCキーで終了
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
        Game::ModeSet(TITLE);
	};
};