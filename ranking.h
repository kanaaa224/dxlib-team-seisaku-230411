// 作：島袋

#pragma once
#define _USE_MATH_DEFINES
#define RANKING_DATA 5


//int RgScore = 0;
//
////ランキングデータ構造体
//struct RankingData {
//	int number;
//	char name[11];
//	long score;
//};
//
////ランキングデータの変数宣言
//struct RankingData gRanking[RANKING_DATA];

void DrawRanking();
void SortRanking(void);
int SaveRanking(void);
int ReadRanking(void);

class Ranking {
public:
	int score;
	int number;
	char name;

};