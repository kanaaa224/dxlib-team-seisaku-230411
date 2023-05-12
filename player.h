#pragma once

#define WALK_RIGHT 2000		//スティックの傾き具合から
#define RUN_RIGHT 25000		//プレイヤーの
#define WALK_LEFT -2000		//状態を
#define RUN_LEFT -25000		//取得

#define MOVE_LEFT_LIMIT 30		//プレイヤーの
#define MOVE_RIGHT_LIMIT 970	//移動制限

#define WALK_SPEED 1	//歩きのスピード
#define SPEED_UP 0.2		//加速度
#define SPEED_UP1 0.2		//加速度
#define IMAGE_RATE 0.9f	//プレイヤー画像の拡大率


class PLAYER
{
private:
	int flg;
	float x;
	int y;
	float speed;
	int BlinkFlg;

public:
	

	//プレイヤーの移動制限
	//プレイヤーが左または右端出会った場合１を返す
	//移動可能であった場合０を返しplayer.xにplayer.speedを加算する
	int PlayerLimit();

	//プレイヤーの操作
	void PlayerControll();
	//プレイヤーの描画
	void DrawPlayer();
	//ポーズ中のプレイヤーの描画
	void DrawPlayerPause();



	//プレイヤーのX座標を取得
	//戻り値でプレイヤーのX座標を返す
	int ReturnPlayerX();

	//プレイヤーのY座標を取得
	//戻り値でプレイヤーのY座標を返す
	int ReturnPlayerY();

	//プレイヤーのX座標を設定
	//引数で与えられた値をX座標に設定
	void SetPlayerX(int xPos);

	//毒リンゴ取得時の点滅
	//引数で与えられた値をBlinkFlgに設定（TRUE or FALSE）
	void SetPlayerBlinkFlg(int x);

	void SetPlayerFlg(int Pflg);
	int GetPlayerBlinkFlg();

	PLAYER();
};

