#pragma once
#include <vector>
#include <iostream>
#include "linearvector.h"
using namespace std;
class matrix
{
public:
	matrix(int m, int n);
	matrix();
	matrix(initializer_list<initializer_list <double >> l);
	int get_row_size();
	int get_col_size();
	void print_matrix(int percision);
	void push_vector(linearvector v);

	linearvector &operator[](int i);
	matrix transpose();
	matrix cholesky();
	linearvector cholesky_solve(linearvector, matrix);

	~matrix();
private:
	vector<linearvector> vectorMatrix;
	int rowSize = 0;
	int colSize = 0;
};

