#pragma once
#include <vector>
#include <iostream>

class linearvector
{
public:
	linearvector();
	linearvector(int size);
	linearvector(int size, double num);
	linearvector(std::vector<double> u);
	void set(int i, double num);
	const int size(void);
	void resize(int size);
	void clear();
	void push_back(double num);
	~linearvector();

	linearvector& operator=(const linearvector& u);
	linearvector& operator+(const linearvector& u);
	double operator*(const linearvector& u);
	double &operator[](const int i);
	linearvector& operator*(const double a);
	friend std::ostream & operator<<(std::ostream &out, const linearvector &u);

private:
	std::vector<double> v;	
};

linearvector operator*(double a, linearvector u);

