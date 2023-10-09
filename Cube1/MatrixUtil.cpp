#include "MatrixUtil.h"
#include <iostream>

void multiply(Matrix A, Matrix B, Matrix& C) {
	const int n = A.getShape()[0];
	const int k = A.getShape()[1];
	const int m = B.getShape()[1];

	long double s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			s = 0;
			for (int l = 0; l < k; l++) {
				s += A.get(i, l) * B.get(l, j);
			}
			C.setValue(i, j, s);
		}
	}
}

Matrix MatrixUtil::matrixProduct(Matrix A, Matrix B) {
	vector<int> shapeA = A.getShape();
	vector<int> shapeB = B.getShape();

	if (shapeA[1] != shapeB[0]) {
		std::cerr << "[ Matrix multiplication error ]  message: \"Can not multiply matrix with given shapes\"" << std::endl;
		return Matrix();
	}

	int n = shapeA[0];
	int m = shapeB[1];

	Matrix C = Matrix(n, m);

	multiply(A, B, C);

	return C;
}

void MatrixUtil::matrixProduct(Matrix A, Matrix B, Matrix& C) {
	multiply(A, B, C);
}

Matrix MatrixUtil::identityMatrix(int n, int m) {
	vector<vector<long double>> matrixI(n, vector<long double>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) {
				matrixI[i][j] = 1;
			}
			else {
				matrixI[i][j] = 0;
			}
		}
	}
	return Matrix(n, m, matrixI);
}

Matrix MatrixUtil::rotateAroundY(double angle, int n, int m) {
	Matrix rotationMatrix = Matrix(n, m);
	rotationMatrix.setRow(0, vector<long double>({ cos(angle),	0., -sin(angle),	0. }));
	rotationMatrix.setRow(1, vector<long double>({ 0,			1,	0,				0. }));
	rotationMatrix.setRow(2, vector<long double>({ sin(angle),	0.,	cos(angle),		0. }));
	rotationMatrix.setRow(3, vector<long double>({ 0,			0., 0,				1. }));
	return rotationMatrix;
}

Matrix MatrixUtil::rotateAroundX(double angle, int n, int m) {
	Matrix rotationMatrix = Matrix(n, m);
	rotationMatrix.setRow(0, vector<long double>({ 1,	0.,			0,			0. }));
	rotationMatrix.setRow(1, vector<long double>({ 0,	cos(angle),	sin(angle),	0. }));
	rotationMatrix.setRow(2, vector<long double>({ 0,	-sin(angle),cos(angle),	0. }));
	rotationMatrix.setRow(3, vector<long double>({ 0,	0.,			0,			1. }));
	return rotationMatrix;
}

Matrix MatrixUtil::rotateAroundZ(double angle, int n, int m) {
	Matrix rotationMatrix = Matrix(n, m);
	rotationMatrix.setRow(0, vector<long double>({ cos(angle),	sin(angle),	0,	0.}));
	rotationMatrix.setRow(1, vector<long double>({ -sin(angle),	cos(angle),	0,	0. }));
	rotationMatrix.setRow(2, vector<long double>({ 0,			0,			1,	0. }));
	rotationMatrix.setRow(3, vector<long double>({ 0,			0.,			0,	1. }));
	return rotationMatrix;
}

Matrix MatrixUtil::Mirroring_YZ(int n, int m) {
	Matrix mirrorMatrix = Matrix(n, m);
	mirrorMatrix.setRow(0, vector<long double>({ -1, 0, 0, 0 }));
	mirrorMatrix.setRow(1, vector<long double>({ 0, 1, 0, 0 }));
	mirrorMatrix.setRow(2, vector<long double>({ 0, 0, 1, 0 }));
	mirrorMatrix.setRow(3, vector<long double>({ 0, 0, 0, 1 }));
	return mirrorMatrix;
}

Matrix MatrixUtil::Mirroring_XY(int n, int m) {
	Matrix mirrorMatrix = Matrix(n, m);
	mirrorMatrix.setRow(0, vector<long double>({ 1, 0, 0, 0 }));
	mirrorMatrix.setRow(1, vector<long double>({ 0, 1, 0, 0 }));
	mirrorMatrix.setRow(2, vector<long double>({ 0, 0, -1, 0 }));
	mirrorMatrix.setRow(3, vector<long double>({ 0, 0, 0, 1 }));
	return mirrorMatrix;
}

Matrix MatrixUtil::Mirroring_XZ(int n, int m) {
	Matrix mirrorMatrix = Matrix(n, m);
	mirrorMatrix.setRow(0, vector<long double>({ 1, 0, 0, 0 }));
	mirrorMatrix.setRow(1, vector<long double>({ 0, -1, 0, 0 }));
	mirrorMatrix.setRow(2, vector<long double>({ 0, 0, 1, 0 }));
	mirrorMatrix.setRow(3, vector<long double>({ 0, 0, 0, 1 }));
	return mirrorMatrix;
}

Matrix MatrixUtil::vectorMove(vector<long double> v) {
	Matrix moveMatrix = Matrix(4, 4);
	long double x = v[0];
	long double y = v[1];
	long double z = v[2];

	moveMatrix.setRow(0, vector<long double>({ 1, 0, 0, 0 }));
	moveMatrix.setRow(1, vector<long double>({ 0, 1, 0, 0 }));
	moveMatrix.setRow(2, vector<long double>({ 0, 0, 1, 0 }));
	moveMatrix.setRow(3, vector<long double>({ x, y, z, 1 }));
	
	return moveMatrix;
}

Matrix MatrixUtil::vectorMove(long double x, long double y, long double z) {
	Matrix moveMatrix = Matrix(4, 4);

	moveMatrix.setRow(0, vector<long double>({ 1, 0, 0, 0 }));
	moveMatrix.setRow(0, vector<long double>({ 0, 1, 0, 0 }));
	moveMatrix.setRow(0, vector<long double>({ 0, 0, 1, 0 }));
	moveMatrix.setRow(0, vector<long double>({ x, y, z, 1 }));

	return moveMatrix;
}