#include"DxLib.h"
#include"PadInput.h"

//コントローラー入力を取得
void InputController() {
	for (int i = 0; i < 16; i++) {
		OldKey.Buttons[i] = NowKey.Buttons[i];
	}
	GetJoypadXInputState(DX_INPUT_PAD1, &NowKey);
	for (int i = 0; i < 16; i++) {
		KeyFlg.Buttons[i] = NowKey.Buttons[i] & ~OldKey.Buttons[i];     //XINPUTは構造体で管理されている
	}
	SetFontSize(16);
	DrawFormatString(390, 100, 0xffffff, "%d",  NowKey.ThumbLX);
}

//ボタンが押されているかの判定
int JudgeButton(unsigned char data) {
	if (KeyFlg.Buttons[data]) {
		return 1;
	}
	else{
		return 0;
	}
}

//ボタンを離した時の判定
int JudgeReleaseButton(unsigned char data) {
	if (OldKey.Buttons[data] == 1 && NowKey.Buttons[data] == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

//左スティックの状態の取得
int GetStickX() {
	return NowKey.ThumbLX;
}
int GetStickY() {
	return NowKey.ThumbLY;
}