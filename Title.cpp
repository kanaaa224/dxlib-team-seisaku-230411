#include"Title.h"

int Image;				//背景画像

int SoundTitle;			//タイトルの音楽
int SoundMoveCorsor;	//カーソル移動の効果音
int	SoundDecision;		//決定の効果音

/*画像読み込み*/
int LoadImages(void)
{
	//タイトル画像の読み込み
	if ((Image = LoadGraph("images/title.png")) == -1)return -1;
}
//
///*サウンド読み込み*/
//int LoadSounds(void);
//{
//	//タイトルSEの読み込み
//	SoundTitle = LoadSoundMem();
//	SoundMoveCorsor = LoadSoundMem();
//	SoundDecision = LoadSoundMem();
//}

/*タイトル*/
void DrawTitle(void)
{
	DrawString(0, 0, "Hello", 0xffffff);
	DrawGraph(0, 0, Image, FALSE);
}