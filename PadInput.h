#pragma once
#include"DxLib.h"

class PAD_INPUT {
private:
	/*static XINPUT_STATE OldKey;
	static XINPUT_STATE NowKey;
	static XINPUT_STATE KeyFlg;*/
public:
	static void InputController();		//コントローラーの入力
	static int JudgeButton(unsigned char data);		//ボタンの入力
	static int JudgeReleaseButton(unsigned char data);		//ボタンを離したとき
	static int GetStickX();		//左スティックのX軸
	static int GetStickY();		//左スティックのY軸
};


	