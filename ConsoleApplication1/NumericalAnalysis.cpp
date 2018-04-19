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
	
	numerical n(f, 1, 2, 0.1);
	numerical n2(n);
	n.print_values();
	n2.print_values();
	
	ode o(f2, f2p, 1.0, 2.0, 0.1, 2.0);
	o.taylor_method();
	o.print_wt();
	std::getchar();
    return 0;
}

double f(double x) {
	return exp(x);
}

double f2(double y, double t) {
	return (1 + t) / (1 + y);
}
double f2p(double y, double t) {
	return 1 / (y + 1);
}