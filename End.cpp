#include "DxLib.h"
#include "resourceLoad.h"

#include "main.h"


int FPSCount = 0;


/********************************
* ƒGƒ“ƒh‰æ–Ê
********************************/
void DrawEnd() {
	if (FPSCount++ < 300) {

		// ”wŒi•\Ž¦
		DrawGraph(0, 0, Image::GetImages(IMG_TITLE, 0), TRUE);

		//”wŒiBOX
		DrawBox(165, 145, 1030, 650, 0xeee8aa, TRUE);

		// Thank you for playing
		DrawStringToHandle(10, 10, "Thank you for playing", 0x000000, Font::GetFonts(FONT_1_128), 0xffffff);

		//»ìŽÒ
		DrawStringToHandle(170, 150, "»ìŽÒ", 0x000000, Font::GetFonts(FONT_0_32), 0xffffff);
		DrawStringToHandle(170, 200, "‘Û“dŽqƒrƒWƒlƒXê–åŠwZ", 0x000000, Font::GetFonts(FONT_0_16), 0xffffff);
		DrawStringToHandle(170, 230, "V—¢Ÿä‹K@–k‘º”¹Žm “‡‘Ü Š–]@‹Êé—¬Š@–LŒ³ˆê¬",0x000000, Font::GetFonts(FONT_0_16), 0xffffff);

		// ŽÓŽ«
		//SetFontSize(40); FPS’á‰º–â‘è”­¶’†
		//DrawFormatString(20, 200, 0x000000, "Žg—p‚µ‚½‘fÞ‚ÌƒNƒŒƒWƒbƒg");
		//SetFontSize(32);
		DrawStringToHandle(170, 270, "Žg—p‚µ‚½‘fÞ", 0x000000, Font::GetFonts(FONT_0_32), 0xffffff);
		DrawStringToHandle(170, 330, "ƒvƒŒƒCƒ„[‰æ‘œi•à‚­j         pictogrammingi–LŒ³ˆê¬jhttps://pictogramming.org/?page_id=2919", 0x000000, Font::GetFonts(FONT_0_16), 0xffffff);
		DrawStringToHandle(170, 360, "ƒvƒŒƒCƒ„[‰æ‘œi‘–‚é)          pictogrammingi–k‘º”¹Žmjhttps://pictogramming.org/?page_id=2919", 0x000000, Font::GetFonts(FONT_0_16), 0xffffff);
		DrawStringToHandle(170, 390, "‚è‚ñ‚²‰æ‘œ                     illustACi‚ä‚ä‚±jhttps://www.ac-illust.com/", 0x000000, Font::GetFonts(FONT_0_16), 0xffffff);
		DrawStringToHandle(170, 420, "ƒQ[ƒ€”wŒi‰æ‘œ                 ‚¢‚ç‚·‚Æ‚â@https://www.irasutoya.com/", 0x000000, Font::GetFonts(FONT_0_16), 0xffffff);

		DrawStringToHandle(170, 450, "ƒtƒHƒ“ƒg                       ‚a‚n‚n‚s‚gi‚Ú‚ñ‚Ì‚¤“°j@https://booth.pm/ja", 0x000000, Font::GetFonts(FONT_0_16), 0xffffff);

		DrawStringToHandle(170, 480, "ƒQ[ƒ€ƒƒCƒ“BGM                ‚c‚n‚u‚`[‚r‚x‚m‚c‚q‚n‚l‚d@ishimtonej https://dova-s.jp/", 0x000000, Font::GetFonts(FONT_0_16), 0xffffff);
		DrawStringToHandle(170, 510, "ƒQ[ƒ€ƒƒCƒ“ŠOBGM              ‚l‚•‚“‚l‚t‚“@https://musmus.main.jp/", 0x000000, Font::GetFonts(FONT_0_16), 0xffffff);

		DrawStringToHandle(170, 540, "‚è‚ñ‚²Žæ“¾ŽžSE                 Œø‰Ê‰¹ƒ‰ƒ{@https://soundeffect-lab.info/", 0x000000, Font::GetFonts(FONT_0_16), 0xffffff);
		DrawStringToHandle(170, 570, "“Å‚è‚ñ‚²Žæ“¾ŽžSE               Œø‰Ê‰¹ƒ‰ƒ{@https://soundeffect-lab.info/", 0x000000, Font::GetFonts(FONT_0_16), 0xffffff);
		DrawStringToHandle(170, 600, "ƒ^ƒCƒgƒ‹‚Å‚Ì‘I‘ðŽž             Œø‰Ê‰¹ƒ‰ƒ{@https://soundeffect-lab.info/", 0x000000, Font::GetFonts(FONT_0_16), 0xffffff);
		DrawStringToHandle(170, 630, "ƒ^ƒCƒgƒ‹‚Å‚ÌƒJ[ƒ\ƒ‹ˆÚ“®ŽžSE   Œø‰Ê‰¹ƒ‰ƒ{@https://soundeffect-lab.info/", 0x000000, Font::GetFonts(FONT_0_16), 0xffffff);

		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
            Game::ModeSet(EXIT);
		};

		if (FPSCount == 300) {
            Game::ModeSet(EXIT);
		}
	}
};