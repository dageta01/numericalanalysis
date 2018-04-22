#include "linearvector.h"
#include <cassert>


linearvector::linearvector()
{
}

linearvector::linearvector(int size)
{
	v.resize(size, 0);
}

linearvector::linearvector(int size, double num)
{
	v.resize(size, num);
}


linearvector::linearvector(std::vector<double> u)
{
	v = u;
}

void linearvector::set(int i, double num)
{
	assert(i < v.size());
	v[i] = num;
}

const int linearvector::size(void)
{
	return v.size();
}

void linearvector::resize(int size)
{
	v.resize(size);
}

void linearvector::clear()
{
	v.clear();
}

void linearvector::push_back(double num)
{
	v.push_back(num);
}

linearvector::~linearvector()
{
}

linearvector & linearvector::operator=(const linearvector & u)
{
	for (int i = 0; i < u.v.size(); i++) {
		this->v[i] = u.v[i];
	}
	return *this;
}

linearvector& linearvector::operator+(const linearvector& u)
{
	assert(this->v.size() == u.v.size());
	for (int i = 0; this->v.size(); i++) {
		this->v[i] += u.v[i];
	}
	return *this;
}

double linearvector::operator*(const linearvector & u)
{
	assert(this->v.size() == u.v.size());
	double dot = 0;
	for (int i = 0; i < this->v.size(); i++)
	{
		dot += this->v[i] * u.v[i];
	}
	return dot;
}

double & linearvector::operator[](const int i)
{
	return v[i];
}

linearvector & linearvector::operator*(const double a)
{
	for (int i = 0; i < this->v.size(); i++) {
		this->v[i] *= a;
	}
	return *this;
}

std::ostream & operator<<(std::ostream & out, const linearvector & u)
{
	linearvector r = u;
	out << "<";
	for (int i = 0; i < r.size() - 1; i++) {
		out << r[i] << ", ";
	}
	out << r[r.size() - 1] << ">" << std::endl;
	return out;
}

linearvector operator*(double a, linearvector u)
{
	linearvector r = u;
	r = u * a;
	return r;
}
