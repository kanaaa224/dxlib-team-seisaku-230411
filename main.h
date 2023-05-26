#pragma once

#define TITLE 0
#define INIT 1
#define MAIN 2
#define HELP 3
#define RESULT 4
#define INPUTNAME 5
#define RANKING 6
#define END 7
#define TEST 8
#define EXIT 99

//ÉQÅ[ÉÄÉÇÅ[Éhä«óù
class Game {
private:
    static int mode;
    static int snd_flg;
public:
    static void ModeSet(int);
    static int ModeGet();

    static void SndFlgSet(int);
    static int SndFlgGet();
};