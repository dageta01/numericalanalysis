// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "numerical.h"
#include "ode.h"
#include <cmath>
#include <vector>
#include <iomanip>
#include "integral.h"
#include "matrix.h"
#include "linearvector.h"

#define P5
#define PI 3.141592653589798323846
#define SQRTPI 1.772453850905516027298
double problem3(double, double);
double problem3dif(double, double);
double erfterm(double x);
double problem2(double, double);
double problem2sol(double t);
double problem4(double, double);
double problem4actual(double);
int main()
{
	/*
	matrix m(
		{	{4., 1., 1., 1.},
			{1., 3., 0., -1.},
			{1., 0., 2., 1.},
			{1., -1., 1., 4.}
		});
	m.print_matrix();
	
	matrix n = m.cholesky();
	n.print_matrix(3);
	*/
	/*
	numerical n(erfterm, 0, 1, 0.1);
	integral i(n);
	i.romberg_integration(0.0000001);
	i.print_romberg();
	cout << i.composite_simpson(200) << endl;
	*/
#ifdef DEBUG
	numerical n(f, 1, 2, 0.1);
	numerical n2(n);
	numerical intTest(f, 0, 2, 0.1);
	n.print_values();
	n2.print_values();
	double p = n.bisection_algorithm(0.00001);
	std::vector <double> test = n.get_x_values();
	std::cout << test.back() << std::endl;

	integral integ(intTest);
	integ.romberg_integration(6);
	integ.print_romberg();
#endif // DEBUG

	//std::cout << p << std::endl;
#ifdef P1
	numerical n(erfterm, 0., 1.0, 0.1);
	integral i(n);
	i.romberg_integration(pow(10, -7));
//	i.print_romberg();
	//cout << setprecision(10) << i.composite_simpson(74) << endl;
	//i.print_romberg();
#endif

#ifdef P2
	ode o(problem2, problem2, 0., 50., 1./12., 0.01);
	o.euler_algorithm();
	o.real_compare(problem2sol);
#endif
#ifdef P3
	ode o(problem3, problem3dif, 0.0, 2.7, 0.01, 48);
	o.taylor_method();
	o.print_solution();
#endif
#ifdef P4
	ode o(problem4, NULL, 1., 3., 0.1, -2);
	o.runge_kutta_fehlberg(0.02, 0.25, pow(10., -4.));
	
	//o.runge_kutta_four();
	//o.print_solution();
	o.real_compare(problem4actual);
#endif
#ifdef P5
	matrix m({
		{4., 1., 1., 1.},
		{1., 3., 0., -1.},
		{1., 0., 2., 1.},
		{1., -1., 1., 4.}
		});
	matrix l = m.cholesky();
	l.print_matrix(8);
	linearvector b;
	b.push_back(2); b.push_back(2);
	b.push_back(1); b.push_back(1);
	cout << l.cholesky_solve(b, l) << endl;
#endif
	std::getchar();
    return 0;
}

double erfterm(double x) {
	return (2. / SQRTPI) * exp(-x * x);
}
double problem2(double t, double p) {
	double r = 0.1, b = 0.02, d = 0.015;
	return r * b*(1. - p);
}
double problem2sol(double t)
{
	return 1. - 0.99*exp(-0.002 * t);
}


double problem3(double t, double v)
{
	double m = 0.11;
	double g = 9.8;
	double k = 0.002;
	return (-m * g - k * v*fabs(v)) / m;
}
double problem3dif(double t, double v) {
	double k = 0.002;
	double m = 0.11;
	double numerator = 2. * k * pow(v, 2.) * problem3(t, v);
	double denom = m * fabs(v);
	return numerator / denom;
}
double problem4(double t, double y)
{
	return (y*y + y) / t;
}
double problem4actual(double t)
{
	return 2. * t / (1. - 2.*t);
}

