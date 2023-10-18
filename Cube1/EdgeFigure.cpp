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

int EdgeFigure::getEdgesNumber() {
    return edges.getSize();
}

Matrix EdgeFigure::getEdge(int index) {
    int start = edges.getEdge(index)[0];
    int end = edges.getEdge(index)[1];
    Matrix edge(2, 3);

    vector<double> startPoint = points.getRow(start);
    vector<double> endPoint = points.getRow(end);

    startPoint.pop_back();
    endPoint.pop_back();

    edge.setRow(0, startPoint);
    edge.setRow(1, endPoint);

    return edge;
}

Matrix EdgeFigure::getMatrix() {
    return points;
}

void EdgeFigure::setMatrix(Matrix matrix) {
    this->points = matrix;
}