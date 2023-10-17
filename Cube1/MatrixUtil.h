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

	static Matrix rotateAroundY(double angle, int n = 4, int m = 4);

	static Matrix rotateAroundX(double angle, int n = 4, int m = 4);

	static Matrix rotateAroundZ(double angle, int n = 4, int m = 4);

	static Matrix Mirroring_XY(int n = 4, int m = 4);

	static Matrix Mirroring_YZ(int n = 4, int m = 4);

	static Matrix Mirroring_XZ(int n = 4, int m = 4);

	static Matrix vectorMove(vector<long double> v);

	static Matrix vectorMove(long double x, long double y, long double z);

	static Matrix scale(double scalar);

	static Matrix scaleWithoutMoving(double scalar, vector<long double> massCenter);
};

