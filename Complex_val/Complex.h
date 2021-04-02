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
	int getre() const;
	int getim() const;
	void setre(int);
	void setim(int);
	Complex operator+(const Complex& b);
	Complex(int _re);

};

