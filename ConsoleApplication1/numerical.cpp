#include "numerical.h"


numerical::numerical(double(*fxn)(const double x), double aConst, double bConst, double hConst)
{
	f = fxn;
	h = hConst;
	a = aConst;
	b = bConst;
	ArraySize = (b - a) / h + 1;
	x = new double[ArraySize + 1];
	y = new double[ArraySize + 1];
	for (int i = 0; i < ArraySize + 1; i++) {
		x[i] = a + i*h;
		y[i] = f(x[i]);
	}
}

numerical::numerical(const double xConst[], double const yConst[], int size)
{
	ArraySize = size;
	x = new double[ArraySize + 1];
	y = new double[ArraySize + 1];
	for (int i = 0; i < ArraySize + 1; i++) {
		x[i] = xConst[i];
		y[i] = yConst[i];
	}
	a = x[0];
	b = x[ArraySize];
	h = x[1] - x[0];
	f = NULL;
}

numerical::numerical(const numerical & n)
{
	*this = n;
}

numerical::numerical()
{
}

double* numerical::get_x_values()
{
	return x;
}

double* numerical::get_y_values()
{
	return y;
}


double numerical::bisection_algorithm(const double TOL)
{
	using namespace std;
	double p, fa, fp;
	p = (a + b) / 2.0;
	fa = f(a);
	fp = f(p);
	if (f == NULL) {
		cout << "The bisection algorithm only works if"
			" the numerical class has been given a"
			" valid function pointer. " << endl;
		return 0xFFFFFFFF;
	}
	while (fp != 0 && (b - a) / 2 > TOL)
	{
		if (fp*fa > 0)
		{
			a = p;
			p = (a + b) / 2.0;
			fa = f(a);
			fp = f(p);
		}
		else
		{
			b = p;
			p = (a + b) / 2.0;
			fa = f(a);
			fp = f(p);
		}
#ifdef SHOWSTEPS
		cout << "Step: " << i << " p = " << p;
#endif
	}
	return p;
}

int numerical::get_size()
{
	return ArraySize;
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

numerical& numerical::operator=(const numerical &n) {

	a = n.a;
	ArraySize = n.ArraySize;
	a = n.a;
	b = n.b;
	y = n.y;
	x = n.x;
	f = n.f;
	h = n.h;

	return *this;

}