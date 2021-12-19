#pragma once
#include "Problem.h"
#include <vector>
#include <sstream>

class Line 
{
private:
	int _fromX;
	int _fromY;

	int _toX;
	int _toY;

public:
	Line(int fromX, int fromY, int toX, int toY) {
		_fromX = fromX;
		_fromY = fromY;
		_toX = toX;
		_toY = toY;
	}

	bool IsOneAxisLine() {
		return (!HasVerticalDifferences() || !HasVerticalDifferences());
	}

	bool HasHorizontalDifferences() {
		return (_fromX != _toX);
	}

	bool HasVerticalDifferences() {
		return (_fromY != _toY);
	}

	int GetFromX() {
		return _fromX;
	}

	int GetFromY() {
		return _fromY;
	}

	int GetToX() {
		return _toX;
	}

	int GetToY() {
		return _toY;
	}

	void Print() {
		std::cout << _fromX << "," << _fromY << " -> " << _toX << "," << _toY << std::endl;
	}
};

class Problem5 : public Problem
{
private:
	static const int ROWS = 1000;
	static const int COLUMNS = 1000;

	std::vector<Line> _lines;
	std::vector<std::vector<int>> _table;

	void LoadProblem(std::string filepath) override;
	void CalculateLineOverlaps();

public:
	Problem5(std::string filepath);

	int LinesOverlapPoints(int minNumberOfOverlaps);

	void Resolve() override;
};