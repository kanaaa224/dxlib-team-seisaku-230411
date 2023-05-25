/************************************************
*　りんごの処理プログラム
*　制作：豊元、新里
************************************************/
#include "DxLib.h"
#include "resourceLoad.h"
#include "Apple.h"
#include "player.h"
#include<string>

/************************************************
*　変数の宣言
************************************************/
int gFPSCount = 0;

using std::string;
using std::to_string;

int AppleBlinkFlg;

/************************************************
*　オブジェクト宣言
************************************************/
//Image appleimage;			//画像
//Font applefont;			    //フォント
//Sound applesound;			//サウンド

/************************************************
*　初期化
************************************************/
void Apple::AppleInit() 
{
	for (int i = 0; i < APPLE_MAX; i++) {
		gApple[i].flg = FALSE;
		gApple[i].img = 0;
		gApple[i].x = 0;
		gApple[i].y = 0;
		gApple[i].w = 0;
		gApple[i].h = 0;
		gApple[i].speed = 0;
		gApple[i].point = 0;
	}
}
/************************************************
*　りんごのカウント、スコア、フラグ初期化
************************************************/
void Apple::AppleMainInit()
{
    AppleCount::SetRA(0);
    AppleCount::SetBL(0);
    AppleCount::SetGL(0);
    AppleCount::SetPO(0);
    AppleCount::SetScore(0);

	for (int i = 0; i < APPLE_MAX; i++) {
		gApple[i].flg = FALSE;
	}
}


/************************************************
*　リンゴ落下処理
************************************************/
void Apple::FallApple()
{
	for (int i = 0; i < APPLE_MAX; i++) {

		if (gApple[i].flg == TRUE) {
			//リンゴの表示
			DrawRotaGraph((int)gApple[i].x, (int)gApple[i].y, 0.19, 0, gApple[i].img, TRUE);

			//真っすぐ下に移動
			gApple[i].y += gApple[i].speed;

			//りんごの座標が１０００になったらりんごをけす
			if (gApple[i].y > 1000 + gApple[i].h) {
				gApple[i].flg = FALSE;
			}
		}
	}

	if ((gFPSCount++) % 25 == 0) {//２５フレームごとに生成されるりんごの数をチェック
		CreateApple();
		HitBox();
	}
}

/************************************************
*　リンゴ生成＆確率
************************************************/
int Apple::CreateApple()
{

	//りんご確率
	int AppleImg = Image::GetImages(IMG_APPLE, 0);

	gP = GetRand(99);//100%

	if (gP < 59) {
		AppleImg = Image::GetImages(IMG_APPLE, REDAPPLE); //赤リンゴ
	}
	else if (gP >= 60 && gP < 84) {
		AppleImg = Image::GetImages(IMG_APPLE, BLUEAPPLE); //青リンゴ
	}
	else if (gP >= 85 && gP < 94) {
		AppleImg = Image::GetImages(IMG_APPLE, GOLDAPPLE); //金リンゴ
	}
	else if (gP >= 95 && gP < 99) {
		AppleImg = Image::GetImages(IMG_APPLE, POISONAPPLE); //毒リンゴ
	}

	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == FALSE) {
			gApple[i].img = AppleImg;				//リンゴの画像
			gApple[i].x = 70 + (GetRand(6) * 130);	//りんごのレーン決定
			gApple[i].y = -50;						//リンゴの初期Y座標
			AppleSpeed(i);							//リンゴの速度
			gApple[i].flg = TRUE;
			//成功
			return TRUE;
		}
	}
	//失敗
	return FALSE;
}

/************************************************
*　リンゴの速度
************************************************/
void Apple::AppleSpeed(int i)
{
	if (gApple[i].img == Image::GetImages(IMG_APPLE, REDAPPLE)) {
		gApple[i].speed = 1;//赤リンゴ
	}
	else if (gApple[i].img == Image::GetImages(IMG_APPLE, BLUEAPPLE)) {
		gApple[i].speed = 2;//青リンゴ
	}
	else if (gApple[i].img == Image::GetImages(IMG_APPLE, GOLDAPPLE)) {
		gApple[i].speed = 3.5;//金リンゴ
	}
	else if (gApple[i].img == Image::GetImages(IMG_APPLE, POISONAPPLE)) {
		gApple[i].speed = 0.5;//毒リンゴ
	}
}

