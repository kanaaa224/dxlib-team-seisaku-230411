#include "image.h"

// ‰æ‘œ‚ğ“Ç‚İ‚ŞŠÖ”
int LoadImage(Image& image, const char* filename) {
	if ((image.handle = LoadGraph(filename)) == -1) return -1;
	return 0;
}

// ‰æ‘œ‚ğ•`‰æ‚·‚éŠÖ”
void DrawImage(Image& image, int x, int y) {
	DrawGraph(x, y, image.handle, TRUE);
}
