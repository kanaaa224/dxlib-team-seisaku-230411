// 作：島袋

#define _USE_MATH_DEFINES
#include <math.h>
#define RANKING_DATA 5
#include <stdio.h>

#include "DxLib.h"
#include "resourceLoad.h"
#include "ranking.h"
#include "main.h"

extern Image image;
extern Font font;

extern Game game;

/********************************
* ランキング
********************************/
void DrawRanking() {
    DrawGraph(0, 0, image.title, TRUE);
    DrawStringToHandle(340, 140, "ランキング", 0x000000, font.handle_1_32, 0xffffff);
    DrawStringToHandle(340, 180, "rでランキング入力画面へ", 0x000000, font.handle_1_32, 0xffffff);
    DrawStringToHandle(340, 220, "escでtitleへ", 0x000000, font.handle_1_32, 0xffffff);

    if (CheckHitKey(KEY_INPUT_R)) {
        game.mode = INPUTNAME;
    };

    if (CheckHitKey(KEY_INPUT_ESCAPE)) {
        game.mode = TITLE;
    };

    // ファイル読み込み対応
    // パッド対応
};

