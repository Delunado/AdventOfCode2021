#pragma once
#include "Problem.h"
#include <vector>

struct BingoNumber {
	int _number;
	bool _isMarked;

	BingoNumber(int number) {
		_number = number;
		_isMarked = false;
	}
};

class BingoBoard {
private:
	std::vector<std::vector<BingoNumber>> _bingoBoard;

public:
	BingoBoard(std::vector<std::vector<BingoNumber>> bingoBoard) {
		_bingoBoard = bingoBoard;
	}


};

class Problem4 : public Problem
{
private:
	std::vector<BingoBoard> _bingoBoards;
	std::vector<int> _randomNumbers;

	void LoadProblem(std::string filepath) override;

public:
	Problem4(std::string filepath);

	void Resolve() override;
};