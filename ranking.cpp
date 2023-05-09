// 作：島袋

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

#include "DxLib.h"
#include "resourceLoad.h"
#include "ranking_name_input.h"
#include "ranking.h"
#include "Apple.h"
#include <string>
#include "main.h"

extern Image image;
extern Font font;

extern Game game;

extern NameInput nameInput;

using std::string;
using std::to_string;

int gRankingImg;	//ランキング画面背景

//ランキングデータ構造体
struct RankingData {
	int number;
	char name[11];
	long score;
};

//ランキングデータの変数宣言
struct RankingData gRanking[RANKING_DATA];

/********************************
* ランキング
********************************/
void DrawRanking() {

	if (GetRankingFlg() == 1) {
		// スコア書き込み処理
		//gRanking[RANKING_DATA - 1].name = GetInputedName(); String -> Char 変換問題
		gRanking[RANKING_DATA - 1].score = ReturnScore();	// ランキングデータの最下位にスコアを登録
		SortRanking();		// ランキング並べ替え
		SaveRanking();		// ランキングデータの保存
	};

	int RgScore = 0;

	RgScore = ReturnScore();

    // 背景表示
    DrawGraph(0, 0, image.title, TRUE);

    DrawStringToHandle(340, 10, "ランキング", 0x000000, font.handle_1_128, 0xffffff);
 
    // 戻る表示
    DrawStringToHandle(530, 670, "Aボタンでもどる", 0x000000, font.handle_1_32, 0xffffff);

    // 仮
    if (CheckHitKey(KEY_INPUT_R)) {
        game.mode = INPUTNAME;
    };

	// 仮
	if (CheckHitKey(KEY_INPUT_R)) {
		game.mode = END;
	};

    // 背景表示
    DrawGraph(0, 0, image.title, TRUE);

    DrawStringToHandle(340, 10, "ランキング", 0x000000, font.handle_1_128, 0xffffff);
 
    // 戻る表示
    DrawStringToHandle(530, 670, "(仮)RボタンでEND画面へ", 0x000000, font.handle_1_32, 0xffffff);

	SetFontSize(18);
	for (int i = 0; i < RANKING_DATA; i++) {

		DrawFormatStringFToHandle(240, 150 + i * 100, 0x000000, font.handle_1_64, "%2d位 %10s %10d", gRanking[i].number, gRanking[i].name, gRanking[i].score);
	}

};

//ランキング並べ替え
void SortRanking(void)
{
	int i, j;
	RankingData work;

	//選択法ソート
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (gRanking[i].score <= gRanking[j].score) {
				work = gRanking[i];
				gRanking[i] = gRanking[j];
				gRanking[j] = work;
			}
		}
	}

	//順位付け
	for (i = 0; i < RANKING_DATA; i++) {
		gRanking[i].number = 1;
	}
	//得点が同じ場合は、同じ順位とする。
	//同順位があった場合の次の順位はデータ個数が加算された順位とする。
	for (i = 0; i < RANKING_DATA; i++) {
		for (j = i + j; j < RANKING_DATA; j++) {
			if (gRanking[i].score > gRanking[i].score) {
				gRanking[j].number++;
			}
		}
	}
}

//ランキングデータの保存
int SaveRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	//ファイルオープン
	if ((fp = fopen("Resources/dat/rankingdata.txt", "w")) == NULL) {
		/*エラー処理*/
		printf("Ranking Data Error\n");
		return -1;
	}

	//ランキングデータ分配列データを書き込む
	for (int i = 0; i < RANKING_DATA; i++) {
		fprintf(fp, "%2d %10s %10d\n", gRanking[i].number, gRanking[i].name, gRanking[i].score);
	}

	//ファイルクローズ
	fclose(fp);
	return 0;
}

//ランキングデータ読み込み
int ReadRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	//ファイルオープン
	if ((fp = fopen("Resources/dat/rankingdata.txt", "r")) == NULL) {
		//エラー処理
		printf("Ranking Data Error\n");
		return -1;
	}

	//ランキングデータ配分列データを読み込む
	for (int i = 0; i < RANKING_DATA; i++) {
		int dammy = fscanf(fp, "%2d %10s %d10", &gRanking[i].number, gRanking[i].name, &gRanking[i].score);
	}

	//ファイルクローズ
	fclose(fp);

	return 0;
}

/********************************
* スコアがランキング最下位を超えたかの判断を返す関数
********************************/
int GetRankingFlg() {
	// 最下位と現在のスコアを比較
	if (gRanking[RANKING_DATA - 1].score < ReturnScore()) {
		return 1;
	}
	else {
		return 0;
	}
	//return gRanking;
};