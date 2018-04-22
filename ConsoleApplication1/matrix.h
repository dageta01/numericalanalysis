#pragma once
#include <vector>
#include <iostream>
#include "linearvector.h"
using namespace std;
class matrix
{
public:
	matrix(int m, int n);
	int get_row_size();
	int get_col_size();
	void print_matrix();
	~matrix();
private:
	vector<linearvector> vectorMatrix;
	int rowSize;
	int colSize;
};

