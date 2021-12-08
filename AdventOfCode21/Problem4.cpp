#include "Problem4.h"

Problem4::Problem4(std::string filepath, std::string randomNumbersFilepath) : _bingoBoards(std::vector<BingoBoard>()), _randomNumbers(std::vector<int>())
{
	LoadProblem(filepath);
	LoadProblemRandomNumbers(randomNumbersFilepath);
}

void Problem4::LoadProblem(std::string filepath)
{
	std::fstream file;
	file.open(filepath);

	if (file) {
		while (!file.eof()) {

			BingoBoard bingoBoard(5, 5);

			while (!bingoBoard.IsComplete()) {
				int nextBingoBoardNumber;
				file >> nextBingoBoardNumber;

				bingoBoard.AddNumber(nextBingoBoardNumber);
			}

			_bingoBoards.push_back(bingoBoard);
		}

		file.close();
	}
	else {
		std::cout << "Can't open file " << filepath << std::endl;
	}
}

void Problem4::LoadProblemRandomNumbers(std::string filepath)
{
	std::fstream file;
	file.open(filepath);

	if (file) {
		while (!file.eof()) {

			std::string nextRandomNumberStr;
			std::getline(file, nextRandomNumberStr, ',');

			int nextRandomNumber = std::stoi(nextRandomNumberStr);

			_randomNumbers.push_back(nextRandomNumber);
		}

		file.close();
	}
	else {
		std::cout << "Can't open file " << filepath << std::endl;
	}
}

int Problem4::FindFirstWinningBoard()
{
	for (int i = 0; i < _randomNumbers.size(); i++) {
		int currentRandomNumber = _randomNumbers[i];

		for (int j = 0; j < _bingoBoards.size(); j++) {
			if (_bingoBoards[j].CheckNumber(currentRandomNumber)) {
				return _bingoBoards[j].CalculateScore();
			}
		}
	}

	return 0;
}

/// <summary>

/// </summary>
/// <returns></returns>
int Problem4::FindLastWinningBoard()
{
	/// We process all the boards and save the latest score, 
	//so when all random numbers are drawn, the last score will be the winner one.
	int lastScore = 0;

	for (int i = 0; i < _randomNumbers.size(); i++) {
		int currentRandomNumber = _randomNumbers[i];

		for (int j = 0; j < _bingoBoards.size(); j++) {
			if (!_bingoBoards[j].IsWinning()) {
				if (_bingoBoards[j].CheckNumber(currentRandomNumber)) {
					lastScore = _bingoBoards[j].CalculateScore();
				}
			}
		}
	}

	return lastScore;
}

void Problem4::Resolve()
{
	std::cout << "The final score of the first winning board is " << FindFirstWinningBoard() << std::endl;
	std::cout << "The final score of the last winning board is " << FindLastWinningBoard() << std::endl;
}
