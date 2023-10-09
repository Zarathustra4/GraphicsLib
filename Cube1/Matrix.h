#pragma once
#include <vector>

using std::vector;

class Matrix
{
private:
	int n; //rows
	int m; //cols
	vector<int> shape;
	vector<vector<long double>> M; //the matrix itself

public:
	Matrix(int n, int m, vector<vector<long double>> M); //user sets dimentionality and the matrix

	Matrix(int n, int m); //fills matrix by zeros

	Matrix(); //creates empty matrix

	~Matrix();

	void setMatrix(vector<vector<long double>> M);

	vector<int> getShape();

	void setValue(int i, int j, long double value);

	void setRow(int i, vector<long double> row);

	void printMatrix();

	void getMatrix(vector<vector<long double>>& M);

	long double get(int i, int j);

	vector<vector<long double>> getMatrix();
};

