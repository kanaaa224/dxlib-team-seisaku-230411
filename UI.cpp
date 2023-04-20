#include"DxLib.h"
#include"UI.h"
#include"main.h"
#include"init.h"
#include"resourceLoad.h"
#include"Apple.h"

extern Init ini;
extern Game game;
extern Image image;

const int TIMELIMIT = 60000;		//60ïb

void DrawUserInterFace()
{
	DrawTimeLimit();
	DrawScore();
}

/*êßå¿éûä‘*/
void DrawTimeLimit()
{
	int Time = TIMELIMIT - (GetNowCount() - ini.StartTime);
	if (Time <= 0)
	{
		game.mode = RESULT;
	}
	DrawFormatString(1100, 100, 0xff0000, "%d", Time / 1000);
}

void DrawScore()
{
	//ÉäÉìÉSÇÃï\é¶
	DrawRotaGraph(1090, 350, 0.125, 0, image.apple[REDAPPLE], TRUE);
	DrawRotaGraph(1170, 350, 0.125, 0, image.apple[BULEAPPLE], TRUE);
	DrawRotaGraph(1250, 350, 0.125, 0, image.apple[GOLDAPPLE], TRUE);

}