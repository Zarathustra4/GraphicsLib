#include <GL/glut.h>
#include <iostream>
#include "Matrix.h"
#include "MatrixUtil.h"
#include "GraphicUtil.h"
#include "EdgeFigure.h"
#include "EdgeFigureUtil.h"
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

void printLine() {
    std::cout << "--------------------------------------------" << std::endl;
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    GraphicUtil graphic_util = GraphicUtil(WINDOW_WIDTH, WINDOW_HEIGHT);
    EdgeFigureUtil edgeFigureUtil = EdgeFigureUtil();

    graphic_util.build3dSystem();
    
    EdgeFigure cube = edgeFigureUtil.getCube();

    graphic_util.drawFigure(cube);

    graphic_util.drawFigure(edgeFigureUtil.rotateCubeAroundX(cube), 'b');

    graphic_util.drawFigure(edgeFigureUtil.Move(cube, vector<long double> ({-2, -1, -2})), 'g');

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
    