#include"DxLib.h"
#include"PadInput.h"
#include"player.h"

int Stick;
int FPScount = 0;

void PlayerControll() {
	Stick = GetStickX();	//スティックの状態取得
	//右歩き
	if (Stick > 2000 && Stick < 25000) {
		player.speed = 5;
		FPScount = 0;
	}
	//左歩き
	else if (Stick < -2000 && Stick > -25000) {
		player.speed = -5;
		FPScount = 0;
	}
	//右ダッシュ
	else if (Stick >= 25000) {
		if (FPScount < 30) {
			player.speed += 1;
			FPScount++;
		}
	}
	//左ダッシュ
	else if(Stick <= -25000) {
		if (FPScount < 30) {
			player.speed -= 1;
			FPScount++;
		}
	}
	//立ち止まり
	else{
		player.speed = 0;
		FPScount = 0;
	}

	player.x += player.speed;
	DrawCircle(player.x, player.y, 15, 0xffffff, TRUE);//(仮)
}