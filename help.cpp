/********************************
* ヘルプ画面処理
* 作者：島袋
********************************/
#include "DxLib.h"
#include "help.h"
#include "resourceLoad.h"
#include "main.h"
#include "PadInput.h"


/********************************
* ヘルプ変数初期化
********************************/
int Help::state = 0;


/********************************
* ヘルプ画面描画
********************************/
void Help::Draw() {
	// 背景表示
	DrawGraph(0, 0, Image::GetImages(IMG_TITLE, 0), TRUE);

	// タイトル表示
	DrawStringToHandle(180, 40, "ヘルプ", 0x000000, Font::GetFonts(FONT_1_128), 0xffffff);

	// 説明表示
	DrawStringToHandle(680, 130, "左スティックで説明を切りかえ", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

	// 戻る表示
	DrawStringToHandle(370, 670, "Bボタンでゲーム開始、Aボタンでもどる", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

	// メンバー変数に保存されたステートで表示を分岐

	if (state == 0) {
		// コントローラーのヘルプ表示

		// サブタイトル表示
		DrawStringToHandle(735, 40, "操作説明", 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);
		DrawTriangle(1065, 55, 1105, 70, 1065, 85, 0x000000, TRUE);

		// コントローラー画像表示
		DrawExtendGraph(330, 290, 630, 490, Image::GetImages(IMG_CONTROLLER, 0), TRUE);
		//DrawExtendGraph(400, 500, 500, 600, image.controller_s, TRUE);

		// B Btn
		DrawLine(587, 368, 700, 368, 0x000000);
		DrawStringToHandle(700, 345, "Bボタン：決定", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

		// A Btn
		DrawLine(566, 392, 700, 392, 0x000000);
		DrawStringToHandle(700, 380, "Aボタン：もどる", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

		// Left Stick
		DrawLine(436, 421, 436, 550, 0x000000);
		DrawStringToHandle(280, 550, "左スティック：プレイヤーと、選たくカーソルの移動", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

		// Back Btn
		DrawLine(447, 350, 700, 276, 0x000000);
		DrawStringToHandle(700, 255, "BACKボタン：ゲームを終わる", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

		// Start Btn
		DrawLine(510, 350, 700, 300, 0x000000);
		DrawStringToHandle(700, 290, "STARTボタン：ポーズ", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	}
	else if (state == 1) {
		// ゲーム内容のヘルプ表示

		// サブタイトル表示
		DrawStringToHandle(770, 40, "ゲーム説明", 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);
		DrawTriangle(710, 55, 670, 70, 710, 85, 0x000000, TRUE);

		// 説明表示
		DrawStringToHandle(100, 220, "この「りんごおとし」は、プレイヤーを左右に動かすだけの単純なゲームです。", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
		DrawStringToHandle(20, 270, "頭上からリンゴを落とされるといういやがらせを受けるので、毒リンゴだけはよけながら、", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
		DrawStringToHandle(300, 320, "他のリンゴを取ってポイントをかせいでください。", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
		DrawStringToHandle(100, 370, "落下してくるリンゴは４種類です。", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

		/*
		時は20XX年。IT技術が急成長を遂げるこの世の中で、ある企業が開発した最先端なAIが暴走してしまい、我々人類を敵とみなしてしまう。
		そのAIは政府の防衛システムや民衆のPCを乗っ取り、今にも機械VS人類の戦争が起ころうとしていた。
		
		そしてその頃、そんな事しるはずもなかった主人公、モヤキンは自分の体が全身黒染めであることに悩みを持っており、特に何もしていない魔王を私情で討伐しようと考えていた。
		そんなある日、彼はC++の最初の難問である「ポインタ」を理解するための修行を行うため「りんごおとしの森」へと向かった。その後の彼の運命とは...
		*/

		// リンゴ画像表示
		DrawLine(640, 420, 640, 620, 0x000000);
		DrawLine(200, 520, 1080, 520, 0x000000);

		// リンゴの説明
		DrawExtendGraph(200, 440, 250, 490, Image::GetImages(IMG_APPLE, 0), TRUE);
		DrawStringToHandle(260, 450, "赤リンゴ：ポイントUP", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

		DrawExtendGraph(670, 440, 720, 490, Image::GetImages(IMG_APPLE, 1), TRUE);
		DrawStringToHandle(730, 450, "青リンゴ：ポイントUP", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

		DrawExtendGraph(200, 550, 250, 600, Image::GetImages(IMG_APPLE, 2), TRUE);
		DrawStringToHandle(260, 560, "金リンゴ：ポイントUP＋", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);

		DrawExtendGraph(670, 550, 720, 600, Image::GetImages(IMG_APPLE, 3), TRUE);
		DrawStringToHandle(730, 560, "毒リンゴ：ポイントDOWN", 0x000000, Font::GetFonts(FONT_1_32), 0xffffff);
	};

	/********************************
	* 説明表示切替
	********************************/
	// コントローラー入力
	if ((PAD_INPUT::JudgeButton(XINPUT_BUTTON_DPAD_RIGHT) == 1) || (PAD_INPUT::GetStickX() > 3200)) {
		state = 1;
	}
	else if ((PAD_INPUT::JudgeButton(XINPUT_BUTTON_DPAD_LEFT) == 1) || (PAD_INPUT::GetStickX() < -32000)) {
		state = 0;
	};
	// Aボタンで終了
	if (PAD_INPUT::JudgeButton(XINPUT_BUTTON_A) == 1) {
        Game::ModeSet(TITLE);
	};
	// Bボタンでゲーム開始
	if (PAD_INPUT::JudgeButton(XINPUT_BUTTON_B) == 1) {
        Game::ModeSet(INIT);
	};

	// キーボード入力
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		state = 0;
	};
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		state = 1;
	};
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
        Game::ModeSet(TITLE);
	};
	if (CheckHitKey(KEY_INPUT_B)) {
        Game::ModeSet(INIT);
	};
};