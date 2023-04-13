#include"Title.h"

int Image;				//背景画像

int SoundTitle;			//タイトルの音楽
int SoundMoveCorsor;	//カーソル移動の効果音
int	SoundDecision;		//決定の効果音

int LoadImages(void)
{
	if ((Image = LoadGraph("images/TitleImage.png")) == -1)return -1;
}

//int LoadSounds(void)
//{
//
//}

void DrawTitle(void)
{
	DrawGraph(0, 0, Image, FALSE);
}