#pragma once
#include <iostream>
class ode
{
public:
	ode(double (*fc)(double y, double t), double (*FtC)(double y, double t),
		double aC, double bC, double hC, double initC);
	void taylor_method(void);
	void print_wt(void);
	void runga_kutta_four(void);
	~ode();
private:
	double(*f)(double y, double t);
	double(*Ft)(double y, double t);
	double a;
	double b;
	double h;
	double ArraySize;
	double init;
	double *w;
	double *t;

	std::string solveMethod = "NOT SOLVED";
};

