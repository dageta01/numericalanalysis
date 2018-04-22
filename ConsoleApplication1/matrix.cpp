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
	for (int i = 1; i < rowSize; i++) {
		l[i][0] = vectorMatrix[i][0] / l[0][0];
	}

	for (int i = 1; i < rowSize - 1; i++) {
		term = 0;
		for (int k = 0; k < i; k++) {
			double a = l[i][k];
			term += a*a;
		}
		l[i][i]= sqrt(vectorMatrix[i][i] - term);
		term = 0;
		for (int j = i + 1; j < rowSize; j++) {
			for (int k = 0; k < i; k++) {
				term += l[j][k] * l[i][k];
			}
			if (j == 3) {
				NULL;
			}
			l[j][i] = (vectorMatrix[j][i] - term)/l[i][i];
		}

	}
	term = 0;
	for (int i = 0; i < rowSize - 1; i++) {
		double a = l[rowSize - 1][i];
		term += l[rowSize - 1][i] * l[rowSize - 1][i];
	}
	l[rowSize - 1][rowSize - 1] = sqrt(vectorMatrix[rowSize - 1][rowSize - 1] - term);
	return l;
}


matrix::~matrix()
{
}
