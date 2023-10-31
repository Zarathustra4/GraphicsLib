#include "EdgeFigureUtil.h"


void setCubePoints(Matrix& cube) {
    cube.setRow(0, vector<double>({ 2, 1, 2, 1 }));
    cube.setRow(1, vector<double>({ 3, 1, 2, 1 }));
    cube.setRow(2, vector<double>({ 3, 1.5, 2, 1 }));
    cube.setRow(3, vector<double>({ 2.5, 2, 2, 1 }));
    cube.setRow(4, vector<double>({ 2, 2, 2, 1 }));
    cube.setRow(5, vector<double>({ 2, 1, 1, 1 }));
    cube.setRow(6, vector<double>({ 3, 1, 1, 1 }));
    cube.setRow(7, vector<double>({ 3, 2, 1, 1 }));
    cube.setRow(8, vector<double>({ 2, 2, 1, 1 }));
    cube.setRow(9, vector<double>({ 3, 2, 1.5, 1 }));
}

void setPiramidPoints(Matrix& piramid) {
    piramid.setRow(0, vector<double>({ .5,  -.5,    0, 1 }));
    piramid.setRow(1, vector<double>({ .5,  .5,     0, 1 }));
    piramid.setRow(2, vector<double>({ -.5, .5,     0, 1 }));
    piramid.setRow(3, vector<double>({ -.5, -.5,    0, 1 }));
    piramid.setRow(4, vector<double>({ 0,   0,      1, 1 }));
}

EdgeFigure EdgeFigureUtil::getPiramid() {
    Matrix piramidPoints(5, 4);
    setPiramidPoints(piramidPoints);

    Edges piramidEdges = Edges();
    piramidEdges.addEdge(vector<int>({ 0, 4 }));
    piramidEdges.addEdge(vector<int>({ 1, 4 }));
    piramidEdges.addEdge(vector<int>({ 2, 4 }));
    piramidEdges.addEdge(vector<int>({ 3, 4 }));
    piramidEdges.addEdge(vector<int>({ 0, 1 }));
    piramidEdges.addEdge(vector<int>({ 0, 3 }));
    piramidEdges.addEdge(vector<int>({ 1, 2 }));
    piramidEdges.addEdge(vector<int>({ 2, 3 }));

    return EdgeFigure(piramidPoints, piramidEdges);
}

EdgeFigure EdgeFigureUtil::getCube() {
    Matrix cubePoints(10, 4);
    setCubePoints(cubePoints);

    Edges cubeEdges = Edges();
    cubeEdges.addEdge(vector<int>({ 0, 1 }));
    cubeEdges.addEdge(vector<int>({ 0, 5 }));
    cubeEdges.addEdge(vector<int>({ 0, 4 }));
    cubeEdges.addEdge(vector<int>({ 1, 2 }));
    cubeEdges.addEdge(vector<int>({ 1, 6 }));
    cubeEdges.addEdge(vector<int>({ 2, 3 }));
    cubeEdges.addEdge(vector<int>({ 2, 9 }));
    cubeEdges.addEdge(vector<int>({ 3, 4 }));
    cubeEdges.addEdge(vector<int>({ 3, 9 }));
    cubeEdges.addEdge(vector<int>({ 4, 8 }));
    cubeEdges.addEdge(vector<int>({ 5, 8 }));
    cubeEdges.addEdge(vector<int>({ 5, 6 }));
    cubeEdges.addEdge(vector<int>({ 6, 7 }));
    cubeEdges.addEdge(vector<int>({ 7, 9 }));
    cubeEdges.addEdge(vector<int>({ 7, 8 }));
    return EdgeFigure(cubePoints, cubeEdges);
}