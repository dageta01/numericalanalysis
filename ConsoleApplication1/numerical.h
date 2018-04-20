#pragma once
#include <iostream>
class numerical
{
public:
	numerical::numerical(double(*fxn)(const double x), double aConst, double bConst, double hConst);
	numerical::numerical(const double xConst[], const double y[], int size);
	numerical::numerical(const numerical &n);
	numerical::numerical();
	double* get_x_values();
	double* get_y_values();
	double bisection_algorithm(const double TOL);
	int get_size();
	void print_values(void);
	numerical& operator=(const numerical&);
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

