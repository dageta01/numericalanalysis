#include "numerical.h"



numerical::numerical(double(*fxn)(const double x), double aConst, double bConst, double hConst)
{
	f = fxn;
	h = hConst;
	a = aConst;
	b = bConst;
	ArraySize = (b - a) / h + 1;
	x = new double[ArraySize];
	y = new double[ArraySize];
	for (int i = 0; i < ArraySize; i++) {
		x[i] = a + i*h;
		y[i] = f(x[i]);
	}
}

numerical::numerical(const double xConst[], double const yConst[])
{
	f = NULL;
	x = new double[sizeof(xConst) / sizeof(xConst[0])];
}
numerical::~numerical()
{
}

void numerical::print_values(void)
{
	for (int i = 0; i < ArraySize; i++) {
		std::cout << "x = " << x[i] << ", y = " << y[i] << std::endl;
	}
}
