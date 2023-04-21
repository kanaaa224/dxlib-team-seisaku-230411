#include "DxLib.h"
#include "resourceLoad.h"
#include "main.h"
#include"init.h"

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
};