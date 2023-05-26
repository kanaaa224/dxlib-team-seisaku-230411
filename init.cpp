#include "DxLib.h"
#include "resourceLoad.h"
#include "main.h"
#include "init.h"
#include "UI.h"
#include "player.h"
#include "Apple.h"
#include "ranking.h"
#include "ranking_name_input.h"

extern Game game;
Apple InitApple;
Init ini;

/********************************
* ゲーム初期化
********************************/
void GameInit() { // 未完成gg
	game.mode = MAIN;

	ini.StartTime = GetNowCount();

	/*SetPlayerX(600);*/
	/*apple.AppleInit();*/
	
    AppleCount::AppleMainInit(0, 0, 0, 0, 0);
    

	// ランキングの実行済みフラグをリセット
	SetRankingState(0);

	// ランキング入力画面リセット
	ResetRankingNameInput();
};