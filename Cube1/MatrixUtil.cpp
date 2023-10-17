#include "MatrixUtil.h"
#include <iostream>

#define PI 3.14159265359

void multiply(Matrix A, Matrix B, Matrix& C) {
	const int n = A.getShape()[0];
	const int k = A.getShape()[1];
	const int m = B.getShape()[1];

	double s;
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


vector<double> normalize(vector<double> vec) {
	double length;
	double sum = 0;
	size_t size = vec.size();

	vector<double> normVec = vector<double>(size);

	for (int i = 0; i < size - 1; i++) {
		sum += vec[i] * vec[i];
	}
	std::cout << "sum = " << sum << std::endl;
	length = sqrt(sum);

	for (int i = 0; i < size - 1; i++) {
		normVec[i] /= length;
	}

	return normVec;
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
	vector<vector<double>> matrixI(n, vector<double>(m));
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
	angle = angle * PI / 180;

	Matrix rotationMatrix = Matrix(n, m);
	rotationMatrix.setRow(0, vector<double>({ cos(angle),	0., -sin(angle),	0. }));
	rotationMatrix.setRow(1, vector<double>({ 0,			1,	0,				0. }));
	rotationMatrix.setRow(2, vector<double>({ sin(angle),	0.,	cos(angle),		0. }));
	rotationMatrix.setRow(3, vector<double>({ 0,			0., 0,				1. }));
	return rotationMatrix;
}

Matrix MatrixUtil::rotateAroundX(double angle, int n, int m) {
	angle = angle * PI / 180;

	Matrix rotationMatrix = Matrix(n, m);
	rotationMatrix.setRow(0, vector<double>({ 1,	0.,			0,			0. }));
	rotationMatrix.setRow(1, vector<double>({ 0,	cos(angle),	sin(angle),	0. }));
	rotationMatrix.setRow(2, vector<double>({ 0,	-sin(angle),cos(angle),	0. }));
	rotationMatrix.setRow(3, vector<double>({ 0,	0.,			0,			1. }));
	return rotationMatrix;
}

Matrix MatrixUtil::rotateAroundZ(double angle, int n, int m) {
	angle = angle * PI / 180;

	Matrix rotationMatrix = Matrix(n, m);
	rotationMatrix.setRow(0, vector<double>({ cos(angle),	sin(angle),	0,	0.}));
	rotationMatrix.setRow(1, vector<double>({ -sin(angle),	cos(angle),	0,	0. }));
	rotationMatrix.setRow(2, vector<double>({ 0,			0,			1,	0. }));
	rotationMatrix.setRow(3, vector<double>({ 0,			0.,			0,	1. }));
	return rotationMatrix;
}

Matrix MatrixUtil::Mirroring_YZ(int n, int m) {
	Matrix mirrorMatrix = Matrix(n, m);
	mirrorMatrix.setRow(0, vector<double>({ -1, 0, 0, 0 }));
	mirrorMatrix.setRow(1, vector<double>({ 0, 1, 0, 0 }));
	mirrorMatrix.setRow(2, vector<double>({ 0, 0, 1, 0 }));
	mirrorMatrix.setRow(3, vector<double>({ 0, 0, 0, 1 }));
	return mirrorMatrix;
}

Matrix MatrixUtil::Mirroring_XY(int n, int m) {
	Matrix mirrorMatrix = Matrix(n, m);
	mirrorMatrix.setRow(0, vector<double>({ 1, 0, 0, 0 }));
	mirrorMatrix.setRow(1, vector<double>({ 0, 1, 0, 0 }));
	mirrorMatrix.setRow(2, vector<double>({ 0, 0, -1, 0 }));
	mirrorMatrix.setRow(3, vector<double>({ 0, 0, 0, 1 }));
	return mirrorMatrix;
}

Matrix MatrixUtil::Mirroring_XZ(int n, int m) {
	Matrix mirrorMatrix = Matrix(n, m);
	mirrorMatrix.setRow(0, vector<double>({ 1, 0, 0, 0 }));
	mirrorMatrix.setRow(1, vector<double>({ 0, -1, 0, 0 }));
	mirrorMatrix.setRow(2, vector<double>({ 0, 0, 1, 0 }));
	mirrorMatrix.setRow(3, vector<double>({ 0, 0, 0, 1 }));
	return mirrorMatrix;
}

Matrix MatrixUtil::vectorMove(vector<double> v) {
	Matrix moveMatrix = Matrix(4, 4);
	double x = v[0];
	double y = v[1];
	double z = v[2];

	moveMatrix.setRow(0, vector<double>({ 1, 0, 0, 0 }));
	moveMatrix.setRow(1, vector<double>({ 0, 1, 0, 0 }));
	moveMatrix.setRow(2, vector<double>({ 0, 0, 1, 0 }));
	moveMatrix.setRow(3, vector<double>({ x, y, z, 1 }));
	
	return moveMatrix;
}

Matrix MatrixUtil::vectorMove(double x, double y, double z) {
	Matrix moveMatrix = Matrix(4, 4);

	moveMatrix.setRow(0, vector<double>({ 1, 0, 0, 0 }));
	moveMatrix.setRow(1, vector<double>({ 0, 1, 0, 0 }));
	moveMatrix.setRow(2, vector<double>({ 0, 0, 1, 0 }));
	moveMatrix.setRow(3, vector<double>({ x, y, z, 1 }));

	return moveMatrix;
}

Matrix MatrixUtil::scale(double scalar) {
	Matrix moveMatrix = Matrix(4, 4);

	moveMatrix.setRow(0, vector<double>({ scalar,	0,		0,		0 }));
	moveMatrix.setRow(1, vector<double>({ 0,		scalar, 0,		0 }));
	moveMatrix.setRow(2, vector<double>({ 0,		0,		scalar, 0 }));
	moveMatrix.setRow(3, vector<double>({ 0,		0,		0,		1 }));

	return moveMatrix;
}

Matrix MatrixUtil::scaleWithoutMoving(double scalar, vector<double> massCenter) {
	vector<double> moveVector = vector<double>(3);

	for (int i = 0; i < 3; i++) {
		moveVector[i] = -massCenter[i];
	}

	Matrix moveMatrix = MatrixUtil::vectorMove(moveVector);
	Matrix scaleMatrix = MatrixUtil::scale(scalar);
	Matrix returnMoveMatrix = MatrixUtil::vectorMove(massCenter);

	Matrix transMatrix = MatrixUtil::matrixProduct(moveMatrix, scaleMatrix);

	return MatrixUtil::matrixProduct(transMatrix, returnMoveMatrix);
}

Matrix MatrixUtil::rotateAroundEdge(double angle, vector<double> edge) {
	//edge = normalize(edge);

	const double nx = edge[0];
	const double ny = edge[1];
	const double nz = edge[2];

	vector<double> returnVector = edge;
	double alfa = 0, beta = 0;

	if (nz) {
		alfa = atan(ny / nz);
	}
	if (ny* ny + nz * nz) {
		beta = atan(nx / (sqrt(ny * ny + nz * nz)));
	}
	

	returnVector[0] *= -1; returnVector[1] *= -1; returnVector[2] *= -1;
	
	Matrix t1 = MatrixUtil::vectorMove(edge);

	Matrix t2 = MatrixUtil::matrixProduct(
		MatrixUtil::rotateAroundX(alfa),
		MatrixUtil::rotateAroundY(-beta)
	);

	Matrix t3 = MatrixUtil::rotateAroundZ(angle);

	Matrix t4 = MatrixUtil::matrixProduct(
		MatrixUtil::rotateAroundY(beta),
		MatrixUtil::rotateAroundX(-alfa)
	);

	Matrix t5 = MatrixUtil::vectorMove(returnVector);


	Matrix transMatrix = MatrixUtil::matrixProduct(t1, t2);
	transMatrix = MatrixUtil::matrixProduct(transMatrix, t3);
	transMatrix = MatrixUtil::matrixProduct(transMatrix, t4);
	
	return MatrixUtil::matrixProduct(transMatrix, t5);
}


Matrix MatrixUtil::mirrorOnPlane(Matrix plane) {
	vector<double> center = vector<double>(3);

	double sumX = 0, sumY = 0, sumZ = 0;
	for (int i = 0; i < 3; i++) {
		sumX += plane.get(0, i);
		sumY += plane.get(1, i);
		sumZ += plane.get(2, i);
	}
	center[0] = sumX / 3; 
	center[1] = sumY / 3;
	center[2] = sumZ / 3;

	vector<double> moveVec = vector<double>({
		-center[0], -center[1], -center[2]
		});

	Matrix t1 = MatrixUtil::vectorMove(moveVec);
	//TODO complete making tranformation matrix

}