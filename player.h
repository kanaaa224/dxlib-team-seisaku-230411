#pragma once

#define WALK_RIGHT 2000
#define RUN_RIGHT 25000
#define WALK_LEFT -2000
#define RUN_LEFT -25000
#define MOVE_LEFT_LIMIT 10
#define MOVE_RIGHT_LIMIT 1000
#define WALK_SPEED 2
#define SPEED_UP 1

struct PLAYER
{
	int flg;
	int x=600;
	int y=600;
	float speed = 0;
};

static struct PLAYER player;

void PlayerControll(void);
int PlayerLimit(int x);
void DrawPlayer();
int ReturnPlayerX();
int ReturnPlayerY();
