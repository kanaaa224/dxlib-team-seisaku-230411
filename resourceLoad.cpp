// 作：島袋

#include "DxLib.h"
#include "resourceLoad.h"

//Image image;
//Sound sound;
//Font font;

/********************************
* 画像を読み込む
********************************/
int Image::title = 0;
int Image::controller = 0;
int Image::apple[] = { 0 };
int Image::Walk[] = { 0 };
int Image::Run[] = { 0 };
int Image::Stop[] = { 0 };

int Image::LoadImages(void) {
	if ((title = LoadGraph("Resources/Images/title.png")) == -1) return -1;

	if ((controller = LoadGraph("Resources/Images/controller.png")) == -1) return -1;

	if ((apple[0] = LoadGraph("Resources/Images/REDApple.png")) == -1) return -1;
	if ((apple[1] = LoadGraph("Resources/Images/BLUEApple.png")) == -1) return -1;
	if ((apple[2] = LoadGraph("Resources/Images/GOLDApple.png")) == -1) return -1;
	if ((apple[3] = LoadGraph("Resources/Images/POISONApple.png")) == -1) return -1;

	LoadDivGraph("Resources/Images/Walk.png", 3, 3, 1, 300, 300, Walk);
	LoadDivGraph("Resources/Images/Run.png", 8, 4, 2, 300, 300, Run);

	Stop[0] = LoadGraph("Resources/Images/Stop.png");
	Stop[1] = LoadGraph("Resources/Images/Stop2.png");

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
		return Walk[arrayNum];

	case IMG_RUN:
		return Run[arrayNum];

	case IMG_STOP:
		return Stop[arrayNum];
	};
};

/********************************
* サウンドを読み込む
********************************/
int Sound::LoadSounds(void) {
	if ((mainbgm = LoadSoundMem("Resources/BGM/Natural_Green.wav")) == -1) return -1;
	if ((subbgm = LoadSoundMem("Resources/BGM/BGM_Odayaka.wav")) == -1) return -1;

	if ((se_apple = LoadSoundMem("Resources/SE/Apple.wav")) == -1) return -1;
	if ((se_poisonapple = LoadSoundMem("Resources/SE/PoisonApple.wav")) == -1) return -1;
	if ((se_corsor = LoadSoundMem("Resources/SE/btn02.wav")) == -1) return -1;
	if ((se_selct = LoadSoundMem("Resources/SE/btn10.wav")) == -1) return -1;

	ChangeVolumeSoundMem(97, mainbgm);
	ChangeVolumeSoundMem(400, se_apple);
	ChangeVolumeSoundMem(450, se_poisonapple);
	ChangeVolumeSoundMem(150, subbgm);
	ChangeVolumeSoundMem(170, se_corsor);
	ChangeVolumeSoundMem(150, se_selct);

	return 0;
};

/********************************
* フォントを読み込む
********************************/
int Font::LoadFonts(void) {
	LPCSTR font_path = "Resources/Fonts/syokakiutage.ttf"; // 読み込むフォントファイルのパス
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) < 0) {
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	};

	if (state == 0) {
		handle_0_128 = CreateFontToHandle(NULL, 128, -1, DX_FONTTYPE_NORMAL);
		handle_0_64 = CreateFontToHandle(NULL, 64, -1, DX_FONTTYPE_NORMAL);
		handle_0_16 = CreateFontToHandle(NULL, 16, -1, DX_FONTTYPE_NORMAL);
		handle_0_32 = CreateFontToHandle(NULL, 32, -1, DX_FONTTYPE_NORMAL);
		handle_1_128 = CreateFontToHandle("しょかきうたげ（無料版）", 128, 9, DX_FONTTYPE_EDGE);
		handle_1_64 = CreateFontToHandle("しょかきうたげ（無料版）", 64, 9, DX_FONTTYPE_EDGE);
		handle_1_32 = CreateFontToHandle("しょかきうたげ（無料版）", 32, 9, DX_FONTTYPE_EDGE);
		handle_1_16 = CreateFontToHandle("しょかきうたげ（無料版）", 16, 9, DX_FONTTYPE_EDGE);
		//font.handle_3_ // 追加フォントのパスとサイズ
		state = 1;
	};

	//if ((font.s = LoadFont("Resources/Fonts/syokakiutage.ttf")) == -1) return -1;

	return 0;
};
