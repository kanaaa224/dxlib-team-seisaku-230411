// ìF“‡‘Ü

#pragma once

#include <string>
using std::string;
using std::to_string;

class RankingNameInput {
private:
	int state;
	int selector[6];
	std::string inputName;
public:
	void Draw();
	void Reset();
	char GetName();
	int GetLength();
	int GetState();
	RankingNameInput();
};

void DrawRankingNameInput();
void ResetRankingNameInput();
char GetInputedName(int i);
int GetInputedNameLength();
int GetRankingNameInputState();