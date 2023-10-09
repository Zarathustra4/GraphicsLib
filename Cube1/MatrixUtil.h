#include <vector>
#include "Matrix.h"
#include <math.h>
#pragma once

using std::vector;

class MatrixUtil
{
public:
	Matrix matrixProduct(Matrix A, Matrix B);
	void matrixProduct(Matrix A, Matrix B, Matrix& C);

	Matrix identityMatrix(int n, int m);

	Matrix rotateAroundY(double angle, int n = 4, int m = 4);

	Matrix rotateAroundX(double angle, int n = 4, int m = 4);

	Matrix rotateAroundZ(double angle, int n = 4, int m = 4);

	Matrix Mirroring_XY(int n = 4, int m = 4);

	Matrix Mirroring_YZ(int n = 4, int m = 4);

	Matrix Mirroring_XZ(int n = 4, int m = 4);

	Matrix vectorMove(vector<long double> v);

	Matrix vectorMove(long double x, long double y, long double z);
};

