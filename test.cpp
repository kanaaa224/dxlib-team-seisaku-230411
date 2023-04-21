// 作：島袋

#include "DxLib.h"
#include "resourceLoad.h"
#include "main.h"
#include "PadInput.h"

extern Image image;
extern Font font;

extern Game game;

/********************************
* テスト
********************************/
void DrawTest() {
    DrawGraph(0, 0, image.title, TRUE);
	
	DrawStringToHandle(400, 40, "りんごおとし", 0x000000, font.handle_1_32, 0xffffff);
	DrawStringToHandle(400, 90, "りんごおとし", 0x000000, font.handle_1_64, 0xffffff);
	DrawStringToHandle(400, 150, "りんごおとし", 0x000000, font.handle_1_128, 0xffffff);

	DrawRotaGraph(100, 150, 0.5f, 0, image.player[0], TRUE);
	DrawRotaGraph(150, 400, 0.5f, 0, image.apple[0], TRUE);

	// 戻る表示
	DrawStringToHandle(530, 670, "Aボタンでもどる", 0x000000, font.handle_1_32, 0xffffff);

	// Aボタンで終了
	if (JudgeReleaseButton(XINPUT_BUTTON_A) == 1) {
		game.mode = TITLE;
	};

	// ESCキーで終了
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		game.mode = TITLE;
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