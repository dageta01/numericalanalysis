// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "numerical.h"
#include "ode.h"
#include <math.h>

double f(double x);

double f2(double y, double t);
double f2p(double y, double t);

int main()
{
	
	//numerical n(f, 1, 2, 0.1);
	//numerical n2(n);
	//n.print_values();
	//n2.print_values();
	//double p = n.bisection_algorithm(0.00001);
	//std::cout << p << std::endl;
	ode o(f2, f2p, 1.0, 2.0, 0.1, -1.0 / log(2.0));
	o.runga_kutta_four();
	o.print_wt();
	std::getchar();
    return 0;
}

double f(double x) {
	return 1 - 2*x;
}

double f2(double y, double t) {
	return y*y / (1 + t);
}
double f2p(double y, double t) {
	return 1 / (y + 1);
}