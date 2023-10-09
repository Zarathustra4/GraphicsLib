#pragma once
#include "Matrix.h"
#include "MatrixUtil.h"
#include "EdgeFigure.h"
#include <GL/glut.h>

class GraphicUtil
{
private:
	int windowWidth;
	int windowHeight;
	int c = 30;
	int cx, cy;
	MatrixUtil matrixUtil = MatrixUtil();
	Matrix projectionMatrix = Matrix(4, 4);
public:
	GraphicUtil(int windowWidth, int windowHeight);
	void buildImage(Matrix m);
	void build3dSystem();
	void display();
	void drawFigure(EdgeFigure figure);
};

