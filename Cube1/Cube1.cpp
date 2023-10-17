#include <GL/glut.h>
#include <iostream>
#include "Matrix.h"
#include "MatrixUtil.h"
#include "GraphicUtil.h"
#include "EdgeFigure.h"
#include "EdgeFigureUtil.h"
#include <vector>

/*
    Future TODOs :
        Maybe refactor Util classes to just files with functions.
*/

using std::vector;

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
GraphicUtil graphic_util = GraphicUtil(WINDOW_WIDTH, WINDOW_HEIGHT);

void printLine() {
    std::cout << "--------------------------------------------" << std::endl;
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    graphic_util.build3dSystem();

    EdgeFigure cube = EdgeFigureUtil::getCube();
    graphic_util.drawFigure(cube);

    glFlush();
}

void keyboard(unsigned char key, int x0, int y0) {
    EdgeFigure cube = EdgeFigureUtil::getCube();
    
    switch (key){
    case '1':
        graphic_util.drawFigure(EdgeFigureUtil::scale(cube, 2), 'b');
        break;
    case '2':
        graphic_util.drawFigure(EdgeFigureUtil::rotateAroundYX(cube, 90, 90), 'g');
        break;
    case '3':
        graphic_util.drawFigure(EdgeFigureUtil::rotateAroundXY(cube, 90, 90), 'b');
        break;
    case '4':
        graphic_util.drawFigure(EdgeFigureUtil::rotateAroundEdge(cube, 90, 1), 'g');
        break;
    case '5':
        graphic_util.drawFigure(EdgeFigureUtil::rotateAroundDiagonal(cube, 90., 4, 6), 'b');
        break;
    case '6':
        graphic_util.drawFigure(EdgeFigureUtil::mirrorAtPlane(cube, 2, 3, 9), 'g');
        break;
    }
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
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
    