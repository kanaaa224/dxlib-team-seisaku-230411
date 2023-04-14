// ìF“‡‘Ü

#pragma once

class Resourceload {
public:
	int state;
};

class Image {
public:
	int title;
	int apple;
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
	int handle_1;
};

int ResourceLoad(void);
