#include "matrix.h"
#include <iomanip>
#include <cassert>

matrix::matrix(int m, int n)
	: rowSize(m), colSize(n)
{
	linearvector temp(n, 0.0);
	for (int i = 0; i < m; i++) {
		vectorMatrix.push_back(temp);
	}
}
matrix::matrix() {
}
matrix::matrix(initializer_list<initializer_list<double>> l)
{
	int row = 0;
	int col = 0;
	rowSize = l.size();
	linearvector temp;
	for (const auto i : l) {
		for (const auto j : i) {
			temp.push_back(j);
		}
		vectorMatrix.push_back(temp);
		colSize = temp.size();
		temp.clear();
	}
}

int matrix::get_row_size()
{
	return rowSize;
}

int matrix::get_col_size()
{
	return colSize;
}


void matrix::print_matrix(int percision)
{
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			std::cout << std::setprecision(percision) << std::setw(percision + 3) << vectorMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void matrix::push_vector(linearvector v)
{
	vectorMatrix.push_back(v);
}

linearvector & matrix::operator[](int i)
{
	return vectorMatrix[i];
}

matrix matrix::transpose()
{
	matrix m(colSize, rowSize);
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			m[i][j] = vectorMatrix[j][i];
		}
	}
	return m;
}


matrix matrix::cholesky()
{
	assert(colSize == rowSize);
	matrix l(rowSize, colSize);
	l[0][0] = sqrt(vectorMatrix[0][0]);
	double term = 0;
	int n = rowSize;
	for (int j = 1; j < n; j++) {
		l[j][0] = vectorMatrix[j][0] / l[0][0];
	}
	l.print_matrix(8);
	cout << endl;
	for (int i = 1; i < n; i++) {
		for (int j = i; j < n; j++) {
			term = 0;
			if (i == j) {
				for (int k = 0; k < i; k++) {
					double a = l[i][k];
					term += a * a;
				}
				l[i][i] = sqrt(vectorMatrix[i][i] - term);
			}
			else {
				if (j == 3) {

				}
				for (int k = 0; k <= i - 1; k++) {
					double a = l[j][k];
					double b = l[i][k];
					term += a * b;
				}
				l[j][i] = (vectorMatrix[j][i] - term) / l[i][i];
				l.print_matrix(8);
				cout << endl;
			}
		}
	}
	term = 0;
	for (int k = 0; k < n - 1; k++) {
		double a = l[n - 1][k];
		term += a * a;
	}

	l[n - 1][n - 1] = sqrt(vectorMatrix[n - 1][n - 1] - term);
	return l;
}

linearvector matrix::cholesky_solve(linearvector b, matrix l)
{

	int n = l[0].size();
	linearvector y(b.size());
	matrix lt = l.transpose();
	linearvector x(n);
	double term = 0;
	assert(b.size() > 0);
	assert(vectorMatrix[0].size() == b.size());
	y[0] = b[0] / l[0][0];
	for (int i = 1; i < n; i++) {
		term = 0;
		for (int j = 0; j <= i-1; j++) {
			term += l[i][j] * y[j];
			y[i] = (b[i] - term) / l[i][i];
		}
	}
	x[n - 1] = y[n - 1] / l[n - 1][n - 1];
	for (int i = n -2; i >= 0; i--) {
		term = 0;
		for (int j = i + 1; j < n; j++) {
			term += l[j][i] * x[j];
		}
		x[i] = (y[i] - term) / l[i][i];
	}
	return x;
}


matrix::~matrix()
{
}
