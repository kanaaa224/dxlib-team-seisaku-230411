#pragma once

static XINPUT_STATE OldKey;
static XINPUT_STATE NowKey;
static XINPUT_STATE KeyFlg;

void InputController();
int JudgeButton(unsigned char data);
