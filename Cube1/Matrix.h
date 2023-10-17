#pragma once
#include <vector>

using std::vector;

class Matrix
{
private:
	int n; //rows
	int m; //cols
	vector<int> shape;
	vector<vector<double>> M; //the matrix itself

public:
	Matrix(int n, int m, vector<vector<double>> M); //user sets dimentionality and the matrix

	Matrix(int n, int m); //fills matrix by zeros

	Matrix(); //creates empty matrix

	~Matrix();

	void setMatrix(vector<vector<double>> M);

	vector<int> getShape();

	void setValue(int i, int j, double value);

	void setRow(int i, vector<double> row);

	void printMatrix();

	void getMatrix(vector<vector<double>>& M);

	double get(int i, int j);

	vector<vector<double>> getMatrix();

	vector<double> getRow(int i);
};

