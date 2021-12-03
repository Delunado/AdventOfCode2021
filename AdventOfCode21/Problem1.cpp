#include "Problem1.h"

Problem1::Problem1(std::string filepath): _depthMeasures(std::vector<int>())
{
	LoadProblem(filepath);
}

void Problem1::LoadProblem(std::string filepath) {
	std::fstream file;
	file.open(filepath);

	if (file) {
		while (!file.eof()) {
			int nextMeasure;
			file >> nextMeasure;

			_depthMeasures.push_back(nextMeasure);
		}

		file.close();
	}
	else {
		std::cout << "Can't open file " << filepath << std::endl;
	}
}

int Problem1::DepthMeasureIncrement(std::vector<int> depthMeasures)
{
	int increment = 0;

	if (depthMeasures.size() > 1) {
		int lastMeasure = depthMeasures[0];

		for (int i = 1; i < depthMeasures.size(); i++) {
			int currentMeasure = depthMeasures[i];

			if (currentMeasure > lastMeasure) {
				increment++;
			}

			lastMeasure = currentMeasure;
		}
	}

	return increment;
}

int Problem1::DepthMeasureWindowIncrement(unsigned int windowSize)
{
	std::vector<int> windowedMeasures = std::vector<int>();

	for (int i = 0; i < _depthMeasures.size(); i++) {
		int currentWindowMeasure = 0;
		int windowLimit = i + windowSize;

		if (windowLimit <= _depthMeasures.size()) {

			for (int j = i; j < windowLimit; j++) {
				currentWindowMeasure += _depthMeasures[j];
			}

			windowedMeasures.push_back(currentWindowMeasure);
		}
	}

	return DepthMeasureIncrement(windowedMeasures);
}

void Problem1::Resolve() {
	std::cout << "The depth measure increment is " << DepthMeasureIncrement(_depthMeasures) << std::endl;
	std::cout << "The windowed depth measure increment is " << DepthMeasureWindowIncrement(3) << std::endl;
}