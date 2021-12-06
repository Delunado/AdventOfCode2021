#pragma once

#include "Utils.h"
#include <fstream>

class Problem {
private:
	virtual void LoadProblem(std::string filepath) = 0;
public:
	virtual void Resolve() = 0;
};