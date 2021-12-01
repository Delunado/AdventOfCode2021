#pragma once

#include "Problem.h"
#include <vector>

class Problem1 : public Problem {
private:
	std::vector<int> _depthMeasures;

	void LoadProblem(std::string filepath) override;

	int DepthMeasureIncrement(std::vector<int> depthMeasures);
	int DepthMeasureWindowIncrement(unsigned int windowSize);

public:
	Problem1(std::string filepath);

	void Resolve() override;
};