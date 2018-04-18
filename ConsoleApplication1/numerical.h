#pragma once
#include <iostream>
class numerical
{
public:
	numerical::numerical(double(*fxn)(const double x), double aConst, double bConst, double hConst);
	numerical::numerical(const double xConst[], const double y[]);
	void print_values(void);
	~numerical();
private:
	double(*f)(const double x);
	double h;
	int ArraySize;
	double a;
	double b;
	double *y;
	double *x;
	

};

