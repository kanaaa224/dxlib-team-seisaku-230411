#include "DxLib.h"
#include "resourceLoad.h"
#include "main.h"
#include "PadInput.h"
#include "player.h"
#include "title.h"
#include "test.h"
#include "help.h"
#include "ranking.h"
#include "ranking_name_input.h"
#include "end.h"
#include "init.h"
#include "result.h"
#include"UI.h"
#include "Apple.h"
#include "Pause.h"

extern Image image;
extern Font font;
extern Sound sound;

Game game;

// プログラムの開始
int WINAPI WinMain(_In_ HINSTANCE  hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR LpCmdLine, _In_ int NCmdShow)
{
	// FPSの計測と表示を行うローカル変数の宣言
	LONGLONG nowTime = GetNowHiPerformanceCount();
	LONGLONG oldTime = nowTime;
	LONGLONG fpsCheckTime;
	double deltaTime = 0;
	int fpsCounter = 0;
	int fps = 0;

	// タイトルを設定
	SetMainWindowText("りんごおとし");

	// 他のDxLibと競合しないように
	SetMainWindowClassName("りんごおとし");

	// ウインドウモードで起動
	ChangeWindowMode(TRUE);

	// ウインドウのサイズ
	SetGraphMode(1280, 720, 32);

	// DXライブラリの初期化処理
	if (DxLib_Init() == -1)return -1;

	// 描画先画面を裏にする（ダブルバッファリング）
	SetDrawScreen(DX_SCREEN_BACK);

	// ループ前にFPS計測を初期化
	fpsCheckTime = GetNowHiPerformanceCount();
	fps = 0;
	fpsCounter = 0;

	int nextTime;

	//game.mode = TITLE;

	// リソースを読み込んで、他の .cpp でもメンバー変数で利用可能にする関数（島袋）
	if (ResourceLoad() == -1) return -1;

	// ランキングデータの読込
	if (ReadRanking() == -1) return -1;

	// ゲームループ
	while (ProcessMessage() == 0 && game.mode != 99&& !(JudgeButton(XINPUT_BUTTON_BACK)))
	{
		// 画面の初期化
		ClearDrawScreen();

		//コントローラーの入力を取得
		//コントローラーのMODEを押すと左スティックと十字ボタンの入力が逆になる
		InputController();

		//ゲームモードと画面遷移
		switch (game.mode) {
		case TITLE:
			// タイトル
			DrawTitle();
			if (CheckSoundMem(sound.subbgm) == 0) {
				PlaySoundMem(sound.subbgm, DX_PLAYTYPE_BACK, TRUE);
			}
			break;
		case INIT:
			// ゲーム初期化
			GameInit();
			StopSoundMem(sound.subbgm);
			break;
		case MAIN:
			// 背景表示
			DrawGraph(0, 0, image.title, TRUE);
			
			// 開発用 - Rキーで強制リザルト
			if (CheckHitKey(KEY_INPUT_R)) {
				game.mode = RESULT;
			};
			if (JudgeButton(XINPUT_BUTTON_START) == 1) { //ポーズ
				if (GetPauseFlg() == 0) {
					SetPauseFlg(1);
				}
				else {
					SetPauseFlg(0);
				}
			}
			// プレイヤー開始
			if (GetPauseFlg() == 0) {
				if (game.soundflg == 0) {		//最初だけはじめから再生
					//BGM
					PlaySoundMem(sound.mainbgm, DX_PLAYTYPE_BACK, TRUE);
					game.soundflg = 1;
				}
				else {
					//BGM
					PlaySoundMem(sound.mainbgm, DX_PLAYTYPE_BACK, FALSE);
				}

				PlayerControll();
				DrawPlayer();
				DrawUserInterFace();
				HitBoxPlayer();
				
				//リンゴ
				FallApple();
			}
			else {
				//BGM
				StopSoundMem(sound.mainbgm);
				for (int i = 0; i < 10; i++) {
					if (ReturnAppleFlg(i) == TRUE) {
						//リンゴの表示
						DrawRotaGraph(ReturnAppleX(i), ReturnAppleY(i), 0.19, 0, ReturnAppleImg(i), TRUE);
					}
				}
				DrawPlayerPause();
				DrawUserInterFace();
				HitBoxPlayer();
				DrawStringToHandle(200, 310, "-- ポーズ中 --", 0x000000, font.handle_1_128, 0xffffff);
				//リンゴ
				//FallApple();
			}
			break;
		case HELP:
			// ヘルプ画面（島袋）
			DrawHelp();
			break;
		case RESULT:
			//BGM
			StopSoundMem(sound.mainbgm);
			if (CheckSoundMem(sound.subbgm) == 0) {
				PlaySoundMem(sound.subbgm, DX_PLAYTYPE_BACK, TRUE);
			}
			game.soundflg = 0;
			// リザルト画面
			DrawResult();
			break;
		case INPUTNAME:
			// ランキング入力画面（島袋）
			DrawRankingNameInput();
			break;
		case RANKING:
			// ランキング画面
			DrawRanking();
			break;
		case END:
			// エンド画面
			DrawEnd();
			break;
		case TEST:
			// テストで、画像やフォント表示（島袋）（タイトルでTを押して発動）
			DrawTest();
			break;
		}

		// FPSの表示
		/*SetFontSize(16);
		DrawFormatString(390, 5, 0xffffff, "FPS:%3d DELTA: %8.6fsec  %d", fps, deltaTime, GetStickX());*/
		
		// 裏画面の内容を表画面に反映する
		ScreenFlip();

		// １ループ時点のシステム時間を取得
		oldTime = nowTime;
		nowTime = GetNowHiPerformanceCount();

		// １ループの時間経過を求める
		deltaTime = (nowTime - oldTime) / 1000000.0F;

		// １秒間のFPSを計測する、１秒ごとに初期化する
		fpsCounter++;
		if (nowTime - fpsCheckTime > 1000000) { // 1000000(240FPS) 500000(120FPS) 250000(60FPS)
			fps = fpsCounter;
			fpsCounter = 0;
			fpsCheckTime = nowTime;
		}

		// FPS60 固定
		nextTime = GetNowCount();
		nextTime += 16;
		if (nextTime > GetNowCount()) {
			WaitTimer(nextTime - GetNowCount());
		}
	}

	// DXライブラリ使用の終了処理
	DxLib_End();

	// プログラムの終了
	return 0;

}
