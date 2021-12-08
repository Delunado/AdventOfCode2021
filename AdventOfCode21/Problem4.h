#pragma once
#include "Problem.h"
#include <sstream>
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
	int _rowSize;
	int _columnSize;
	int _currentRow;
	int _currentColumn;
	bool _isComplete;
	bool _isWinning;
	int _winNumber;

public:
	BingoBoard(int rowSize, int columSize) : _bingoBoard(std::vector<std::vector<BingoNumber>>()), _rowSize(rowSize), _columnSize(columSize),
		_currentRow(0), _currentColumn(0), _isComplete(false), _isWinning(false), _winNumber(0) {

		for (int i = 0; i < _rowSize; i++) {
			_bingoBoard.push_back(std::vector<BingoNumber>());
		}
	}

	void AddNumber(int number) {
		if (_isComplete) {
			Utils::Log("The bingo board is complete!");
			return;
		}

		BingoNumber bingoNumber(number);

		_bingoBoard[_currentRow].push_back(bingoNumber);

		++_currentColumn %= _columnSize;

		if (_currentColumn == 0) {
			_currentRow++;
		}

		if (_currentRow >= _rowSize) {
			_isComplete = true;
		}
	}

	/// <summary>
	/// Marks the parameter number and returns true if there is a winning row or column
	/// </summary>
	/// <param name="number"></param>
	/// <returns></returns>
	bool CheckNumber(int number) {

		//Here we mark the number
		int numberRow = 0;
		int numberColumn = 0;

		for (int i = 0; i < _rowSize; i++) {
			for (int j = 0; j < _columnSize; j++) {
				if (_bingoBoard[i][j]._number == number) {
					_bingoBoard[i][j]._isMarked = true;
					numberRow = i;
					numberColumn = j;
					break;
				}
			}
		}

		//Then check winning row
		bool isWinningNumber = true;

		for (int i = 0; i < _rowSize; i++) {
			if (!_bingoBoard[i][numberColumn]._isMarked) {
				isWinningNumber = false;
				break;
			}
		}

		if (!isWinningNumber) {
			isWinningNumber = true;

			//Finally check winning column, if no winning row
			for (int i = 0; i < _columnSize; i++) {
				if (!_bingoBoard[numberRow][i]._isMarked) {
					isWinningNumber = false;
					break;
				}
			}
		}

		if (isWinningNumber) {
			_winNumber = number;
			_isWinning = true;
		}

		return isWinningNumber;
	}

	int CalculateScore() {
		int unmarkedSum = 0;

		for (int i = 0; i < _rowSize; i++) {
			for (int j = 0; j < _columnSize; j++) {
				if (!_bingoBoard[i][j]._isMarked) {
					unmarkedSum += _bingoBoard[i][j]._number;
				}
			}
		}

		return unmarkedSum * _winNumber;
	}

	bool IsComplete() {
		return _isComplete;
	}

	bool IsWinning() {
		return _isWinning;
	}

	void PrintBoard() {
		for (int i = 0; i < _rowSize; i++) {
			for (int j = 0; j < _columnSize; j++) {
				std::cout << _bingoBoard[i][j]._number << " ";
			}

			std::cout << std::endl;
		}

		std::cout << "\n" << std::endl;
	}
};

class Problem4 : public Problem
{
private:
	std::vector<BingoBoard> _bingoBoards;
	std::vector<int> _randomNumbers;

	//Here we will load the Bingo Boards
	void LoadProblem(std::string filepath) override;

	//here we will load hte Random Numbers
	void LoadProblemRandomNumbers(std::string filepath);

	int FindFirstWinningBoard();
	int FindLastWinningBoard();

public:
	Problem4(std::string filepath, std::string randomNumbersFilepath);

	void Resolve() override;
};