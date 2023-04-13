#pragma once

struct PLAYER
{
	int flg;
	int x=600;
	int y=600;
	int speed=5;
};

static struct PLAYER player;

void PlayerControll(void);