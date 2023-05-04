#pragma once
class UI
{
public:
	int Apple[4];
	int AppleScore[4];
	int SetScore[4];
};

static int gFpsCnt;
static int gTimeLimit;
void DrawUserInterFace();
void DrawTimeLimit();
void DrawCnt();
void SetUI(int cnt,int time);
