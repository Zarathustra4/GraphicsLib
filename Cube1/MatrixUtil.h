#include <vector>
#include "Matrix.h"
#include <math.h>
#pragma once

using std::vector;

class MatrixUtil
{
public:
	static Matrix matrixProduct(Matrix A, Matrix B);
	void matrixProduct(Matrix A, Matrix B, Matrix& C);

	static Matrix identityMatrix(int n, int m);

	static Matrix rotateAroundY(double angle, bool degrees = true, int n = 4, int m = 4);

	static Matrix rotateAroundX(double angle, bool degrees = true, int n = 4, int m = 4);

	static Matrix rotateAroundZ(double angle, bool degrees = true, int n = 4, int m = 4);

	static Matrix Mirroring_XY(int n = 4, int m = 4);

	static Matrix Mirroring_YZ(int n = 4, int m = 4);

	static Matrix Mirroring_XZ(int n = 4, int m = 4);

	static Matrix vectorMove(vector<double> v);

	static Matrix vectorMove(double x, double y, double z);

	static Matrix scale(double scalar);

	static Matrix scaleWithoutMoving(double scalar, vector<double> massCenter);

	static Matrix rotateAroundEdge(double angle, vector<double> a, vector<double> b);

	static Matrix mirrorOnPlane(Matrix plane);
};

