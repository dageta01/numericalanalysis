#include "ode.h"



ode::ode(double(*fc)(double y, double t), double(*FtC)(double y, double t),
	double aC, double bC, double hC, double initC)
{
	a = aC; b = bC; h = hC; init = initC;
	ArraySize = (b - a) / h;
	f = fc;
	Ft = FtC;
	w = new double[ArraySize + 1];
	t = new double[ArraySize + 1];
}

void ode::taylor_method(void)
{
	double *term = new double[ArraySize + 1];
	w[0] = init;
	t[0] = a;
	term[0] = f(w[0], t[0]);
	term[0] += h / 2.0 * Ft(w[0], t[0]);
	for (int i = 1; i <= ArraySize ; i++) {
		t[i] = t[i - 1] + h;
		w[i] = w[i - 1] + h*term[i - 1];
		term[i] = f(w[i- 1], t[i - 1]);
		term[i] += h / 2.0 * Ft(w[i - 1], t[i - 1]);
	}
}

void ode::print_wt(void)
{
	using namespace std;
	for (int i = 0; i <= ArraySize; i++) {
		cout << "t[" << i << "] = " << t[i];
		cout << ", w[" << i << "] = " << w[i] << endl;
	}
}


ode::~ode()
{
}
