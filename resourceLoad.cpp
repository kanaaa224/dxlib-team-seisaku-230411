// ìF“‡‘Ü

#include "resourceLoad.h"
#include "DxLib.h"

Image image;

int LoadImages(void)
{
	if ((image.title = LoadGraph("Resources/images/title.png")) == -1) return -1;
	return 0;
}

int LoadSounds(void)
{
	return 0;
}

int ResourceLoad(void)
{
	if (LoadImages() == -1) return -1;
	if (LoadSounds() == -1) return -1;
	return 0;
}