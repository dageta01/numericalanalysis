// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "numerical.h"
#include "ode.h"
#include <math.h>

double f(double x);

double f2(double, double);
double f2p(double, double);

int main()
{
	
	//numerical n(f, 1, 2, 0.1);
	//numerical n2(n);
	//n.print_values();
	//n2.print_values();
	//double p = n.bisection_algorithm(0.00001);
	//std::cout << p << std::endl;
	ode o(f2, f2p, 1.0, 2.0, 0.1, -1.0 / log(2.0));
	o.runge_kutte_fehlberg(0.01, 0.05, 0.000000001);
	o.print_wt();
	std::getchar();
    return 0;
}

double f(double x) {
	return 1 - 2*x;
}

double f2(double t, double y) {
	return y*y / (1 + t);
}
double f2p(double t, double y) {
	return 1 / (y + 1);
}