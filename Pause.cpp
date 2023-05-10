#include "Pause.h"

int PauseFlg = 0;

int GetPauseFlg() {
	return PauseFlg;
}

int SetPauseFlg(int num) {
	PauseFlg = num;
	return PauseFlg;
}