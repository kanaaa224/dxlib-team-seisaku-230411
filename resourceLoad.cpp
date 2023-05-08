// 作：島袋

#include "DxLib.h"
#include "resourceLoad.h"

int resourceload_state;

Image image;
Sound sound;
Font font;
ChageFont chageFont;

int LoadImages(void)
{
	if ((image.title = LoadGraph("Resources/Images/title.png")) == -1) return -1;
	if ((image.controller = LoadGraph("Resources/Images/controller.png")) == -1) return -1;
	if ((image.controller_s = LoadGraph("Resources/Images/controller_sokumen.png")) == -1) return -1;
	//if ((image.player = LoadGraph("Resources/Images/player.png")) == -1) return -1;
	//LoadDivGraph("Resources/Images/apple.png", 20, 5, 4, 700, 620, image.apple);
	if ((image.apple[0] = LoadGraph("Resources/Images/REDApple.png")) == -1) return -1;
	if ((image.apple[1] = LoadGraph("Resources/Images/BLUEApple.png")) == -1) return -1;
	if ((image.apple[2] = LoadGraph("Resources/Images/GOLDApple.png")) == -1) return -1;
	if ((image.apple[3] = LoadGraph("Resources/Images/POISONApple.png")) == -1) return -1;
	LoadDivGraph("Resources/Images/player.png", 15, 5, 3, 515, 612, image.player);
	image.player[15] = LoadGraph("Resources/Images/human.png");
	LoadDivGraph("Resources/Images/Run.png", 8, 4, 2, 300, 300, image.Run);
	LoadDivGraph("Resources/Images/Walk.png", 3, 3, 1, 300, 300, image.Walk);
	image.Stop[0] = LoadGraph("Resources/Images/Stop.png");
	image.Stop[1] = LoadGraph("Resources/Images/Stop2.png");
	return 0;
}

int LoadSounds(void)
{
	if ((sound.mainbgm = LoadSoundMem("Resources/BGM/Natural_Green.wav")) == -1) return -1;
	if ((sound.se_apple = LoadSoundMem("Resources/SE/Apple.wav")) == -1) return -1;
	if ((sound.se_poisonapple = LoadSoundMem("Resources/SE/PoisonApple.wav")) == -1) return -1;

	ChangeVolumeSoundMem(97, sound.mainbgm);
	ChangeVolumeSoundMem(400, sound.se_apple);
	ChangeVolumeSoundMem(450, sound.se_poisonapple);
	return 0;
}

int LoadFonts(void)
{
	LPCSTR font_path = "Resources/Fonts/syokakiutage.ttf"; // 読み込むフォントファイルのパス
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) < 0) {
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	}
	if (font.state == 0) {
		font.handle_0_16 = CreateFontToHandle(NULL, 16, -1, DX_FONTTYPE_NORMAL);
		font.handle_0_32 = CreateFontToHandle(NULL, 32, -1, DX_FONTTYPE_NORMAL);
		font.handle_1_128 = CreateFontToHandle("しょかきうたげ（無料版）", 128, 9, DX_FONTTYPE_EDGE);
		font.handle_1_64 = CreateFontToHandle("しょかきうたげ（無料版）", 64, 9, DX_FONTTYPE_EDGE);
		font.handle_1_32 = CreateFontToHandle("しょかきうたげ（無料版）", 32, 9, DX_FONTTYPE_EDGE);
		//font.handle_3_ // 追加フォントのパスとサイズ
		font.state = 1;
	}
	//if ((font.s = LoadFont("Resources/Fonts/syokakiutage.ttf")) == -1) return -1;
	return 0;
}

int ResourceLoad(void)
{
	if (resourceload_state == 0) {
		if (LoadImages() == -1) return -1;
		if (LoadSounds() == -1) return -1;
		if (LoadFonts() == -1) return -1;
		resourceload_state = 1;
	}
	return 0;
}

int ChangeFontSize(int size) {
	if (chageFont.state != size) {
		SetFontSize(size);
		chageFont.state = size;
		return 1;
	}
	else {
		return 0;
	}
}



/* old - image.h
// 作：島袋


#pragma once
#include "DxLib.h"

// 画像用の構造体
class Image {
public:
	int handle;
	char* filename;
};

// 画像を読み込む関数のプロトタイプ宣言
int LoadImage(Image& image, const char* filename);

// 画像を描画する関数のプロトタイプ宣言
void DrawImage(Image& image, int x, int y);


class IMAGE {
public:

	int Title;

	void print();
};

// メンバー関数（メソッド）の定義と処理
// :: はスコープ演算子
void IMAGE::print() {
	printf("x : %lf y : %lf\n", x, y);
};
*/

/* old - image.cpp
// 作：島袋


#include "image.h"

// 画像を読み込む関数
int LoadImage(Image& image, const char* filename) {
	if ((image.handle = LoadGraph(filename)) == -1) return -1;
	return 0;
}

// 画像を描画する関数
void DrawImage(Image& image, int x, int y) {
	DrawGraph(x, y, image.handle, TRUE);
}

*/