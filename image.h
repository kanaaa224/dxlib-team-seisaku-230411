#pragma once
#include "DxLib.h"

// 画像用の構造体
class Image {
public:
	int handle;
	char* filename;
};

// 画像を読み込む関数のプロトタイプ宣言
int LoadImage(Image& image, const char* filename);

// 画像を描画する関数のプロトタイプ宣言
void DrawImage(Image& image, int x, int y);

/*
class IMAGE {
public:

	int Title;

	void print();
};

// メンバー関数（メソッド）の定義と処理
// :: はスコープ演算子
void POS::print() {
	printf("x : %lf y : %lf\n", x, y);
};
*/