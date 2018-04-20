#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

enum METHOD {
	UNSOLVED,
	TAYLOR,
	RKOF,
	RKF,
	RKFERROR
};

class ode
{
public:
	ode(double (*fc)(double y, double t), double (*FtC)(double y, double t),
		double aC, double bC, double hC, double initC);
	void taylor_method(void);
	void print_wt(void);
	void runge_kutta_four(void);
	void runge_kutte_fehlberg(const double hMIN, const double hMAX, const double TOL);
	void print_solution(void);
	~ode();
private:
	double RKF_Math(double *k);
	double(*f)(double t, double y);
	double(*Ft)(double t, double y);
	double a;
	double b;
	double h;
	double n;
	double init;
	
	//double *w;
	//double *t;
	vector <double> w;
	vector <double> t;
	vector <double> rungKutFehlHValues;
	enum METHOD solveMethod = UNSOLVED;
};