/************************************************
*　りんごの当たり判定
************************************************/
int Apple::HitBox()
{
	double sx1[10];
	double sy1[10];
	double sx2[10];
	double sy2[10];

	for (int i = 0; i < 10; i++) {
		if (gApple[i].flg == TRUE) {
			sx1[i] = gApple[i].x - 31;	//左上 X
			sy1[i] = gApple[i].y - 60;	//左上 Y
			sx2[i] = gApple[i].x + 31;	//右下 X
			sy2[i] = gApple[i].y + 60;	//右下 Y
		}
	}

    for (int i = 0; i < APPLE_MAX; i++) {
        if (gApple[i].flg == TRUE) {
            for (int j = 0; j < APPLE_MAX; j++) {
                if (sx1[i] == sx1[j] && sx2[j] == sx2[i] && sy1[i] < sy1[j] && sy1[j] < sy2[i]) {
                    if (gApple[i].img == gApple[j].img) {
                        gApple[i].flg = FALSE;	//削除
                    }
                }
            }
        }
    }

	return 0;

}

/******************************************************
* プレイヤーの当たり判定＆プレイヤーとりんごの接触処理
******************************************************/
int Apple::HitBoxPlayer() {
	double sx1[10];
	double sy1[10];
	double sx2[10];
	double sy2[10];

	

	for (int i = 0; i < 10; i++) {
		if (gApple[i].img == Image::GetImages(IMG_APPLE, POISONAPPLE)) {//毒りんごの当たり判定
			if (gApple[i].flg == TRUE) {
				sx1[i] = gApple[i].x - 40;	//左上 X
				sy1[i] = gApple[i].y - 37;	//左上 Y
				sx2[i] = gApple[i].x + 40;	//右下 X
				sy2[i] = gApple[i].y + 37;	//右下 Y
			}
		}
		else {											//毒りんご以外の当たり判定
			if (gApple[i].flg == TRUE) {
				sx1[i] = gApple[i].x - 46;	//左上 X
				sy1[i] = gApple[i].y - 43;	//左上 Y
				sx2[i] = gApple[i].x + 46;	//右下 X
				sy2[i] = gApple[i].y + 43;	//右下 Y
			}
		}
	}

	if (GetBlinkFlg() == 0) {	//点滅中は当たらないように
		for (int i = 0; i < 10; i++) {
			if (gApple[i].flg == TRUE) {

				if (px1 < sx2[i] && sx1[i] < px2 && py1 < sy2[i] && sy1[i] < py2) {
					if (gApple[i].img == Image::GetImages(IMG_APPLE, POISONAPPLE)) {
						//player.SetPlayerBlinkFlg(1);
						SetBlinkFlg(1);
					}
					gApple[i].flg = FALSE;	//削除
					ApplePoint(i);//スコア処理
				}
			}
		}
	}
	//プレイヤーとりんごが接触したらりんごが消える
	for (int i = 0; i < 10; i++) {
		if (gApple[i].flg == TRUE) {
			
			if (px1 < sx2[i] && sx1[i] < px2 && py1 < sy2[i] && sy1[i] < py2) {
				if (gApple[i].img == Image::GetImages(IMG_APPLE,POISONAPPLE)) {
					SetBlinkFlg(1);
				}
			}
		}
	}
	std::string str1 = std::to_string(AppleCount::ReturnRA());
	std::string str2 = std::to_string(AppleCount::ReturnBL());
	std::string str3 = std::to_string(AppleCount::ReturnGL());

	DrawStringToHandle(1020, 400, str1.c_str(), 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);
	DrawStringToHandle(1120, 400, str2.c_str(), 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);
	DrawStringToHandle(1225, 400, str3.c_str(), 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);

	return 0;
}

