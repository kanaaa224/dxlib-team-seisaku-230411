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

	/*
	ChangeFont("しょかきうたげ（無料版）");
	ChangeFontType(DX_FONTTYPE_EDGE);
	SetFontSize(128);
	DrawString(340, 140, "りんごおとし", 0x000000, 0xffffff);

	// 開発用
	//DrawCircle(mirutame[0], mirutame[1], mirutame[2], 0xffffff, FALSE);
	DrawBox(mirutame[0], mirutame[1], mirutame[0] + mirutame[2], mirutame[1] + mirutame[3], 0xffffff, FALSE);
	DrawFormatString(mirutame[0], mirutame[1], 0xffffff, "%d - %d", mirutame[0], mirutame[1]);
	if (CheckHitKey(KEY_INPUT_W)) {
		mirutame[1]--;
	};
	if (CheckHitKey(KEY_INPUT_S)) {
		mirutame[1]++;
	};
	if (CheckHitKey(KEY_INPUT_A)) {
		mirutame[0]--;
	};
	if (CheckHitKey(KEY_INPUT_D)) {
		mirutame[0]++;
	};
	if (CheckHitKey(KEY_INPUT_Q)) {
		mirutame[2]--;
	};
	if (CheckHitKey(KEY_INPUT_E)) {
		mirutame[2]++;
	};
	if (CheckHitKey(KEY_INPUT_R)) {
		mirutame[3]--;
	};
	if (CheckHitKey(KEY_INPUT_F)) {
		mirutame[3]++;
	};

	// 開発
	int mirutame[4];
	*/
};