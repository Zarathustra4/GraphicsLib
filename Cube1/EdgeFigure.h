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

	Edges getEdges() {
		return edges;
	}

	std::vector<double> getMassCenter() {
		std::vector<double> massCenter = std::vector<double>(3);
		int pointsNumber = points.getShape()[0];

		double sumX = 0;
		double sumY = 0;
		double sumZ = 0;

		for (int i = 0; i < pointsNumber; i++) {
			sumX += points.get(i, 0);
			sumY += points.get(i, 1);
			sumZ += points.get(i, 2);
		}

		massCenter[0] = sumX / pointsNumber;
		massCenter[1] = sumY / pointsNumber;
		massCenter[2] = sumZ / pointsNumber;
		return massCenter;
	}
};