/************************************************
*　りんごのスコア処理
************************************************/
void Apple::ApplePoint(int i)
{
	if (gApple[i].img == Image::GetImages(IMG_APPLE, REDAPPLE)) {//赤りんご
        AppleCount::SetScore(100);
		AppleCount::SetRA(1);
		PlaySoundMem(Sound::GetSounds(SND_SE_APPLE), DX_PLAYTYPE_BACK, TRUE);
	}
	if (gApple[i].img == Image::GetImages(IMG_APPLE, BLUEAPPLE)) {//青りんご
        AppleCount::SetScore(200);
        AppleCount::SetBL(1);
		PlaySoundMem(Sound::GetSounds(SND_SE_APPLE), DX_PLAYTYPE_BACK, TRUE);
	}
	if (gApple[i].img == Image::GetImages(IMG_APPLE, GOLDAPPLE)) {//金りんご
        AppleCount::SetScore(500);
        AppleCount::SetGL(1);
		PlaySoundMem(Sound::GetSounds(SND_SE_APPLE), DX_PLAYTYPE_BACK, TRUE);
	}
	if (gApple[i].img == Image::GetImages(IMG_APPLE, POISONAPPLE)) {//毒りんご
        AppleCount::SetScore(-750);
        AppleCount::SetPO(1);
		if (AppleCount::ReturnScore() < 0) {
            AppleCount::SetScore(0);
		}
		PlaySoundMem(Sound::GetSounds(SND_SE_POISON), DX_PLAYTYPE_BACK, TRUE);
	}
}

/************************************************
*　その他関数
************************************************/

int Apple::ReturnAppleX(int num) {
	return (int)gApple[num].x;
}

int Apple::ReturnAppleY(int num) {
	return (int)gApple[num].y;
}

int Apple::ReturnAppleImg(int num) {
	return gApple[num].img;
}


int Apple::ReturnAppleFlg(int num) {
	return gApple[num].flg;
}

void Apple::GetPlayerX(int xPos) {
	px1 = xPos - 30;
	px2 = xPos + 30;
}

void Apple::GetPlayerY(int yPos) {
	py1 = yPos - 90;
	py2 = yPos + 120;
}

int Apple::GetBlinkFlg() {
	return AppleBlinkFlg;
}

int Apple::SetBlinkFlg(int flg) {
	AppleBlinkFlg = flg;
	return AppleBlinkFlg;
}

//void Apple::GetAppleImgClass(Image& AppleImg){
//   appleimage = AppleImg;
//}

//void Apple::GetFontClass(Font& AppleFont) {
//    applefont = AppleFont;
//}

//void Apple::GetSoundClass(Sound& AppleSound) {
//    applesound = AppleSound;
//}

void Apple::DrawPause() {
    std::string str1 = std::to_string(AppleCount::ReturnRA());
    std::string str2 = std::to_string(AppleCount::ReturnBL());
    std::string str3 = std::to_string(AppleCount::ReturnGL());

    DrawStringToHandle(1020, 400, str1.c_str(), 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);
    DrawStringToHandle(1120, 400, str2.c_str(), 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);
    DrawStringToHandle(1225, 400, str3.c_str(), 0x000000, Font::GetFonts(FONT_1_64), 0xffffff);
}


/************************************************
*　AppleCountClass
************************************************/

int AppleCount::gRACount = 0;
int AppleCount::gBACount = 0;
int AppleCount::gGACount = 0;
int AppleCount::gPACount = 0;
int AppleCount::gScore = 0;

int AppleCount::ReturnRA() {
    return gRACount;
}

int AppleCount::ReturnBL() {
    return gBACount;
}

int AppleCount::ReturnGL() {
    return gGACount;
}

int AppleCount::ReturnPO() {
    return gPACount;
}

int AppleCount::ReturnScore() {
    return (int)gScore;
}

void AppleCount::SetRA(int num) {
    gRACount += num;
}

void AppleCount::SetBL(int num) {
    gBACount += num;
}

void AppleCount::SetGL(int num) {
    gGACount += num;
}

void AppleCount::SetPO(int num) {
    gPACount += num;
}

void AppleCount::SetScore(int num) {
    gScore += num;
}