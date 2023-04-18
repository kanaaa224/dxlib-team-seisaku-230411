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

int ResourceLoad(void);
