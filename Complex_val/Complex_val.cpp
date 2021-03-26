
#include <iostream>
#include <clocale>


class Complex
{
private:
	int re;
	int im;
public:
	class Complex(int _re, int _im) :
		re(_re), im(_im) 
	{
		std::cout << "Просто выведено: ";
	}
	Complex(const Complex &complex) :
		re(complex.re),
		im(complex.im)
	{
		std::cout << "Прошло через конструктор копирования: ";
	}
	int getre();
	int getim();

};

int Complex::getre() { return re; }
int Complex::getim() { return im; }

int main()
{
	setlocale(LC_ALL, "RUS");
	std::cout << "Тест ввода, вывода и конструкторов копирования" << std::endl;
	int i, k;
	std::cout << "Введите вещественную часть" << std::endl;
	std::cin >> i;
	std::cout << "Введите мнимую часть" << std::endl;
	std::cin >> k;
	Complex c0 = Complex(i, k);
	std::cout << "0.5 sposob: " << c0.getre() << " + " << c0.getim() << "i" << std::endl;
	Complex c1 = Complex(6, 5);
	std::cout << "1 sposob: " << c1.getre() << " + " << c1.getim() << "i" << std::endl;
	Complex c2(Complex(7, 2));
	std::cout << "2 sposob: " << c2.getre() << " + " << c2.getim() << "i" << std::endl;
	Complex c3(3,8);
	std::cout << "3 sposob: " << c3.getre() << " + " << c3.getim() << "i" << std::endl;
	Complex c4(c1);
	std::cout << "4 sposob: " << c4.getre() << " + " << c4.getim() << "i" << std::endl;
	Complex c5 = c2;
	std::cout << "5 sposob: " << c5.getre() << " + " << c5.getim() << "i" << std::endl;
	system("pause");
}


