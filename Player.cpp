#include"DxLib.h"
#include"PadInput.h"
#include"player.h"

int Stick;
int FPScount = 0;

void PlayerControll() {
	Stick = GetStickX();	//スティックの状態取得
	//右歩き
	if (Stick > WALK_RIGHT && Stick < RUN_RIGHT) {
		player.speed = WALK_SPEED;
		FPScount = 0;
	}
	//左歩き
	else if (Stick < WALK_LEFT && Stick > RUN_LEFT) {
		player.speed = WALK_SPEED * -1;
		FPScount = 0;
	}
	//右ダッシュ
	else if (Stick >= RUN_RIGHT) {
		if (FPScount < 30) {
			player.speed += SPEED_UP;
			FPScount++;
		}
	}
	//左ダッシュ
	else if(Stick <= RUN_LEFT) {
		if (FPScount < 30) {
			player.speed -= SPEED_UP;
			FPScount++;
		}
	}
	//立ち止まり
	else{
		player.speed = 0;
		FPScount = 0;
	}

	//プレイヤーの移動制限
	if (player.x <= MOVE_LEFT_LIMIT) {
		player.x = MOVE_LEFT_LIMIT;
	}
	else if (player.x >= MOVE_RIGHT_LIMIT) {
		player.x = MOVE_RIGHT_LIMIT;
	}
	else{
		player.x += player.speed;
	}
	
	DrawCircle(player.x, player.y, 15, 0xffffff, TRUE);//(仮)
}