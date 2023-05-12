// ìF“‡‘Ü

#pragma once
#define _USE_MATH_DEFINES
#define RANKING_DATA 5

void DrawRanking();
void SortRanking(void);
int SaveRanking(void);
int ReadRanking(void);
int GetRankingFlg(void);
void SetRankingState(int flg);

//class Ranking {
//public:
//	int ranking[RANKING_DATA];
//	int score;
//	int number;
//	char name;
//
//};