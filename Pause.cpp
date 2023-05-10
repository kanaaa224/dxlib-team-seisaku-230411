#include "Pause.h"

int PauseFlg = 0; //‚P‚È‚çƒ|[ƒY’†‚O‚È‚ç’Êí

int GetPauseFlg() {
	return PauseFlg;
}

int SetPauseFlg(int num) {
	PauseFlg = num;
	return PauseFlg;
}