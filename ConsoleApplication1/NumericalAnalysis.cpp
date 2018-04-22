// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "numerical.h"
#include "ode.h"
#include <cmath>
#include <vector>
#include "integral.h"
#include "matrix.h"
#include "linearvector.h"

#define PI 3.141592653589798323846
double f(double x);

double f2(double, double);
double f2p(double, double);
double factual(double t);
double rTest(double x);
int main()
{
	matrix m(
		{	{4., 1., 1., 1.},
			{1., 3., 0., -1.},
			{1., 0., 2., 1.},
			{1., -1., 1., 4.}
		});
	//m.print_matrix();
	matrix n = m.cholesky();
	n.print_matrix(3);
	//numerical n(f, 1, 2, 0.1);
	//integral i(n);
//	i.romberg_integration(10);
	//i.print_romberg();
	//cout << i.composite_simpson(20) << endl;
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
	
#ifdef DEBUG
	ode o(f2, f2p, 1.0, 2.0, 0.1, 1);
	o.runge_kutte_fehlberg(0.0005, 0.5, 0.000000000001);
	o.real_compare(factual);
#endif // DEBUG


	std::getchar();
    return 0;
}

double f(double x) {
	return x;
}

double rTest(double x) {
	return sin(x);
}
double f2(double t, double y) {
	return y*t;
}
double f2p(double t, double y) {
	return y;
}

double factual(double t) {
	return exp(1.0 / 2.0 * (-1.0 + t * t));
}