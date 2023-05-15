#include"DxLib.h"
#include"PadInput.h"

static XINPUT_STATE OldKey;
static XINPUT_STATE NowKey;
static XINPUT_STATE KeyFlg;

//コントローラー入力を取得
void PAD_INPUT::InputController() {
	for (int i = 0; i < 16; i++) {
		OldKey.Buttons[i] = NowKey.Buttons[i];
	}
	GetJoypadXInputState(DX_INPUT_PAD1, &NowKey);
	for (int i = 0; i < 16; i++) {
		KeyFlg.Buttons[i] = NowKey.Buttons[i] & ~OldKey.Buttons[i];     //XINPUTはクラスで管理されている
	}
	SetFontSize(16);
	DrawFormatString(390, 100, 0xffffff, "%d",  NowKey.ThumbLX);
}

//ボタンが押されているかの判定
int PAD_INPUT::JudgeButton(unsigned char data) {
	if (/*KeyFlg.Buttons[data] & data*/OldKey.Buttons[data] == 0 && NowKey.Buttons[data] == 1) {
		return 1;
	}
	else{
		return 0;
	}
}

//ボタンを離した時の判定
int PAD_INPUT::JudgeReleaseButton(unsigned char data) {
	if (OldKey.Buttons[data] == 1 && NowKey.Buttons[data] == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

//左スティックの状態の取得
int PAD_INPUT::GetStickX() {
	return NowKey.ThumbLX;
}
int PAD_INPUT::GetStickY() {
	return NowKey.ThumbLY;
}