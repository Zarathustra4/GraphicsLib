#include "EdgeFigure.h"
#include "Edges.h"

EdgeFigure::EdgeFigure():
	points(Matrix(0, 4)),
	edges(Edges()),
	pointsNumber(0),
	edgesNumber(0)
{}

EdgeFigure::EdgeFigure(Matrix points, Edges edges):
    points(points),
    edges(edges),
    pointsNumber(points.getShape()[0]),
    edgesNumber(edges.getSize()) 
{}

EdgeFigure::EdgeFigure(int pointsNumber, int edgesNumber):
    points(Matrix(pointsNumber, 4)),
    edges(Edges(edgesNumber)),
    pointsNumber(pointsNumber),
    edgesNumber(edgesNumber) 
{}
