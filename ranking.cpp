// 作：島袋

#define _USE_MATH_DEFINES
#define RANKING_DATA 5
#include <stdio.h>
#include <math.h>

#include "DxLib.h"
#include "resourceLoad.h"

#include "main.h"

extern Image image;
extern Font font;

extern Game game;

/********************************
* ランキング
********************************/
void DrawRanking() {
    // 背景表示
    DrawGraph(0, 0, image.title, TRUE);

    // タイトル
    DrawStringToHandle(370, 40, "ランキング", 0x000000, font.handle_1_128, 0xffffff);

    // 本文
    DrawStringToHandle(340, 180, "rでランキング入力画面へ", 0x000000, font.handle_1_32, 0xffffff);

    // 戻る表示
    DrawStringToHandle(530, 670, "Aボタンでもどる", 0x000000, font.handle_1_32, 0xffffff);

    // 仮
    if (CheckHitKey(KEY_INPUT_R)) {
        game.mode = INPUTNAME;
    };

    // 仮
    if (CheckHitKey(KEY_INPUT_ESCAPE)) {
        game.mode = TITLE;
    };

    // ファイル読み込み対応
    // パッド対応
};
