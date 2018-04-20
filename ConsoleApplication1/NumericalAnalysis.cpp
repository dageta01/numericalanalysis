// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "numerical.h"
#include "ode.h"
#include <math.h>
#include <vector>

double f(double x);

double f2(double, double);
double f2p(double, double);
double factual(double t);
int main()
{
	
	numerical n(f, 1, 2, 0.1);
	numerical n2(n);
	/*
	n.print_values();
	n2.print_values();
	double p = n.bisection_algorithm(0.00001);
	std::vector <double> test = n.get_x_values();
	std::cout << test.back() << std::endl;
	*/
	//std::cout << p << std::endl;
	
	ode o(f2, f2p, 1.0, 2.0, 0.1, 1);
	o.runge_kutte_fehlberg(0.005,0.5,0.01);
	o.real_compare(factual);

	std::getchar();
    return 0;
}

double f(double x) {
	return 1 - 2*x;
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