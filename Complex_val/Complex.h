#pragma once
#include "String.h"

class Complex
{
private:
	int re;
	int im;
public:
	Complex();
	Complex(int _re, int _im);
	Complex(const Complex& complex);
	int getre();
	int getim();
};

