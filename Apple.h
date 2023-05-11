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
*豊元一成 
*void FallApple(void)
*りんごの落下処理
*引数	：なし
*戻り値	：なし
*/
void FallApple(void);

/**
*豊元一成 
*int CreateApple(void)
*りんごの生成とりんごの確率処理
*引数	：なし
*戻り値	：int型
*戻り値はりんごの生成が成功した場合TRUE、失敗した場合FALSEがgAppleのflgに入る
*/
int CreateApple(void);

/**
*豊元一成 
*void AppleSpeed(int i)
*りんごの落下速度
*引数	：int型 i
*戻り値	：なし
*CreateApple関数から入ってくる関数
*引数にはCreateApple関数から取ってきたgAppleの配列番号が入っている
*/
void AppleSpeed(int i);

/**
*void AppleInit(int num)
*りんごのカウント変数とスコアの初期化
*引数	：int型 num
*戻り値	：なし
*/
void AppleInit();

/**
* 北村隼士
*int HitBox(void)
*りんごの当たり判定処理
*引数	：なし
*戻り値	：int型　
*/
int HitBox(void);

/*
* 北村隼士
*int HitBoxPlayer(void)
*りんごの当たり判定処理
*引数	：なし
*戻り値	：int型　
*/
int HitBoxPlayer(void);

/**
*豊元一成
*void ApplePoint(int i)
*りんごのスコア＆個数をカウント処理
*引数	：int型
*戻り値	：なし
*引数でgAppleの配列番号をHitBoxPlayerから取ってきて、りんごの種類別にスコアと個数を入れる
*/
void ApplePoint(int i);

/**
* 新里滉規
*int ReternRA(void)
*赤りんごの個数を返す
*引数	：int型
*戻り値	：int型　
*/
int ReturnRA(void);

/**
* 新里滉規
*int ReternBL(void)
*青りんごの個数を返す
*引数	：int型
*戻り値	：int型　
*/
int ReturnBL(void);

/**
* 新里滉規
*int ReternGL(void)
*金りんごの個数を返す
*引数	：int型
*戻り値	：int型　
*/
int ReturnGL(void);

/**
* 新里滉規
*int ReternPO(void)
*毒りんごの個数を返す
*引数	：int型
*戻り値	：int型　
*/
int ReturnPO(void);

/**
* 新里滉規
*int ReternRA(void)
*スコアを返す
*引数	：int型
*戻り値	：int型　
*/
int ReturnScore(void);

/**
* 北村隼士
*int ReternAppleX(int num)
*りんごのX座標を返す
*引数	：int型
*戻り値	：int型　
*/
int ReturnAppleX(int num);

/**
* 北村隼士
*int ReternAppleY(int num)
*りんごのY座標を返す
*引数	：int型
*戻り値	：int型　
*/
int ReturnAppleY(int num);

/**
* 北村隼士
*int ReternAppleImg(int num)
*りんごのImgを返す
*引数	：int型
*戻り値	：int型　
*/
int ReturnAppleImg(int num);

/**
* 北村隼士
*int ReternAppleFlg(int num)
*りんごのFlgを返す
*引数	：int型
*戻り値	：int型　
*/
int ReturnAppleFlg(int num);

/**
* 北村隼士
*void SetAppleCount(int num)
*
*引数	：なし
*戻り値	：int型　
*/
void SetAppleCount(int num);










void GetPlayerX(int xPos);
void GetPlayerY(int yPos);
int GetBlinkFlg();
int SetBlinkFlg(int flg);
#endif