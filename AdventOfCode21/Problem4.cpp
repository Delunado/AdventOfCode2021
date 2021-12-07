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
			std::string nextBingoBoardLine;
			file >> nextBingoBoardLine;

			//Crear sistema para cargar los boards con numeros y que se vayan rellenando automáticamente. Te avisa cuando ya está lleno del todo. Hay que rellenarlo con
			//BoardsNumbers, no enteros normales!

			Utils::Log(nextBingoBoardLine);
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

void Problem4::Resolve()
{
}
