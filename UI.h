#pragma once

class UI
{
private:
	int gFpsCnt;	//Fps計測
	int gTimeLimit;	//制限時間

public:
	/*
	*関数名：DrawTimeLimit
	*引数なし
	*処理内容
	*制限時間の計測、表示
	*/
	void DrawTimeLimit();
	/*
	*関数名：DrawImg
	*引数なし
	*処理内容
	*りんごの画像を表示する
	*/
	void DrawImg();
	/*
	*関数名：SetUI
	*引数
	* int cnt,int time
	*処理内容
	*変数の初期化
	*/
	void SetUI(int cnt, int time);
};
