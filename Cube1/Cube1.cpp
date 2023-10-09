#include <GL/glut.h>
#include <iostream>
#include "Matrix.h"
#include "MatrixUtil.h"
#include "GraphicUtil.h"
#include <vector>

using std::vector;

const int WINDOW_WIDTH = 700;
const int WINDOW_HEIGHT = 700;

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

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    GraphicUtil graphic_util = GraphicUtil(WINDOW_WIDTH, WINDOW_HEIGHT);
    graphic_util.build3dSystem();

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
    