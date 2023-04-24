#pragma once
class UI
{
public:
	int Apple[4];
	int AppleScore[4];
	int SetScore[4];
};

static int gFpsCnt = 0;

void DrawUserInterFace();
void DrawTimeLimit();
void DrawCnt();