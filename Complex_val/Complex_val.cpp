
#include <iostream>
#include <clocale>
#include "Complex.h"

int Complex::getre() { return re; };
int Complex::getim() { return im; };

Complex::Complex()
{
	re = 0;
	im = 0;
	std::cout << "Пройден конструктор по умолчанию" << std::endl;
}

Complex::Complex(int _re, int _im)
{
	re = _re;
	im = _im;
	std::cout << "Пройден конструктор инициализации" << std::endl;
}


Complex::Complex(const Complex& complex)
{
	re = complex.re;
	im = complex.im;
	std::cout << "Пройден конструктор копирования" << std::endl;
};

Complex summa(Complex complex1, Complex complex2)
{
	Complex c;
	c. = complex1.getre() + complex2.getre();
	c. = complex1.getim() + complex2.getim();
	std::cout << "Функция сложения пройдена" << std::endl;
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
	std::cout << "Результат сложения этих двух чисел: " << c.getre() << "+" << c.getim() << "i" << std::endl;
	system("pause");
}


