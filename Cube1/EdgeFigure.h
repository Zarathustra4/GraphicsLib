#include "Matrix.h"
#include "Edges.h"
#include <unordered_map>

#pragma once
class EdgeFigure
{
private:
	Matrix points;
	Edges edges;
	int pointsNumber;
	int edgesNumber;
public:

	EdgeFigure();

	EdgeFigure(Matrix points, Edges edges);

	EdgeFigure(int pointsNumber, int edgesNumber);

	int getEdgesNumber();

	//return matrix with shape 2x3 to being displayed
	Matrix getEdge(int edgeIndex);  

	Matrix getMatrix();

	void setMatrix(Matrix matrix);
};

