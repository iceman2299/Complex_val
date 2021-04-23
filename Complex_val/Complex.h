#pragma once
#include "String.h"
#include <iostream>

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
	Complex operator-(const Complex& b);
	Complex operator*(const Complex& b);
	Complex operator/(const Complex& b);
	friend std::ostream& operator<< (std::ostream& os, const Complex& a);
	friend std::istream& operator>> (std::istream& is, Complex& a);
	Complex(int _re);

};

