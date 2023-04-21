#pragma once

#define TITLE 0
#define INIT 1
#define MAIN 2
#define HELP 3
#define RESULT 4
#define INPUTNAME 5
#define RANKING 6
#define END 7
#define TEST 8
#define EXIT 99

//ÉQÅ[ÉÄÉÇÅ[Éhä«óù
class Game {
public:
	//char mode[10] = "TITLE";
	int mode = 0;
};

static int PauseFlg = 0;


//static enum MODE{
//	TITLE,
//	INIT,
//	MAIN,
//	HELP,
//	RESULT,
//	INPUTNAME,
//	RANKING,
//	END,
//	TEST,
//	EXIT = 99
//};
//
//MODE gGameMode;