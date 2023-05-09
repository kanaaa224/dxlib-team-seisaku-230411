#pragma once

#define WALK_RIGHT 2000
#define RUN_RIGHT 25000
#define WALK_LEFT -2000
#define RUN_LEFT -25000
#define MOVE_LEFT_LIMIT 30
#define MOVE_RIGHT_LIMIT 970
#define WALK_SPEED 1
#define SPEED_UP 1
#define IMAGE_RATE 0.9f

struct PLAYER
{
	int flg = TRUE;
	int x;
	int y = 600;
	float speed = 0;
};




void PlayerControll(void);
int PlayerLimit();
void DrawPlayer();
void DrawPlayerPause();
int ReturnPlayerX();
int ReturnPlayerY();
void SetPlayerX(int x);
void SetPlayerBlinkFlg(int x);
