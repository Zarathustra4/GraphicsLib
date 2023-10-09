#include "EdgeFigure.h"

EdgeFigure::EdgeFigure():
	points(Matrix(0, 4)),
	edges(Matrix(0, 2)),
	pointsNumber(0),
	edgesNumber(0)
{}

EdgeFigure::EdgeFigure(Matrix points, Matrix edges):
    points(points),
    edges(edges),
    pointsNumber(points.getShape()[0]),
    edgesNumber(edges.getShape()[0]) 
{}

EdgeFigure::EdgeFigure(int pointsNumber, int edgesNumber):
    points(Matrix(pointsNumber, 4)),
    edges(Matrix(edgesNumber, 2)),
    pointsNumber(pointsNumber),
    edgesNumber(edgesNumber) 
{}
