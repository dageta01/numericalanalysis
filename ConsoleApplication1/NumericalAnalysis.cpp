// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "numerical.h"
#include <math.h>

double f(double x);

int main()
{
	numerical n(f, 1, 2, 0.1);
	n.print_values();
	std::getchar();
    return 0;
}

double f(double x) {
	return exp(x);
}

