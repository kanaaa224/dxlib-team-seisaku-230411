// çÏÅFìáë‹

#pragma once

#define IMG_TITLE 0
#define IMG_APPLE 1
#define IMG_WALK 2
#define IMG_RUN 3
#define IMG_STOP 4
#define IMG_CONTROLLER 5

#define SND_BGM_MAIN 0
#define SND_BGM_SUB 1
#define SND_SE_APPLE 2
#define SND_SE_POISON 3
#define SND_SE_CURSOR 4
#define SND_SE_SELECT 5

#define FONT_0_128 0
#define FONT_0_64 1
#define FONT_0_32 2
#define FONT_0_16 3
#define FONT_1_128 4
#define FONT_1_64 5
#define FONT_1_32 6
#define FONT_1_16 7

class Image {
private:
	static int title;
	static int apple[20];
	static int walk[3];
	static int run[8];
	static int stop[2];
	static int controller;
public:
	int LoadImages(void);
	static int GetImages(int, int);
};

class Sound {
private:
    static int bgm_main;
    static int bgm_sub;
    static int se_apple;
    static int se_poison;
    static int se_cursor;
    static int se_select;
public:
	int LoadSounds(void);
    static int GetSounds(int);
};

class Font {
private:
	static int handle_0_128;
    static int handle_0_64;
    static int handle_0_32;
    static int handle_0_16;
    static int handle_1_128;
    static int handle_1_64;
    static int handle_1_32;
    static int handle_1_16;
public:
	int LoadFonts(void);
    static int GetFonts(int);
};
