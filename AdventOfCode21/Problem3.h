#pragma once
#include "Problem.h"
#include <bitset>
#include <vector>

class Problem3 : public Problem
{
	enum class ComparisonType {
		MOST_COMMON,
		LEAST_COMMON
	};

private:
	static const int BITS_NUMBER = 12;

	std::vector<std::bitset<BITS_NUMBER>> _bitsetsData;

	void LoadProblem(std::string filepath) override;

	int PowerConsumption();
	int LifeSupportRating();
	int FindValuableBitset(int valuableBit, ComparisonType comparisonType);

public:
	Problem3(std::string filepath);

	void Resolve() override;
};