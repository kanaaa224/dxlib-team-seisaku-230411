#pragma once

#ifndef APPLE_H
#define APPLE_H

//マクロ定義
#define REDAPPLE 0		//画像の配列番号（赤りんご）
#define BLUEAPPLE 1		//画像の配列番号（青りんご）
#define GOLDAPPLE 2		//画像の配列番号（金りんご）
#define POISONAPPLE 3	//画像の配列番号（毒りんご）

//型定義

/************************************************
*　変数の宣言（グローバル変数:Apple.cpp内）
************************************************/
//int gAppleImg[20];	//りんごの画像変数
extern int gP;			//りんごの確率

extern int gOldTime;	//前時間（前時間と後時間を比較してりんごが表示されてから何秒たった計測する変数
extern int gNowTime;	//後時間（前時間と後時間を比較してりんごが表示されてから何秒たった計測する変数
extern int gTimeFlg;	//時間計測用の変数

extern int gFPSCount;

extern int gRACount;	//赤りんごの個数
extern int gBACount;	//青りんごの個数
extern int gGACount;	//金りんごの個数
extern int gPACount;	//毒りんごの個数
extern int gScore;		//スコア

/************************************************
*　定数の宣言
************************************************/
const int APPLE_MAX = 10;//りんごの最大個数

/************************************************
*　構造体
************************************************/
struct APPLE {
	int flg;			//使用フラグ
	int img;			//画像
	double x, y, w, h;	//座標、幅、高さ
	double speed;		//移動速度
	int point;			//スコア加算ポイント
};

static struct APPLE gApple[10];

//プロトタイプ宣言

/**
*void FallApple(void)
*りんごの落下処理
*引数	：なし
*戻り値	：なし
*/
void FallApple(void);

/**
*int CreateApple(void)
*りんごの生成とりんごの確率処理
*引数	：なし
*戻り値	：int型
*戻り値はりんごの生成が成功した場合TRUE、失敗した場合FALSEがgAppleのflgに入る
*/
int CreateApple(void);

/**
*void AppleSpeed(int i)
*りんごの落下速度
*引数	：int型 i
*戻り値	：なし
*CreateApple関数から入ってくる関数
*引数にはCreateApple関数から取ってきたgAppleの配列番号が入っている
*/
void AppleSpeed(int i);		//りんごの速度

void AppleInit(int num);	//リンゴの変数の初期化
int HitBox(void);			//りんごの当たり判定
int HitBoxPlayer(void);		//プレイヤーの当たり判定

void ApplePoint(int i);		//りんごのスコア処理

int ReturnRA(void);			//gRACountがリザルト画面で使用したいので
int ReturnBL(void);
int ReturnGL(void);
int ReturnPO(void);
int ReturnScore(void);
int ReturnAppleX(int num);
int ReturnAppleY(int num);
int ReturnAppleImg(int num);
int ReturnAppleFlg(int num);
void SetAppleCount(int num);




#endif