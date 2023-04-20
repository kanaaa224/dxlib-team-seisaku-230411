/************************************************
*　りんごの処理プログラム
*　制作：豊元、新里
************************************************/
#include "DxLib.h"
#include "Apple.h"
#include "resourceLoad.h"
#include "player.h"

/************************************************
*　変数の宣言（グローバル変数）
************************************************/
//int gAppleImg[20];	//りんごの画像変数
int gP;					//りんごの確率

int gOldTime;			//前時間（前時間と後時間を比較してりんごが表示されてから何秒たった計測する変数
int gNowTime;			//後時間（前時間と後時間を比較してりんごが表示されてから何秒たった計測する変数
int gTimeFlg = FALSE;	//時間計測用の変数

int gFPSCount = 0;

int gRACount = 0;	//赤りんごの個数
int gBACount = 0;	//青りんごの個数
int gGACount = 0;	//金りんごの個数
int gPACount = 0;	//毒りんごの個数
int gScore = 0;		//スコア

extern Image image;		//りんごの画像変数

/************************************************
*　定数の宣言
************************************************/
const int APPLE_MAX = 10;

/************************************************
*　画像読込
************************************************/
//int LoadImges(void)
//{
//	//りんご画像データの分割読み込み
//	if (LoadDivGraph("images/Apple.png", 20, 5, 4, 700, 620, gAppleImg) == -1)return -1;
//}

/************************************************
*　リンゴ落下処理
************************************************/
void FallApple(void)
{
	for (int i = 0; i < APPLE_MAX; i++) {

		if (gApple[i].flg == TRUE) {

			////テスト
			//SetFontSize(16);
			//DrawFormatString(0, 0, 0xffffff, "Y:%3d", gApple[i].y);
			//DrawFormatString(100, 0, 0xffffff, "X:%3d", gApple[i].x);

			//リンゴの表示
			DrawRotaGraph(gApple[i].x, gApple[i].y, 0.19, 0, gApple[i].img, TRUE);

			//真っすぐ下に移動
			gApple[i].y += gApple[i].speed;

			//りんごの座標が１０００になったらりんごをけす
			if (gApple[i].y > 1000 + gApple[i].h) {
				gApple[i].flg = FALSE;
				gApple[i].y = 0;
			}

		}

	}

	//gOldTime;//前時間（前時間と後時間を比較してりんごが表示されてから何秒たった計測する変数）
	//gNowTime;//後時間（前時間と後時間を比較してりんごが表示されてから何秒たった計測する変数）
	//gTimeFlg;

	//if (gTimeFlg == FALSE) {
	//	gOldTime = GetNowCount();
	//	gTimeFlg = TRUE;
	//}

	//gNowTime = GetNowCount();

	if ((gFPSCount++) % 25 == 0) {//２５フレームごとに生成されるりんごの数をチェック
		CreateApple();
		HitBox();
	}

}

/************************************************
*　リンゴ生成＆確率
************************************************/
int CreateApple(void)
{

	//りんご確率
	gP = 0;

	int AppleImg = image.apple[0];

	gP = GetRand(99);//100%

	if (gP < 59) {
		AppleImg = image.apple[REDAPPLE];//赤リンゴ
	}
	else if (gP >= 60 && gP < 84) {
		AppleImg = image.apple[BLUEAPPLE];//青リンゴ
	}
	else if (gP >= 85 && gP < 94) {
		AppleImg = image.apple[GOLDAPPLE];//金リンゴ
	}
	else if (gP >= 95 && gP < 99) {
		AppleImg = image.apple[POISONAPPLE];//毒リンゴ
	}

	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == FALSE) {
			gApple[i].img = AppleImg;				//リンゴの画像
			gApple[i].x = 70 + (GetRand(6) * 130);	//りんごのレーン決定
			gApple[i].y = -150;						//リンゴの初期Y座標
			AppleSpeed(i);							//リンゴの速度
			//成功
			return gApple[i].flg = TRUE;
		}
	}
	//失敗
	return FALSE;
}

