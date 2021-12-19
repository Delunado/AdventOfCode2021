#include "Problem5.h"

Problem5::Problem5(std::string filepath) : _lines(std::vector<Line>()), _table(std::vector<std::vector<int>>(ROWS, std::vector<int>(COLUMNS)))
{
	LoadProblem(filepath);
}

void Problem5::LoadProblem(std::string filepath)
{
	std::fstream file;
	file.open(filepath);

	std::string discardStr;
	std::string nextLineFrom;
	std::string nextLineTo;

	int fromX;
	std::string fromXStr;
	int fromY;

	int toX;
	std::string toXStr;
	int toY;

	if (file) {
		while (!file.eof()) {
			file >> nextLineFrom;
			std::stringstream ssFrom(nextLineFrom);
			std::getline(ssFrom, fromXStr, ',');
			fromX = std::stoi(fromXStr);
			ssFrom >> fromY;

			file >> discardStr;

			file >> nextLineTo;
			std::stringstream ssTo(nextLineTo);
			std::getline(ssTo, toXStr, ',');
			toX = std::stoi(toXStr);
			ssTo >> toY;

			Line line(fromX, fromY, toX, toY);
			_lines.push_back(line);
		}

		CalculateLineOverlaps();

		file.close();
	}
	else {
		std::cout << "Can't open file " << filepath << std::endl;
	}
}

void Problem5::CalculateLineOverlaps()
{
	//Now, only for one axis lines
	for (int i = 0; i < _lines.size(); i++) {
		if (_lines[i].IsOneAxisLine()) {
			if (_lines[i].HasHorizontalDifferences()) {
				int from = _lines[i].GetFromX();
				int to = _lines[i].GetToX();

				if (from > to) {

				}
				else if (to > from) {

				}
			}
			else {

			}
		}
	}
}

int Problem5::LinesOverlapPoints(int minNumberOfOverlaps)
{
	return 0;
}

void Problem5::Resolve()
{
	std::cout << "The final score of the first winning board is " << "Funcion" << std::endl;
}