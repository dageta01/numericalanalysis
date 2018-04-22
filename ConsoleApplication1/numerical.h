#pragma once
#include <iostream>
#include <vector>
#include "iomanip"
using namespace std;
class numerical
{
public:
	numerical::numerical(double(*fxn)(const double x), double aConst, double bConst, double hConst);
	numerical::numerical(const double xConst[], const double y[], int size);
	numerical::numerical(const numerical &n);
	numerical::numerical();
	vector <double> get_x_values();
	vector <double> get_y_values();
	double bisection_algorithm(const double TOL);
	double get_a(void);
	double get_b(void);
	double funct(double x);
	int get_size();
	void print_values(void);
	numerical& operator=(const numerical&);
	~numerical();
private:
	double(*f)(const double x);
	double h;
	int n;
	double a;
	double b;
	//double *y;
	//double *x;
	vector <double> x;
	vector <double> y;

};

