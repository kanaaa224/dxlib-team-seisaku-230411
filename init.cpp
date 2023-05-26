#include "DxLib.h"
#include "resourceLoad.h"
#include "main.h"
#include "init.h"
#include "UI.h"
#include "player.h"
#include "Apple.h"
#include "ranking.h"
#include "ranking_name_input.h"

/********************************
* ゲーム初期化
********************************/
void GameInit() {
    Game::ModeSet(MAIN);
	
    AppleCount::AppleMainInit(0, 0, 0, 0, 0);
    

	// ランキングの実行済みフラグをリセット
	SetRankingState(0);

	// ランキング入力画面リセット
    RankingNameInput::Reset();
};