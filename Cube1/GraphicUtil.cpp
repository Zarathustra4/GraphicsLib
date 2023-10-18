#include "GraphicUtil.h"
#include "MatrixUtil.h"
#include "Matrix.h"
#include <vector>
#include <math.h>
#define Pi 3.14159265358979323846

Matrix setProjectionMatrix(Matrix& projectionMatrix) {
	double phi, teta;
	phi = -29 * Pi / 180; teta = 26 * Pi / 180;

	projectionMatrix.setRow(0, vector<double>({ cos(phi),	sin(phi) * sin(teta),	0, 0 }));
	projectionMatrix.setRow(1, vector<double>({ 0,			cos(teta),				0, 0 }));
	projectionMatrix.setRow(2, vector<double>({ sin(phi), -cos(phi) * sin(teta),	0, 0 }));
	projectionMatrix.setRow(3, vector<double>({ 0,			0,						0, 1 }));

	return projectionMatrix;
}

GraphicUtil::GraphicUtil(int windowWidth, int windowHeight) :
	windowWidth(windowWidth),
	windowHeight(windowHeight),
	cx(windowWidth / 2.),
	cy(windowHeight / 2.)
{
	setProjectionMatrix(projectionMatrix);
}

void GraphicUtil::drawFigure(EdgeFigure figure, char color) {
	figure.setMatrix(
		matrixUtil.matrixProduct(figure.getMatrix(), projectionMatrix)
	);

	if (color == 'r') {
		glColor3d(1, 0, 0);//червоний колір
	}
	else if (color == 'b') {
		glColor3d(0, 0, 1);
	}
	else if (color == 'g') {
		glColor3d(0, 1, 0);
	}
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(3);
	glBegin(GL_LINES);

	double x1, y1, x2, y2, screenX1, screenY1, screenX2, screenY2;
	Matrix projectedPoints;
	int size = figure.getEdgesNumber();
	for (int i = 0; i < figure.getEdgesNumber(); i++) {
		projectedPoints = figure.getEdge(i);

		x1 = projectedPoints.get(0, 0);
		y1 = projectedPoints.get(0, 1);

		x2 = projectedPoints.get(1, 0);
		y2 = projectedPoints.get(1, 1);
		
		screenX1 = c * x1 + cx;
		screenY1 = c * y1 + cy;
		screenX2 = c * x2 + cx;
		screenY2 = c * y2 + cy;

		glVertex2d(screenX1, screenY1);
		glVertex2d(screenX2, screenY2);
	}
	glEnd();
}


void GraphicUtil::build3dSystem() {
    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, windowWidth, 0.0, windowHeight);

    Matrix axisMatrix(4, 4);
    axisMatrix.setRow(0, vector<double>({ 0,0,0,1 }));
    axisMatrix.setRow(1, vector<double>({ 7,0,0,1 }));
    axisMatrix.setRow(2, vector<double>({ 0,7,0,1 }));
    axisMatrix.setRow(3, vector<double>({ 0,0,7,1 }));

    Matrix projectedAxisMatrix(4, 4);
    Matrix screenAxisMatrix(4, 4);
    double x, y, xScreen, yScreen;

    matrixUtil.matrixProduct(axisMatrix, projectionMatrix, projectedAxisMatrix);

    for (int i = 0; i <= 3; i++) {
        x = projectedAxisMatrix.get(i, 0);
        y = projectedAxisMatrix.get(i, 1);
        xScreen = c * x + cx;
        yScreen = c * y + cy;
        screenAxisMatrix.setValue(i, 0, xScreen);
        screenAxisMatrix.setValue(i, 1, yScreen);
    }

    glColor3d(0, 0, 0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2d(screenAxisMatrix.get(0, 0), screenAxisMatrix.get(0, 1));
    glVertex2d(screenAxisMatrix.get(1, 0), screenAxisMatrix.get(1, 1));
    glVertex2d(screenAxisMatrix.get(0, 0), screenAxisMatrix.get(0, 1));
    glVertex2d(screenAxisMatrix.get(2, 0), screenAxisMatrix.get(2, 1));
    glVertex2d(screenAxisMatrix.get(0, 0), screenAxisMatrix.get(0, 1));
    glVertex2d(screenAxisMatrix.get(3, 0), screenAxisMatrix.get(3, 1));
    glEnd();
}


