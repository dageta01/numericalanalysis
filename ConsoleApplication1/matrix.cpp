#include "matrix.h"



matrix::matrix(int m, int n)
	: rowSize(m), colSize(n)
{
	linearvector temp(n, 0.0);
	for (int i = 0; i < m; i++) {
		vectorMatrix.push_back(temp);
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

void matrix::print_matrix()
{
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			std::cout << vectorMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


matrix::~matrix()
{
}
