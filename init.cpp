#include "DxLib.h"
#include "resourceLoad.h"
#include "main.h"
#include "init.h"
#include "UI.h"
#include "player.h"
#include "Apple.h"
#include "ranking.h"
#include "ranking_name_input.h"

extern Apple apple;

/********************************
* ゲーム初期化
********************************/
void GameInit() {
    Game::ModeSet(MAIN);
	
	apple.AppleMainInit();

	// ランキングの実行済みフラグをリセット
	SetRankingState(0);

	// ランキング入力画面リセット
	ResetRankingNameInput();
};