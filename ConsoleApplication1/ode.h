#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef enum {
	UNSOLVED,
	TAYLOR,
	RKOF,
	RKF,
	RKFERROR
}METHOD;
class ode
{
public:
	ode(double (*fc)(double y, double t), double (*FtC)(double y, double t),
		double aC, double bC, double hC, double initC);
	void taylor_method(void);
	void print_wt(void);
	void runge_kutta_four(void);
	void runge_kutte_fehlberg(const double hMIN, const double hMAX, const double TOL);
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
	METHOD solveMethod = UNSOLVED;
};

