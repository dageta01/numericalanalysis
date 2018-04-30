#include "integral.h"



integral::integral(const numerical constFxn)
{
	fxn = constFxn;
}


void integral::romberg_integration(int n)
{
	double a = fxn.get_a();
	double b = fxn.get_b();
	double h = b - a;
	double sum = 0; 
	double term = 0;

	vector <double> tempR;
	tempR.push_back(0.5 * h * (fxn.funct(a) + fxn.funct(b)));
	romberg.push_back(tempR);
	for (int i = 1; i <= n; i++) {
		sum = 0;
		for (int k = 1; k <= pow(2.0, i - 1.0);k++) {
			sum += fxn.funct(a + (k - 0.5)*h); 
		}
		tempR.clear();
		tempR.push_back(0.5*(romberg.back()[0] + h * sum));
		romberg.push_back(tempR);
		for (int j = 1; j <= i; j++) {
			term = romberg.back()[j - 1];
			term += (romberg.back()[j - 1] - romberg[i - 1][j - 1]) / (pow(4.0, j) - 1.0);
			romberg.back().push_back(term);

		}
		h /= 2.0;
	}
}

void integral::romberg_integration(double TOL)
{
	double a = fxn.get_a();
	double b = fxn.get_b();
	double h = b - a;
	double sum = 0;
	double term = 0;
	bool done = false;
	vector <double> tempR;
	tempR.push_back(0.5 * h * (fxn.funct(a) + fxn.funct(b)));
	romberg.push_back(tempR);
	for (int i = 1; done != true; i++) {
		sum = 0;
		for (int k = 1; k <= pow(2.0, i - 1.0); k++) {
			sum += fxn.funct(a + (k - 0.5)*h);
		}
		tempR.clear();
		tempR.push_back(0.5*(romberg.back()[0] + h * sum));
		romberg.push_back(tempR);
		for (int j = 1; j <= i; j++) {
			term = romberg.back()[j - 1];
			term += (romberg.back()[j - 1] - romberg[i - 1][j - 1]) / (pow(4.0, j) - 1.0);
			romberg.back().push_back(term);

		}
		if (i > 2 && fabs(romberg[i - 2][i - 2] - romberg[i - 1][i - 1]) <= TOL) {
			if (abs(romberg[i - 1][i - 1] - romberg[i][i] <= TOL)) {
				done = true;
			}
		}
		h /= 2.0;
	}
}
void integral::print_romberg(void)
{
	for (int i = 0; i < romberg.size(); i++) {
		for (int j = 0; j < romberg[i].size(); j++) {
			cout << setprecision(9) << setw(12)  << romberg[i][j] << "	";
		}
		cout << endl;
	}
}

double integral::composite_simpson(int n)
{
	double b = fxn.get_b();
	double a = fxn.get_a();
	double h = (b - a) / n;

	double x0, x1, x2, x;
	x0 = fxn.funct(a) + fxn.funct(b);
	x1 = 0; x2 = 0;
	for (int i = 1; i < n; i++) {
		x = a + i * h;
		if (i % 2) {
			x1 = x1 + fxn.funct(x);
		}
		else {
			x2 = x2 + fxn.funct(x);
		}
	}
	return h * (x0 + 2.0*x2 + 4 * x1) / 3.0;
}

integral::~integral()
{
}
