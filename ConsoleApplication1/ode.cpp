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
	solveMethod = "Taylor Method";
}

void ode::print_wt(void)
{
	using namespace std;
	for (int i = 0; i <= ArraySize; i++) {
		cout << "t[" << i << "] = " << t[i];
		cout << ", w[" << i << "] = " << w[i] << endl;
	}
}

void ode::runga_kutta_four(void)
{
	int n = (b - a) / h;
	w[0] = init;
	t[0] = a;
	double *k = new double[4];
	double term;

	for (int i = 1; i <= n; i++) {
		k[0] = h*f(w[i - 1], t[i - 1]);
		k[0] = h*f(w[i - 1], t[i - 1i);
		k[1] = h*f(w[i - 1] + h, t[i - 1] + k[0] / 2.0);
		k[2] = h*f(w[i - 1] + h / 2.0, t[i - 1] + k[1] / 2.0);
		k[3] = h*f(w[i - 1] + h, t[i - 1] + k[2]);

		term = (k[0] + 2 * k[1] + 2 * k[2] + k[3]) / 6;
		w[i] = w[i - 1] + term;
		t[i] = t[i - 1] + h;
	}
	solveMethod = "Runga Kutta Order Four";
}


ode::~ode()
{
}
