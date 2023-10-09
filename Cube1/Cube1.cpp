#include <GL/glut.h>
#include <iostream>
#include "Matrix.h"
#include "MatrixUtil.h"
#include "GraphicUtil.h"
#include "EdgeFigure.h"
#include <vector>

//TODO: use this enum to chose transformation
enum Transformation {
    rotateX,
    rotateY,
    rotateZ,
    mirrorXY,
    mirrorXZ,
    mirrorYZ
};

using std::vector;

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
MatrixUtil matrixUtil = MatrixUtil();

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

void printLine() {
    std::cout << "--------------------------------------------" << std::endl;
}

EdgeFigure createCube() {
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

EdgeFigure rotateCubeAroundY(EdgeFigure figure) {
    Matrix rotationMatrix = matrixUtil.rotateAroundY(90);

    return EdgeFigure(
        matrixUtil.matrixProduct(figure.getMatrix(), rotationMatrix),
        figure.getEdges()
    );
}

EdgeFigure rotateCubeAroundX(EdgeFigure figure) {
    Matrix rotationMatrix = matrixUtil.rotateAroundX(90);

    return EdgeFigure(
        matrixUtil.matrixProduct(figure.getMatrix(), rotationMatrix),
        figure.getEdges()
    );
}

EdgeFigure rotateCubeAroundZ(EdgeFigure figure) {
    Matrix rotationMatrix = matrixUtil.rotateAroundZ(-30);

    return EdgeFigure(
        matrixUtil.matrixProduct(figure.getMatrix(), rotationMatrix),
        figure.getEdges()
    );
}

EdgeFigure MirrorXY(EdgeFigure figure) {
    Matrix rotationMatrix = matrixUtil.Mirroring_XY();

    return EdgeFigure(
        matrixUtil.matrixProduct(figure.getMatrix(), rotationMatrix),
        figure.getEdges()
    );
}

EdgeFigure MirrorXZ(EdgeFigure figure) {
    Matrix rotationMatrix = matrixUtil.Mirroring_XZ();

    return EdgeFigure(
        matrixUtil.matrixProduct(figure.getMatrix(), rotationMatrix),
        figure.getEdges()
    );
}

EdgeFigure MirrorYZ(EdgeFigure figure) {
    Matrix rotationMatrix = matrixUtil.Mirroring_YZ();

    return EdgeFigure(
        matrixUtil.matrixProduct(figure.getMatrix(), rotationMatrix),
        figure.getEdges()
    );
}

EdgeFigure Move(EdgeFigure figure, vector<long double> vec) {
    Matrix rotationMatrix = matrixUtil.vectorMove(vec);

    return EdgeFigure(
        matrixUtil.matrixProduct(figure.getMatrix(), rotationMatrix),
        figure.getEdges()
    );
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    GraphicUtil graphic_util = GraphicUtil(WINDOW_WIDTH, WINDOW_HEIGHT);
    graphic_util.build3dSystem();
    
    EdgeFigure cube = createCube();

    graphic_util.drawFigure(cube);

    graphic_util.drawFigure(rotateCubeAroundX(cube), 'b');

    graphic_util.drawFigure(Move(cube, vector<long double> ({-2, -1, -2})), 'g');

    glFlush();
}

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("OpenGL 3D Drawing");
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
    