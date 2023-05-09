#include "DxLib.h"
#include "resourceLoad.h"
#include "main.h"
#include "init.h"
#include "UI.h"
#include "player.h"
#include "Apple.h"
#include "ranking.h"

extern Image image;
extern Font font;

extern Game game;

Init ini;

/********************************
* ƒQ[ƒ€‰Šú‰»
********************************/
void GameInit() { // –¢Š®¬
	game.mode = MAIN;

	ini.StartTime = GetNowCount();

	SetUI(0, 60);
	SetPlayerX(600);
	AppleInit(0);

	SetRankingState(0);
};