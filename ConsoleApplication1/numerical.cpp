#include "numerical.h"


numerical::numerical(double(*fxn)(const double x), double aConst, double bConst, double hConst)
{
	f = fxn;
	h = hConst;
	a = aConst;
	b = bConst;
	n = (b - a) / h;

	for (int i = 0; i < n + 1; i++) {
		x.push_back(a + i*h);
		y.push_back(f(x[i]));
	}
}

numerical::numerical(const double xConst[], double const yConst[], int size)
{
	n = size;

	for (int i = 0; i < n + 1; i++) {
		x.push_back(xConst[i]);
		y.push_back(yConst[i]);
	}
	a = x[0];
	b = x[n];
	h = x[1] - x[0];
	f = NULL;
}

numerical::numerical(const numerical & input)
{
	*this = input;
}

numerical::numerical()
{
}

vector <double> numerical::get_x_values()
{
	return x;
}

vector <double> numerical::get_y_values()
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
	return x.size();
}


numerical::~numerical()
{
}

void numerical::print_values(void)
{
	for (int i = 0; i < x.size(); i++) {
		std::cout << "x = " << x[i] << ", y = " << y[i] << std::endl;
	}
}

numerical& numerical::operator=(const numerical & input) {

	a = input.a;
	n = input.n;
	a = input.a;
	b = input.b;
	y = input.y;
	x = input.x;
	f = input.f;
	h = input.h;

	return *this;

}