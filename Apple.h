#pragma once

#ifndef APPLE_H
#define APPLE_H

//マクロ定義
#define REDAPPLE 0
#define BLUEAPPLE 1
#define GOLDAPPLE 2
#define POISONAPPLE 3

#define LINE_NUM 7

//型定義

/************************************************
*　構造体
************************************************/
static struct APPLE {
	int flg;			//使用フラグ
	int img;			//画像
	double x, y, w, h;	//座標、幅、高さ
	double speed;		//移動速度
	int point;			//スコア加算ポイント
};

static struct APPLE gApple[10];

//プロトタイプ宣言
//int LoadImges(void);		//画像読込
void FallApple(void);		//リンゴ落下処理
int CreateApple(void);		//リンゴ生成
void AppleSpeed(int i);		//りんごの速度
//void AppleInit(void);		//リンゴの変数の初期化
int HitBox(void);
int HitBoxPlayer(void);
void ApplePoint(int i);		//りんごのスコア処理
int ReturnRA(void);			//gRACountがリザルト画面で使用したいので
int ReturnBL(void);
int ReturnGL(void);
int ReturnPO(void);
int ReturnScore(void);
int ReturnAppleX(int num);
int ReturnAppleY(int num);
int ReturnAppleImg(int num);

#endif