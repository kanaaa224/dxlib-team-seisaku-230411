#pragma once

#ifndef APPLE_H
#define APPLE_H

//マクロ定義

#define REDAPPLE 0		//画像の配列番号（赤りんご）
#define BLUEAPPLE 1		//画像の配列番号（青りんご）
#define GOLDAPPLE 2		//画像の配列番号（金りんご）
#define POISONAPPLE 3	//画像の配列番号（毒りんご）
#define APPLE_MAX 10	//りんご最大個数

//クラス宣言
class Apple {
private:
	/*メンバ変数*/
	
	int gP = 0;						//りんごの確率	

	int px1;
	int py1;
	int px2;
	int py2;

    struct  APPLE {
        int flg;			//使用フラグ
        int img;			//画像
        double x, y, w, h;	//座標、幅、高さ
        double speed;		//移動速度
        int point;			//スコア加算ポイント
    };

	APPLE gApple[APPLE_MAX];

	/*メンバ関数*/

public:
	/**
	*豊元一成
	*void AppleInit(void)
	*りんごの初期化
	*引数	：なし
	*戻り値	：なし
	* メンバ変数を初期化
	*/
	void AppleInit();

	/**
	*豊元一成
	*void FallApple(void)
	*りんごの落下処理
	*引数	：なし
	*戻り値	：なし
	*/
	void FallApple();

	/**
	*豊元一成
	*int CreateApple(void)
	*りんごの生成とりんごの確率処理
	*引数	：なし
	*戻り値	：int型
	*戻り値はりんごの生成が成功した場合TRUE、失敗した場合FALSEがgAppleのflgに入る
	*/
	int CreateApple();

	/**
	*豊元一成
	*void AppleSpeed(int i)
	*りんごの落下速度
	*引数	：int型 i
	*戻り値	：なし
	*CreateApple関数から入ってくる関数
	*引数にはCreateApple関数から取ってきたgAppleの配列番号が入っている
	*/
	void AppleSpeed(int i);

	/**
	* 北村隼士
	*int HitBox(void)
	*りんごの当たり判定処理
	*引数	：なし
	*戻り値	：int型　
	*/
	int HitBox();

	/*
	* 北村隼士
	*int HitBoxPlayer(void)
	*りんごの当たり判定処理
	*引数	：なし
	*戻り値	：int型　
	*/
	int HitBoxPlayer();

	/**
	*豊元一成
	*void ApplePoint(int i)
	*りんごのスコア＆個数をカウント処理
	*引数	：int型
	*戻り値	：なし
	*引数でgAppleの配列番号をHitBoxPlayerから取ってきて、りんごの種類別にスコアと個数を入れる
	*/
	void ApplePoint(int i);

	
	/**
	* 北村隼士
	*int ReternAppleX(int num)
	*りんごのX座標を返す
	*引数	：int型
	*戻り値	：int型　
	*/
	int ReturnAppleX(int num);

	/**
	* 北村隼士
	*int ReternAppleY(int num)
	*りんごのY座標を返す
	*引数	：int型
	*戻り値	：int型　
	*/
	int ReturnAppleY(int num);

	/**
	* 北村隼士
	*int ReternAppleImg(int num)
	*りんごのImgを返す
	*引数	：int型
	*戻り値	：int型　
	*/
	int ReturnAppleImg(int num);

	/**
	* 北村隼士
	*int ReternAppleFlg(int num)
	*りんごのFlgを返す
	*引数	：int型
	*戻り値	：int型　
	*/
	int ReturnAppleFlg(int num);

    /**
    *
    *void GetPlayerX(int xPos)
    *引数    ：
    *戻り値  ：なし
    * 
    * 
    * 
    */
	void GetPlayerX(int xPos);

    /**
    *
    *void GetPlayerX(int xPos)
    *引数    ：
    *戻り値  ：なし
    *
    *
    *
    */
	void GetPlayerY(int yPos);

    /**
    *
    *int GetBlinkFlg(void)
    *引数    ：
    *戻り値  ：
    * 
    */
 	static int GetBlinkFlg();

    /**
    *
    *int GetBlinkFlg(void)
    *引数    ：
    *戻り値  ：
    *
    */
	static int SetBlinkFlg(int flg);

    void GetAppleImgClass(Image& AppleImg);
    void GetSoundClass(Sound& AppleSound);
    void GetFontClass(Font& AppleFont);
    void DrawPause();
};

class AppleCount {
private:
    static int gRACount;				//赤りんごの個数
    static int gBACount;				//青りんごの個数
    static int gGACount;				//金りんごの個数
    static int gPACount;				//毒りんごの個数
    static int gScore;					//スコア
public:
    /**
    * 新里滉規
    *int ReternRA(void)
    *赤りんごの個数を返す
    *引数	：int型
    *戻り値	：int型　
    */
    static int ReturnRA();

    /**
    * 新里滉規
    *int ReternBL(void)
    *青りんごの個数を返す
    *引数	：int型
    *戻り値	：int型　
    */
    static int ReturnBL();

    /**
    * 新里滉規
    *int ReternGL(void)
    *金りんごの個数を返す
    *引数	：int型
    *戻り値	：int型　
    */
    static int ReturnGL();

    /**
    * 新里滉規
    *int ReternPO(void)
    *毒りんごの個数を返す
    *引数	：int型
    *戻り値	：int型　
    */
    static int ReturnPO();

    /**
    * 新里滉規
    *int ReternRA(void)
    *スコアを返す
    *引数	：int型
    *戻り値	：int型　
    */
    static int ReturnScore();

    /**
    *豊元一成
    *void MainAppleInit(void)
    *りんごの初期化
    *引数	：なし
    *戻り値	：なし
    *りんごのカウント、スコア、フラグを初期化
    */
    static void AppleMainInit(int RACount,int BACount,int GACount,int PACount,int Score);

    static void SetRA(int num);
    static void SetBL(int num);
    static void SetGL(int num);
    static void SetPO(int num);
    static void SetScore(int num);

};
#endif