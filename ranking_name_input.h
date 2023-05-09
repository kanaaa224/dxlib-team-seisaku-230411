// ìF“‡‘Ü

#pragma once

void DrawRankingNameInput();
void ResetRankingNameInput();
char GetInputedName(int i);

#include <string>
using std::string;
using std::to_string;

class NameInput {
public:
	//int input_flg = 0;
	std::string inputedName = "";
	//char inputedName;
};
