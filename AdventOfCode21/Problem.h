#pragma once

#include <iostream>
#include <fstream>

class Problem {
private:
	virtual void LoadProblem(std::string filepath) = 0;
public:
	virtual void Resolve() = 0;
};