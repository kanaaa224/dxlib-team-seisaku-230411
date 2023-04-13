// ìF“‡‘Ü

#include "resourceLoad.h"
#include "DxLib.h"

Image image;
Sound sound;
Font font;

int LoadImages(void)
{
	if ((image.title = LoadGraph("Resources/Images/title.png")) == -1) return -1;
	//if ((image.apple = LoadGraph("Resources/Images/apple.png")) == -1) return -1;
	return 0;
}

int LoadSounds(void)
{
	//if ((sound.bgm = LoadGraph("Resources/Fonts/syokakiutage.ttf")) == -1) return -1;
	//if ((sound.se = LoadGraph("Resources/Fonts/syokakiutage.ttf")) == -1) return -1;
	return 0;
}

int LoadFonts(void)
{
	//if ((font.s = LoadGraph("Resources/Fonts/syokakiutage.ttf")) == -1) return -1;
	return 0;
}

int ResourceLoad(void)
{
	if (LoadImages() == -1) return -1;
	if (LoadSounds() == -1) return -1;
	if (LoadFonts() == -1) return -1;
	return 0;
}