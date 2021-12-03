#pragma once
#include "Problem.h"
#include <vector>

class Problem2 : public Problem
{
	enum class MovementType {
		FORWARD,
		UP,
		DOWN
	};

	struct MovementData {
		MovementType _movementType;
		int _movementValue;

		MovementData(std::string movementTypeStr, int movementValue) {

			_movementType = MovementType::FORWARD;

			if (movementTypeStr == "down") {
				_movementType = MovementType::DOWN;
			}
			else if (movementTypeStr == "up") {
				_movementType = MovementType::UP;
			}
			else if (movementTypeStr != "forward") {
				std::cout << "No valid movement type of type " << movementTypeStr << std::endl;
			}

			_movementValue = movementValue;
		}
	};

private:
	std::vector<MovementData> _movements;

	void LoadProblem(std::string filepath) override;

	int FinalPositionMultiplication();
	int FinalPositionWithAimMultiplication();

public:
	Problem2(std::string filepath);

	void Resolve() override;
};

