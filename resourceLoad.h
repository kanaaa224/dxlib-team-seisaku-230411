// ìF“‡‘Ü

#pragma once

#define IMG_TITLE 0
#define IMG_APPLE 1
#define IMG_WALK 2
#define IMG_RUN 3
#define IMG_STOP 4
#define IMG_CONTROLLER 5

class Image {
private:
	static int title;
	static int apple[20];
	static int Walk[3];
	static int Run[8];
	static int Stop[2];
	static int controller;
public:
	int LoadImages(void);
	static int GetImages(int, int);
};

class Sound {
public:
	int mainbgm;
	int subbgm;
	int se_apple;
	int se_poisonapple;
	int se_corsor;
	int se_selct;
public:
	int LoadSounds(void);
};

class Font {
public:
	int state;
	int handle_0_128;
	int handle_0_64;
	int handle_0_32;
	int handle_0_16;
	int handle_1_128;
	int handle_1_64;
	int handle_1_32;
	int handle_1_16;
public:
	int LoadFonts(void);
};
