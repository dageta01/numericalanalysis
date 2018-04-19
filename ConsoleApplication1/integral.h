#pragma once
#include "numerical.h"
class integral
{
public:
	integral(const numerical n);
	~integral();
private:
	numerical fxn;
};

