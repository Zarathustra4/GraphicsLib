#include "Matrix.h"
#include <unordered_map>

#pragma once
class EdgeFigure
{
private:
	Matrix points;
	Matrix edges;
	int pointsNumber;
	int edgesNumber;
public:

	EdgeFigure();

	EdgeFigure(Matrix points, Matrix edges);

	EdgeFigure(int pointsNumber, int edgesNumber);

	
};

