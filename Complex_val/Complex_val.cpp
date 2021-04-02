﻿
#include <iostream>
#include <clocale>
#include "Complex.h"

int Complex::getre() const { return re; };
int Complex::getim() const { return im; };
void Complex::setre(int _re)  {re = _re;};
void Complex::setim(int _im) {im = _im;};

Complex Complex::operator+(const Complex& b)
{
	Complex res;
	res.re = re + b.re;
	res.im = im + b.im;
	std::cout << "\x1b[1;35mПройдена перегрузка оператора+\x1b[1;0m" << std::endl;
	return res;
}

Complex::Complex(int _re)
{
	re = _re;
	im = 0;
	std::cout << "\x1b[1;30mПройден конструктор преобразования типа\x1b[1;0m" << std::endl;
}

Complex::Complex()
{
	re = 0;
	im = 0;
	std::cout << "\x1b[1;34mПройден конструктор по умолчанию\x1b[1;0m" << std::endl;
}

Complex::Complex(int _re, int _im)
{
	re = _re;
	im = _im;
	std::cout << "\x1b[1;33mПройден конструктор инициализации\x1b[1;0m" << std::endl;
}


Complex::Complex(const Complex& complex)
{
	re = complex.re;
	im = complex.im;
	std::cout << "\x1b[1;36mПройден конструктор копирования\x1b[1;0m" << std::endl;
};

Complex summa(const Complex& complex1, const Complex& complex2)
{
	Complex c;
	c.setre(complex1.getre() + complex2.getre());
	c.setim(complex1.getim() + complex2.getim());
	std::cout << "\x1b[1;32mФункция сложения пройдена\x1b[0m" << std::endl;
	return c;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int re, im;
	std::cout << "Введите вещественную часть" << std::endl;
	std::cin >> re;
	std::cout << "Введите мнимую часть" << std::endl;
	std::cin >> im;
	Complex a(re, im);
	std::cout << "Первое число: " << a.getre() << "+" << a.getim() << "i" << std::endl;
	Complex b(a);
	std::cout << "Второе число: " << b.getre() << "+" << b.getim() << "i" << std::endl;
	Complex c = summa(a, b);
	std::cout << "Результат сложения этих двух чисел через функцию: " << c.getre() << "+" << c.getim() << "i" << std::endl;
	Complex d = a + c;
	std::cout << "Результат сложения первого числа и предыдущего результата: " << d.getre() << "+" << d.getim() << "i" << std::endl;
	Complex k = d + 3;
	std::cout << "Результат сложения предыдущего результата и числа 3: " << k.getre() << "+" << k.getim() << "i" << std::endl;
	system("pause");
}