/************************************************
*　リンゴの速度
************************************************/
void AppleSpeed(int i)
{
	if (gP < 59) {
		gApple[i].speed = 1;//赤リンゴ
	}
	else if (gP >= 60 && gP < 84) {
		gApple[i].speed = 2;//青リンゴ
	}
	else if (gP >= 85 && gP < 94) {
		gApple[i].speed = 3.5;//金リンゴ
	}
	else if (gP >= 95 && gP < 99) {
		gApple[i].speed = 0.5;//毒リンゴ
	}
}

/************************************************
*　りんごの当たり判定
************************************************/
int HitBox(void)
{
	int sx1[10];
	int sy1[10];
	int sx2[10];
	int sy2[10];

	for (int i = 0; i < 10; i++) {
		if (gApple[i].flg == TRUE) {
			sx1[i] = gApple[i].x - 31;	//左上 X
			sy1[i] = gApple[i].y - 60;	//左上 Y
			sx2[i] = gApple[i].x + 31;	//右下 X
			sy2[i] = gApple[i].y + 60;	//右下 Y
		}
	}

	for (int i = 0; i < 10; i++) {
		if (gApple[i].flg == TRUE) {
			for (int j = 0; j < 10; j++) {
				if (gApple[i].img == gApple[j].img) {
					if (sx1[i] == sx1[j] && sx2[j] == sx2[i] && sy1[i] < sy1[j] && sy1[j] < sy2[i]) {
						gApple[j].flg = FALSE;	//削除
					}
				}
			}
		}
	}

	return 0;

}

int HitBoxPlayer(void) {
	int sx1[10];
	int sy1[10];
	int sx2[10];
	int sy2[10];

	int px1;
	int py1;
	int px2;
	int py2;

	for (int i = 0; i < 10; i++) {
		if (gApple[i].flg == TRUE) {
			sx1[i] = gApple[i].x - 51;	//左上 X
			sy1[i] = gApple[i].y - 50;	//左上 Y
			sx2[i] = gApple[i].x + 51;	//右下 X
			sy2[i] = gApple[i].y + 50;	//右下 Y
		}
	}

	px1 = ReturnPlayerX() - 30;
	py1 = ReturnPlayerY() - 30;
	px2 = ReturnPlayerX() + 30;
	py2 = ReturnPlayerY() + 30;

	DrawBox(px1, py1, px2, py2, 0xffffff, TRUE);

	for (int i = 0; i < 10; i++) {
		if (gApple[i].flg == TRUE) {
			DrawBox(sx1[i], sy1[i], sx2[i], sy2[i], 0xffffff, TRUE);
		}
		DrawFormatString(390, 100, 0xffffff, "%d", sy1[i]);
	}

	for (int i = 0; i < 10; i++) {
		if (gApple[i].flg == TRUE) {

			if (px1 < sx2[i] && sx1[i] < px2 && py1 < sy2[i] && sy1[i] < py2) {
				gApple[i].flg = FALSE;	//削除
				ApplePoint(i);
			}

			
			/*if (py1 < sy2[i]) {
				gApple[i].flg = FALSE;
			}*/
		}
	}
	
	SetFontSize(16);
	DrawFormatString(0, 100, 0xffffff, "Score:%d", gScore);
	DrawFormatString(0, 120, 0xffffff, "RED:%d", gRACount);
	DrawFormatString(0, 140, 0xffffff, "BULE:%d", gBACount);
	DrawFormatString(0, 160, 0xffffff, "GOLD:%d", gGACount);
	DrawFormatString(0, 180, 0xffffff, "POISON:%d", gPACount);

	return 0;
}

/************************************************
*　りんごのスコア処理
************************************************/
void ApplePoint(int i)
{
	if (gApple[i].img == image.apple[REDAPPLE]) {//赤りんご
		gScore += 100;
		gRACount += 1;
	}
	if (gApple[i].img == image.apple[BLUEAPPLE]) {//青りんご
		gScore += 200;
		gBACount += 1;
	}
	if (gApple[i].img == image.apple[GOLDAPPLE]) {//金りんご
		gScore += 500;
		gGACount += 1;
	}
	if (gApple[i].img == image.apple[POISONAPPLE]) {//毒りんご
		gScore -= 750;
		gPACount += 1;
		if (gScore < 0) {
			gScore = 0;
		}
	}
}