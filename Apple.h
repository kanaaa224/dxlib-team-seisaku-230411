#pragma once

#ifndef APPLE_H
#define APPLE_H

//マクロ定義
#define APPLE_MAX 10; //リンゴの画面内の最大数

//型定義

struct Apple
{
	int flg;			//使用フラグ
	int type;			//タイプ
	int img;			//画像
	int x, y, w, h;		//座標、幅、高さ
	int speed;			//移動速度
	int point;			//スコア加算ポイント
};

typedef enum
{
	Apple_ID_Red = 0,
	Apple_ID_Blue,
	Apple_ID_Gold,
	Apple_ID_Poison,
	//-----------------------------
	E_Apple_ID_END,//番兵
}Apple_ID;

//プロトタイプ宣言
int CreateApple(void);	//リンゴ生成処理
int FallAplle(void);	//リンゴ落下処理

#endif