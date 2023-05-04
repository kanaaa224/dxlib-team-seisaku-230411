#include"DxLib.h"
#include"resourceLoad.h"
#include"PadInput.h"
#include"player.h"
#include"Apple.h"

int Stick;
int FPScount = 0;
extern Image image;
int Run = 0;
int Walk = 0;
int FPS = 0;
struct PLAYER player;

void PlayerControll() {
	Stick = GetStickX();	//スティックの状態取得

	PlayerLimit();

	//右歩き
	if (Stick > WALK_RIGHT && Stick < RUN_RIGHT) {
		if (PlayerLimit() == 0) {
			if (player.speed < WALK_SPEED) {
				player.speed += 0.5;
			}
			else{
				player.speed = WALK_SPEED;
			}
		}
		FPScount = 0;
	}
	//左歩き
	else if (Stick < WALK_LEFT && Stick > RUN_LEFT) {
		if (PlayerLimit() == 0) {
			if (player.speed > WALK_SPEED * -1) {
				player.speed -= 0.5;
			}
			else {
				player.speed = WALK_SPEED * -1;
			}
			
		}
		FPScount = 0;
	}
	//右ダッシュ
	else if (Stick >= RUN_RIGHT) {
		if (PlayerLimit() == 0) {
			if (player.speed < 3) {
				player.speed += 0.5;
			}
			else {
				if (FPScount < 10 && FPScount % 5 == 0) {
					player.speed += SPEED_UP;
				}
				FPScount++;
			}
		}
	}
	//左ダッシュ
	else if(Stick <= RUN_LEFT) {
		if (PlayerLimit() == 0) {
			if (player.speed > -3 ) {
				player.speed -= 0.5;
			}
			else {
				if (FPScount < 20 && FPScount % 10 == 0) {
					player.speed -= SPEED_UP;
				}
				FPScount++;
			}
		}
	}
	//立ち止まり
	else{
		if (PlayerLimit() == 0) {
			//慣性
			if (player.speed != 0 && player.speed > 0) {
				player.speed -= 0.5;
			}
			else if (player.speed != 0 && player.speed < 0) {
				player.speed += 0.5;
			}
			else {
				player.speed = 0;
				FPScount = 0;
			}
		}
	}

	
	DrawFormatString(100, 200, 0xffffff, "%d", player.x);
	DrawCircle(player.x, player.y, 15, 0xffffff, TRUE);//(仮)
	//DrawRotaGraph(player.x, player.y, 0.45f, 0,image.player[5] , TRUE, FALSE);
	DrawFormatString(390, 30, 0xffffff, "%d", player.x);
	DrawFormatString(390, 60, 0xffffff, "%f", player.speed);
}

int PlayerLimit() {
	//プレイヤーの移動制限
	if (player.x < MOVE_LEFT_LIMIT) {
		player.speed = 0;
		player.x = MOVE_LEFT_LIMIT;
		return 1;
	}
	else if (player.x > MOVE_RIGHT_LIMIT) {
		player.speed = 0;
		player.x = MOVE_RIGHT_LIMIT;
		return 1;
	}
	else {
		player.x += player.speed;
		
		return 0;
	}
}

void DrawPlayer() {

	if (player.speed > 0 && player.speed < 3 && player.x != MOVE_RIGHT_LIMIT) {
		if (FPS % 10 == 0) {
			Walk++;
			if (Walk > 2) {
				Walk = 0;
			}
		}
		DrawRotaGraph(player.x, player.y, IMAGE_RATE, 0, image.Walk[Walk], TRUE, TRUE);
	}
	else if (player.speed > 3 && player.x != MOVE_RIGHT_LIMIT) {
		if (FPS % 5 == 0) {
			Run += 2;
			if (Run > 7) {
				Run = 0;
			}
		}
		DrawRotaGraph(player.x, player.y, IMAGE_RATE, 0, image.Run[Run], TRUE, TRUE);

	}
	else if (player.speed < 0 && player.speed > -3 && player.x != MOVE_LEFT_LIMIT) {
		if (FPS % 10 == 0) {
			Walk++;
			if (Walk > 2) {
				Walk = 0;
			}
		}
		DrawRotaGraph(player.x, player.y, IMAGE_RATE, 0, image.Walk[Walk], TRUE, FALSE);
	}
	else if (player.speed < -2 && player.x != MOVE_LEFT_LIMIT) {
		if (FPS % 5 == 0) {
			Run += 2;
			if (Run > 7) {
				Run = 0;
			}
		}
		DrawRotaGraph(player.x, player.y, IMAGE_RATE, 0, image.Run[Run], TRUE, FALSE);
	}
	else if ((Stick < 500 && Stick > -500) || player.x <= MOVE_LEFT_LIMIT || player.x >= MOVE_RIGHT_LIMIT) {
		DrawRotaGraph(player.x, player.y, IMAGE_RATE, 0, image.Stop[0], TRUE, FALSE);
    }
	else {
		DrawRotaGraph(player.x, player.y, IMAGE_RATE, 0, image.Stop[1], TRUE, FALSE);
	}
	FPS++;
	HitBoxPlayer();
}

void DrawPlayerPause() {

	if (player.speed > 0 && player.speed < 3 && player.x != MOVE_RIGHT_LIMIT) {
		DrawRotaGraph(player.x, player.y, IMAGE_RATE, 0, image.Walk[Walk], TRUE, TRUE);
	}
	else if (player.speed > 3 && player.x != MOVE_RIGHT_LIMIT) {
		DrawRotaGraph(player.x, player.y, IMAGE_RATE, 0, image.Run[Run], TRUE, TRUE);

	}
	else if (player.speed < 0 && player.speed > -3 && player.x != MOVE_LEFT_LIMIT) {
		DrawRotaGraph(player.x, player.y, IMAGE_RATE, 0, image.Walk[Walk], TRUE, FALSE);
	}
	else if (player.speed < -2 && player.x != MOVE_LEFT_LIMIT) {
		DrawRotaGraph(player.x, player.y, IMAGE_RATE, 0, image.Run[Run], TRUE, FALSE);
	}
	else if ((Stick < 500 && Stick > -500) || player.x <= MOVE_LEFT_LIMIT || player.x >= MOVE_RIGHT_LIMIT) {
		DrawRotaGraph(player.x, player.y, IMAGE_RATE, 0, image.Stop[0], TRUE, FALSE);
	}
	else {
		DrawRotaGraph(player.x, player.y, IMAGE_RATE, 0, image.Stop[1], TRUE, FALSE);
	}
}


int ReturnPlayerX() {
	return player.x;
}
int ReturnPlayerY() {
	return player.y;
}

void SetPlayerX(int x) {
	player.x = x;
}
