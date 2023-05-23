/********************************
* リソース管理処理
* 作者：島袋
********************************/
#include "DxLib.h"
#include "resourceLoad.h"

/********************************
* 画像を読み込む
********************************/
int Image::title = 0;
int Image::controller = 0;
int Image::apple[] = { 0 };
int Image::walk[] = { 0 };
int Image::run[] = { 0 };
int Image::stop[] = { 0 };

int Image::LoadImages(void) {
	if ((title = LoadGraph("Resources/Images/title.png")) == -1) return -1;

	if ((controller = LoadGraph("Resources/Images/controller.png")) == -1) return -1;

	if ((apple[0] = LoadGraph("Resources/Images/REDApple.png")) == -1) return -1;
	if ((apple[1] = LoadGraph("Resources/Images/BLUEApple.png")) == -1) return -1;
	if ((apple[2] = LoadGraph("Resources/Images/GOLDApple.png")) == -1) return -1;
	if ((apple[3] = LoadGraph("Resources/Images/POISONApple.png")) == -1) return -1;

	LoadDivGraph("Resources/Images/Walk.png", 3, 3, 1, 300, 300, walk);
	LoadDivGraph("Resources/Images/Run.png", 8, 4, 2, 300, 300, run);

	stop[0] = LoadGraph("Resources/Images/Stop.png");
	stop[1] = LoadGraph("Resources/Images/Stop2.png");

	return 0;
};

/********************************
* 画像を取得する関数
********************************/
int Image::GetImages(int num, int arrayNum) {
	switch (num) {
	case IMG_TITLE:
		return title;

	case IMG_CONTROLLER:
		return controller;

	case IMG_APPLE:
		return apple[arrayNum];

	case IMG_WALK:
		return walk[arrayNum];

	case IMG_RUN:
		return run[arrayNum];

	case IMG_STOP:
		return stop[arrayNum];
	};
};


/********************************
* サウンドを読み込む
********************************/
int Sound::bgm_main = 0;
int Sound::bgm_sub = 0;
int Sound::se_apple = 0;
int Sound::se_poison = 0;
int Sound::se_cursor = 0;
int Sound::se_select = 0;

int Sound::LoadSounds(void) {
	if ((bgm_main = LoadSoundMem("Resources/BGM/Natural_Green.wav")) == -1) return -1;
	if ((bgm_sub = LoadSoundMem("Resources/BGM/BGM_Odayaka.wav")) == -1) return -1;

	if ((se_apple = LoadSoundMem("Resources/SE/Apple.wav")) == -1) return -1;
	if ((se_poison = LoadSoundMem("Resources/SE/PoisonApple.wav")) == -1) return -1;

	if ((se_cursor = LoadSoundMem("Resources/SE/btn02.wav")) == -1) return -1;
	if ((se_select = LoadSoundMem("Resources/SE/btn10.wav")) == -1) return -1;

	ChangeVolumeSoundMem(97, bgm_main);
    ChangeVolumeSoundMem(150, bgm_sub);

	ChangeVolumeSoundMem(400, se_apple);
	ChangeVolumeSoundMem(450, se_poison);
	
	ChangeVolumeSoundMem(170, se_cursor);
	ChangeVolumeSoundMem(150, se_select);

	return 0;
};

/********************************
* サウンドを取得する関数
********************************/
int Sound::GetSounds(int num) {
    switch (num) {
    case SND_BGM_MAIN:
        return bgm_main;

    case SND_BGM_SUB:
        return bgm_sub;

    case SND_SE_APPLE:
        return se_apple;

    case SND_SE_POISON:
        return se_poison;

    case SND_SE_CURSOR:
        return se_cursor;

    case SND_SE_SELECT:
        return se_select;
    };
};


/********************************
* フォントを読み込む
********************************/
int Font::handle_0_128 = 0;

int Font::LoadFonts(void) {
	LPCSTR font_path = "Resources/Fonts/syokakiutage.ttf"; // 読み込むフォントファイルのパス
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) < 0) {
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	};

    handle_0_128 = CreateFontToHandle(NULL, 128, -1, DX_FONTTYPE_NORMAL);
    handle_0_64 = CreateFontToHandle(NULL, 64, -1, DX_FONTTYPE_NORMAL);
    handle_0_16 = CreateFontToHandle(NULL, 16, -1, DX_FONTTYPE_NORMAL);
    handle_0_32 = CreateFontToHandle(NULL, 32, -1, DX_FONTTYPE_NORMAL);

    handle_1_128 = CreateFontToHandle("しょかきうたげ（無料版）", 128, 9, DX_FONTTYPE_EDGE);
    handle_1_64 = CreateFontToHandle("しょかきうたげ（無料版）", 64, 9, DX_FONTTYPE_EDGE);
    handle_1_32 = CreateFontToHandle("しょかきうたげ（無料版）", 32, 9, DX_FONTTYPE_EDGE);
    handle_1_16 = CreateFontToHandle("しょかきうたげ（無料版）", 16, 9, DX_FONTTYPE_EDGE);
    //font.handle_3_ // 追加フォントのパスとサイズ

	//if ((font.s = LoadFont("Resources/Fonts/syokakiutage.ttf")) == -1) return -1;

	return 0;
};

/********************************
* フォントを取得する関数
********************************/
int Font::GetFonts(int num) {
    switch (num) {
    case FONT_0_128:
        return handle_0_128;
    };
};
