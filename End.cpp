#include"DxLib.h"
#include"resourceLoad.h"
#include"End.h"

extern Image image;
extern Font font;

void DrawEnd()
{
	
	// îwåiï\é¶
	DrawGraph(0, 0, image.title, TRUE);

	// Thank you for playing
	DrawStringToHandle(10, 10, "Thank you for playing", 0x000000, font.handle_1_128, 0xffffff);

};