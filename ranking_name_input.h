// ìF“‡‘Ü

#pragma once

#include <string>
using std::string;
using std::to_string;

class RankingNameInput {
private:
	static int state;
	static int selector[6];
	static std::string inputName;

    static char alphabet[][26];

    static int ctrl_state[];
public:
	static void Draw();
	static void Reset();
	static char GetName(int);
	static int GetNameLength();
	static int GetState();
};