// ìF“‡‘Ü

#pragma once

#define TITLE 0
#define INIT 1
#define MAIN 2
#define HELP 3
#define RESULT 4
#define INPUTNAME 5
#define RANKING 6
#define END 7
#define TEST 8
#define EXIT 99

class Image {
public:
	static int title;
	int apple[20];
	int Walk[3];
	int Run[8];
	int Stop[2];
	int end;
	int controller;
	int controller_s;
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
	//int s;
	int state;
	int handle_0_128;
	int handle_0_64;
	int handle_0_32;
	int handle_0_16;
	int handle_1_128;
	int handle_1_64;
	int handle_1_32;
	int handle_1_16;
	//int handle_2_128;
	//int handle_2_64;
	//int handle_2_32;
public:
	int LoadFonts(void);
};
