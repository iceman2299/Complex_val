
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
	std::cout << "\x1b[1;35mПройдена перегрузка оператора сложения\x1b[1;0m" << std::endl;
	return res;
}

Complex Complex::operator-(const Complex& b)
{
	Complex res;
	res.re = re - b.re;
	res.im = im - b.im;
	std::cout << "\x1b[1;35mПройдена перегрузка оператора вычитания\x1b[1;0m" << std::endl;
	return res;
}

Complex Complex::operator*(const Complex& b)
{
	Complex res;
	res.re = ((re * b.re) - (im * b.im));
	res.im = ((re * b.im) + (b.re * im));
	std::cout << "\x1b[1;35mПройдена перегрузка оператора умножения\x1b[1;0m" << std::endl;
	return res;
}

Complex Complex::operator/(const Complex& b)
{
	Complex res;
	try
	{
		if ((b.re * b.re + b.im * b.im) == 0)
		throw - 1;
	}
	catch (int errcode)
	{
		std::cerr << "\x1b[1;31mДеление невозможно т.к. в знаменателе образовался ноль\x1b[1;0m" << std::endl;
		res.re = 0;
		res.im = 0;
		return res;
	}
	res.re = ((re * b.re) + (im * b.im)) / (b.re * b.re + b.im * b.im);
	res.im = ((b.re * im) - (re * b.im)) / (b.re * b.re + b.im * b.im);
	std::cout << "\x1b[1;35mПройдена перегрузка оператора деления\x1b[1;0m" << std::endl;
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

std::ostream& operator<<(std::ostream& os, const Complex& a)
{
	std::cout << "\x1b[1;33mОтработала перегрузка вывода: \x1b[0m" << std::endl;
	os << a.re << "+" << a.im << "i" << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Complex& a)
{
	std::cout << "Введите вещественную часть" << std::endl;
	is >> a.re;
	std::cout << "Введите мнимую часть" << std::endl;
	is >> a.im;
	return is;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int re, im;
	std::cout << "\x1b[1;32mВведите первое комплексное число\x1b[0m" << std::endl;
	Complex a;
	std::cin >> a;
	std::cout << "Первое число: " << std::endl << a;
	Complex b(a);
	std::cout << "Второе число: " << std::endl << b;
	Complex c = summa(a, b);
	std::cout << "Результат сложения этих двух чисел через функцию: " << std::endl << c;
	Complex d = a + c;
	std::cout << "Результат сложения первого числа и предыдущего результата: " << std::endl << d;
	std::cout << "\x1b[1;32mВведите еще одно комплексное число для операций\x1b[0m" << std::endl;
	Complex temp;
	std::cin >> temp;
	Complex k = d + temp;
	std::cout << "Результат сложения предыдущего результата и нового числа: "<< std::endl << k;
	Complex n = k - temp;
	std::cout << "Результат вычитания нового числа из предыдущего результата: " << std::endl << n;
	Complex l = n * temp;
	std::cout << "Умножаю предыдущее число на новое: " << std::endl << l;
	Complex m = l / temp;
	std::cout << "Делю предыдущее число на новое: " << std::endl << m;
	system("pause");
}


