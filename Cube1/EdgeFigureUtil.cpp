#include "EdgeFigureUtil.h"


void setCubePoints(Matrix& cube) {
    cube.setRow(0, vector<long double>({ 2, 1, 2, 1 }));
    cube.setRow(1, vector<long double>({ 3, 1, 2, 1 }));
    cube.setRow(2, vector<long double>({ 3, 1.5, 2, 1 }));
    cube.setRow(3, vector<long double>({ 2.5, 2, 2, 1 }));
    cube.setRow(4, vector<long double>({ 2, 2, 2, 1 }));
    cube.setRow(5, vector<long double>({ 2, 1, 1, 1 }));
    cube.setRow(6, vector<long double>({ 3, 1, 1, 1 }));
    cube.setRow(7, vector<long double>({ 3, 2, 1, 1 }));
    cube.setRow(8, vector<long double>({ 2, 2, 1, 1 }));
    cube.setRow(9, vector<long double>({ 3, 2, 1.5, 1 }));
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