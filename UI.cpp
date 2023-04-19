#include"DxLib.h"
#include"UI.h"
#include"main.h"
#include"init.h"

extern Init ini;
extern Game game;

const int TIMELIMIT = 60000;		//60ïb

void DrawUserInterFace()
{
	DrawTimeLimit();
}

/*êßå¿éûä‘*/
void DrawTimeLimit()
{
	int Time = TIMELIMIT - (GetNowCount() - ini.StartTime);
	if (Time <= 0)
	{
		game.mode = RESULT;
	}
	DrawFormatString(100, 100, 0xff0000, "%d", Time / 1000);

}

//void DrawScore()
//{
//
//}
