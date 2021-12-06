#include "Problem4.h"

Problem4::Problem4(std::string filepath) : _bingoBoards(std::vector<BingoBoard>()), _randomNumbers(std::vector<int>())
{
	LoadProblem(filepath);
}

void Problem4::LoadProblem(std::string filepath)
{
	std::fstream file;
	file.open(filepath);

	if (file) {
		while (!file.eof()) {

			//Primero cargamos los numeros aleatorios

			std::string nextMovementTypeStr;
			file >> nextMovementTypeStr;

			Utils::Log(nextMovementTypeStr);

			//Luego cargamos los cartones 
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
