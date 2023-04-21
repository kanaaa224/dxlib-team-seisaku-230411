// ìF“‡‘Ü

#pragma once

class Resourceload {
public:
	int state;
};

class Image {
public:
	int title;
	int apple[20];
	int player[16];
	int Walk[3];
	int Run[8];
	int Stop;
	int end;
	int controller;
	int controller_s;
};

class Sound {
public:
	int bgm;
	int se_1;
};

class Font {
public:
	int s;
	int state;
	int handle_1_128;
	int handle_1_64;
	int handle_1_32;
};

class ChageFont {
public:
	int state;
};

int ResourceLoad(void);

int ChangeFontSize(int size);