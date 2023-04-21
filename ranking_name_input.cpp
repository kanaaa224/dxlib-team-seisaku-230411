// 作：島袋

#include "DxLib.h"
#include "resourceLoad.h"

#include "main.h"
#include "PadInput.h"

extern Image image;
extern Font font;

extern Game game;

char rni_alphabet[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
char rni_qwerty[] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };
int rni_hiragana_select_state = 0;

int rni_selectstate;
int rni_stickflg = 0;

// 開発
int mirutame[4];

/********************************
* ランキング入力処理
********************************/
void DrawRankingNameInput() { // 島袋が担当中
    // 背景表示
    DrawGraph(0, 0, image.title, TRUE);

    DrawStringToHandle(340, 140, "ランキング入力", 0x000000, font.handle_1_32, 0xffffff);

	// フォントサイズの設定
	ChangeFontSize(20); // ループ内で一回のみ機能

	// 名前入力指示文字列の描画
	DrawString(150, 240, "ランキングに登録します", 0xFFFFFF);

	//ChangeFontSize(30);

	DrawString(150, 270, "名前を英字で入力してください", 0xFFFFFF);

	for (int i = 0; i < (sizeof(rni_alphabet) / sizeof(rni_alphabet[0])); i++) {
		DrawFormatString(10 + (i * 20), 300, 0x000000,"%c", rni_alphabet[i]);
	}










	// 戻る表示
	DrawStringToHandle(530, 670, "Aボタンでもどる", 0x000000, font.handle_1_32, 0xffffff);

	// ゲームモードセレクト処理
	if (rni_selectstate = GetStickY() > 32000 && rni_stickflg == 0) {
		//if (title.state <= 0) {
		//	title.state = 3;
		//}
		//else {
		//	title.state -= 1;
		//};
		rni_stickflg = 1;
	}
	else if (rni_selectstate = GetStickY() < -32000 && rni_stickflg == 0) {
		//if (title.state >= 3) {
		//	title.state = 0;
		//}
		//else {
		//	title.state += 1;
		//};
		rni_stickflg = 1;
	};
	// スティックが戻ると操作受付
	if (rni_selectstate = GetStickY() < 1200 && rni_stickflg == 1) {
		if (rni_selectstate = GetStickY() > -1200) {
			rni_stickflg = 0;
		};
	};
	// Bボタンで選択
	if (JudgeReleaseButton(XINPUT_BUTTON_B) == 1) {
		//if (title.state == 0) {
		//	// スタート選択
		//	game.mode = INIT;
		//}
		//else if (title.state == 1) {
		//	// ヘルプ選択
		//	game.mode = HELP;
		//}
		//else if (title.state == 2) {
		//	// ランキング選択
		//	game.mode = RANKING;
		//}
		//else if (title.state == 3) {
		//	// 終わる選択
		//	game.mode = END;
		//};
	};

	// キーボード入力対応
    if (CheckHitKey(KEY_INPUT_ESCAPE)) {
        game.mode = TITLE;
    };

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
};







/*
void InputName(void) {

    // ランキング画像表示
    DrawGraph(0, 0, gTitleImg, FALSE);

    // フォントサイズの設定
    SetFontSize(20);

    // 名前入力指示文字列の描画
    DrawString(150, 240, "ランキングに登録します", 0xFFFFFF);
    DrawString(150, 270, "名前を英字で入力してください", 0xFFFFFF);

    // 名前入力
    DrawString(150, 310, "> ", 0xFFFFFF);
    DrawBox(160, 305, 300, 335, 0x000055, TRUE);
    if (KeyInputSingleCharString(170, 310, 10, gRanking[RANKING_DATA - 1].name, FALSE) == 1) {
        gRanking[RANKING_DATA - 1].score = gScore; // ランキングデータにスコア登録
        SortRanking(); // ランキング並び替え
        SaveRanking(); // ランキング保存
        gGameMode = RANKING; // ゲームモード変更
    };
    //gGameMode = TITLE;
};
*/



