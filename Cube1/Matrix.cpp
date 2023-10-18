#include "Matrix.h"
#include <iostream>
#include <vector>

using std::vector;

Matrix::Matrix(int n, int m, vector<vector<double>> M) :
    n(n),
    m(m),
    shape(vector<int>({ n, m })),
    M(M)
{
}

Matrix::Matrix(int n, int m) :
    n(n),
    m(m),
    shape(vector<int>({ n, m })),
    M(vector<vector<double>>(n, vector<double>(m)))
{
}

Matrix::Matrix() :
    n(0),
    m(0),
    shape(vector<int>(2)),
    M(vector<vector<double>>())
{
}

Matrix::~Matrix() {}

vector<int> Matrix::getShape() {
    return shape;
}

void Matrix::setValue(int i, int j, double value) {
    if (i >= 0 && i < n && j >= 0 && j < m) {
        M[i][j] = value;
    }
    else {
        std::cerr << "Index out of range." << std::endl;
    }
}

void Matrix::setMatrix(vector<vector<double>> M) {
    this->M = M;
}

void Matrix::printMatrix() {
    std::cout << "------------------------" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << M[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void Matrix::getMatrix(vector<vector<double>>& M) {
    M = this->M;
}

vector<vector<double>> Matrix::getMatrix() {
    return this->M;
}

double Matrix::get(int i, int j) {
    return M[i][j];
}

void Matrix::setRow(int i, vector<double> row) {
    if (row.size() != this->m) {
        std::cerr << "Length of the row differs from length of Matrix rows!!!\n";
        return;
    }

    if (i < 0 or i > n) {
        std::cerr << "Incorrect row index" << i 
            << "; The  number of rows = " << this->n << "!!!\n";
    }

    for (int j = 0; j < row.size(); j++) {
        M[i][j] = row[j];
    }
}

vector<double> Matrix::getRow(int i) {
    if (i < 0 or i > M.size()) {
        std::cerr << "The index out of range" << std::endl;
    }
    return M[i];
}