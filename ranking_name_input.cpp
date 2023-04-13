// 作：島袋

#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#define RANKING_DATA 5
#include <stdio.h>
//#include "image.h"
#include "ResourceLoad.h"
#include "ranking_name_input.h"

extern Image image;

/********************************
* ランキング入力処理
********************************/
void drawRanking() {
    // 画像の読み込み
    DrawGraph(0, 0, image.title, TRUE);
};







/*
void InputName(void) {

    // ランキング画像表示
    DrawGraph(0, 0, gTitleImg, FALSE);

    // フォントサイズの設定
    SetFontSize(20);

    // 名前入力指示文字列の描画
    DrawString(150, 240, "ランキングに登録します", 0xFFFFFF);
    DrawString(150, 270, "名前を英字で入力してください", 0xFFFFFF);

    // 名前入力
    DrawString(150, 310, "> ", 0xFFFFFF);
    DrawBox(160, 305, 300, 335, 0x000055, TRUE);
    if (KeyInputSingleCharString(170, 310, 10, gRanking[RANKING_DATA - 1].name, FALSE) == 1) {
        gRanking[RANKING_DATA - 1].score = gScore; // ランキングデータにスコア登録
        SortRanking(); // ランキング並び替え
        SaveRanking(); // ランキング保存
        gGameMode = RANKING; // ゲームモード変更
    };
    //gGameMode = TITLE;
};
*/



