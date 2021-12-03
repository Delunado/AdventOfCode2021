#pragma once
#include "Problem.h"
#include <bitset>
#include <vector>

class Problem3 : public Problem
{
private:
	static const int BITS_NUMBER = 12;

	std::vector<std::bitset<BITS_NUMBER>> bitsetsData;

	void LoadProblem(std::string filepath) override;

	int PowerConsumption();
	int LifeSupportRating();
	int CalculateOxygenRating();
	int CalculateC02Rating();

public:
	Problem3(std::string filepath);

	void Resolve() override;
};