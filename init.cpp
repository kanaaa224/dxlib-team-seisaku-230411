#include "DxLib.h"
#include "resourceLoad.h"
#include "main.h"
#include "init.h"
#include "UI.h"
#include "player.h"
#include "Apple.h"
#include "ranking.h"
#include "ranking_name_input.h"

extern Image image;
extern Font font;

extern Game game;

Init ini;

/********************************
* ゲーム初期化
********************************/
void GameInit() { // 未完成
	game.mode = MAIN;

	ini.StartTime = GetNowCount();

	SetUI(0, 60);
	SetPlayerX(600);
	AppleInit();

	// ランキングの実行済みフラグをリセット
	SetRankingState(0);

	// ランキング入力画面リセット
	ResetRankingNameInput();
};