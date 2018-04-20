#include "ode.h"



ode::ode(double(*fc)(double y, double t), double(*FtC)(double y, double t),
	double aC, double bC, double hC, double initC)
{
	a = aC; b = bC; h = hC; init = initC;
	n = (b - a) / h;
	f = fc;
	Ft = FtC;
}

void ode::taylor_method(void)
{
	double *term = new double[n + 1];
	w.clear();
	t.clear();
	w.push_back(init);
	t.push_back(a);
	term[0] = f(w[0], t[0]);
	term[0] += h / 2.0 * Ft(t[0], w[0]);
	for (int i = 1; i <= n ; i++) {
		t.push_back(t.back() + h);
		w.push_back(w.back() + h*term[i - 1]);
		term[i] = f(t[i- 1], w.back());
		term[i] += h / 2.0 * Ft(t.back(), w.back());
	}
	solveMethod = TAYLOR;
}

void ode::print_wt(void)
{
	using namespace std;
	for (int i = 0; i < t.size(); i++) {
		cout << "t[" << i << "] = " << t[i];
		cout << ", w[" << i << "] = " << w[i] << endl;
	}
}

void ode::runge_kutta_four(void)
{
	int n = (b - a) / h;
	w.clear();
	t.clear();
	w.push_back(init);
	t.push_back(a);
	double *k = new double[4];
	double term;

	for (int i = 1; i <= n; i++) {
		k[0] = h*f(t.back(), w.back());
		k[1] = h*f(t.back() + h / 2.0, w.back() + k[0] / 2.0);
		k[2] = h*f(t.back() + h / 2.0, w.back() + k[1] / 2.0);
		k[3] = h*f(t.back() + h, w.back() + k[2]);

		term = (k[0] + 2 * k[1] + 2 * k[2] + k[3]) / 6;
		w.push_back(w.back() + term);
		t.push_back(t.back() + h);
	}
	solveMethod = RKOF;
}

void ode::runge_kutte_fehlberg(const double hMIN, const double hMAX, const double TOL)
{
	const double hOld = h;
	h = hMAX;
	double k[6];
	double tempW, del, r;
	w.clear();
	t.clear();
	w.push_back(init);
	t.push_back(a);
	bool flag = true;
	while (flag) {
		r = RKF_Math(k);
		if (r <= TOL) {
			t.push_back(t.back() + h);
			tempW = w.back() + 25.0 / 216.0 * k[0];
			tempW += 1408.0 / 2565.0 * k[2] + 2197.0 / 4104.0 * k[3] - 1.0 / 5.0 * k[4];
			w.push_back(tempW);
			rungKutFehlHValues.push_back(h);
		}
		del = 0.84 * pow(TOL / r, 0.25);

		if (del <= 0.1) {
			h = 0.1 * h;
		} 
		else if (del >= 4) {
			h = 4.0 * h;
		} 
		else {
			h = del * h;
		}

		if (h > hMAX) {
			h = hMAX;
		}

		if (t.back() >= b) {
			solveMethod = RKF;
			flag = 0;
		}
		else if (t.back() + h > b) {
			h = b - t.back();
		}
		else if (h < hMIN) {
			solveMethod = RKFERROR;
			flag = 0;
		}
	}
}


ode::~ode()
{
}

double ode::RKF_Math(double *k)
{
	double funcInputT, funcInputW, r;
	k[0] = h * f(t.back(), w.back());

	funcInputT = t.back() + 1.0 / 4.0 * h;
	funcInputW = w.back() + 1.0 / 4.0 * k[0];

	k[1] = h * f(funcInputT, funcInputW);

	funcInputT = t.back() + 3.0 / 8.0 * h;
	funcInputW = w.back() + 3.0 / 32.0 * k[0] + 9.0 / 32.0 * k[1];

	k[2] = h * f(funcInputT, funcInputW);

	funcInputT = t.back() + 12.0 / 13.0 * h;
	funcInputW = w.back() + 1932.0 / 2197.0 * k[0] - 7200.0 / 2197.0 * k[1];
	funcInputW += 7296.0 / 2197.0 * k[2];

	k[3] = h * f(funcInputT, funcInputW);

	funcInputT = t.back() + h;
	funcInputW = w.back() + 439.0 / 216.0 * k[0] - 8.0 * k[1];
	funcInputW += 3680.0 / 513.0 * k[2] - 845.0 / 4104.0 * k[3];

	k[4] = h * f(funcInputT, funcInputW);

	funcInputT = t.back() + 1.0 / 2.0 * h;
	funcInputW = w.back() - 8.0 / 27.0 * k[0] + 2.0 * k[1] - 3544.0 / 2565.0 * k[2];
	funcInputW += 1859.0 / 4104.0 * k[3] - 11.0 / 40.0 * k[4];

	k[5] = h * f(funcInputT, funcInputW);

	r = 1.0 / 360.0 * k[0] - 128.0 / 4275.0 * k[2];
	r += -2197.0 / 75240.0 * k[3] + 1.0 / 50.0 * k[4] + 2.0 / 55.0 * k[5];
	r = 1 / h * fabs(r);

	return r;
}
