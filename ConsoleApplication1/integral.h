#pragma once
#include "numerical.h"
using namespace std;
enum INTMETHOD {
	NONE,
	ROMBERG
};
class integral
{
public:
	integral(const numerical constFxn);
	void romberg_integration(int n);
	void romberg_integration(double TOL);
	void print_romberg(void);
	double composite_simpson(int n);
	~integral();
private:
	numerical fxn;
	vector<vector <double> > romberg;
	enum INTMETHOD solveMethod;
};

