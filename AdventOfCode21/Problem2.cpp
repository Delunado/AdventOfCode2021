#include "Problem2.h"

Problem2::Problem2(std::string filepath): _movements(std::vector<MovementData>())
{
	LoadProblem(filepath);
}

void Problem2::LoadProblem(std::string filepath)
{
	std::fstream file;
	file.open(filepath);

	if (file) {
		while (!file.eof()) {
			std::string nextMovementTypeStr;
			file >> nextMovementTypeStr;

			int nextMovementValue;
			file >> nextMovementValue;

			_movements.push_back({nextMovementTypeStr, nextMovementValue});
		}

		file.close();
	}
	else {
		std::cout << "Can't open file " << filepath << std::endl;
	}
}

int Problem2::FinalPositionMultiplication()
{
	int initialHor = 0;
	int initialDepth = 0;

	for (int i = 0; i < _movements.size(); i++) {
		MovementData currentMov = _movements[i];

		if (currentMov._movementType == MovementType::FORWARD) {
			initialHor += currentMov._movementValue;
		}
		else {
			initialDepth += currentMov._movementType == MovementType::DOWN ? currentMov._movementValue : -currentMov._movementValue;
		}
	}

	return initialHor * initialDepth;
}

int Problem2::FinalPositionWithAimMultiplication()
{
	int initialHor = 0;
	int initialDepth = 0;
	int initialAim = 0;

	for (int i = 0; i < _movements.size(); i++) {
		MovementData currentMov = _movements[i];

		if (currentMov._movementType == MovementType::FORWARD) {
			initialHor += currentMov._movementValue;
			initialDepth += initialAim * currentMov._movementValue;
		}
		else {
			initialAim += currentMov._movementType == MovementType::DOWN ? currentMov._movementValue : -currentMov._movementValue;
		}
	}

	return initialHor * initialDepth;
}

void Problem2::Resolve()
{
	std::cout << "The final multiplication of final horizontal position x final depth is " << FinalPositionMultiplication() << std::endl;
	std::cout << "The final multiplication of final horizontal position x final depth, using aim, is " << FinalPositionWithAimMultiplication() << std::endl;
}