#include <iostream>
#include <cmath>
using namespace std;

class Equation
{
public:
	virtual void roots() = 0;
};

class Linear_equation :public Equation
{
	/*
		a * x + b = 0. Количество решений зависит от параметров a и b:
		Если a = b = 0, то уравнение имеет бесконечное множество решений, поскольку  x * 0 = 0;
		Если a = 0, b != 0, то уравнение не имеет решений, поскольку 0 * x = - b != 0;
		Если a != 0, то уравнение имеет единственное решение x = a / -b;
	*/
	double a, b;
public:
	Linear_equation(double a_ = 1, double b_ = 1) : a(a_), b(b_) {}
	virtual void roots();
};

void Linear_equation::roots()
{
	if (a == 0 && b != 0) //if(!a && b)
	{
		cout << "The equation has no solution!" << endl << endl;
	}
	else
	{
		if (!b)
		{
			cout << "Root: infinity...\n\n";
		}
		else
		{
			cout << "Root: " << a / (-b) << endl;
		}
	}
}

class Quadratic_equation :public Equation
{
	/*
		Квадратное уравнение — алгебраическое уравнение общего вида
		ax^2 + bx + c = 0,
		где x — свободная переменная, a, b, c — коэффициенты, причём a =! 0.
		D = b^2 - 4ac.
		D > 0 - два корня: x1,2 = -b +- sqrt(b*b - 4ac) / 2a;
		D = 0 - один корень: x1=x2=-b / 2a
		D < 0 - корней нет;
	*/
	double a, b, c, D;
public:
	Quadratic_equation(double a_ = 1, double b_ = 1, double c_ = 1) : a(a_), b(b_), c(c_)
	{
		if (a == 0)
		{
			cout << "\'a\' must be more 0\n";
		}
		else
		{
			D = pow(b, 2) - 4 * a * c;
		}
	}
	virtual void roots();
};

void Quadratic_equation::roots()
{
	if (D > 0)
	{
		cout << "Discriminant = " << D << endl << endl;
		cout << "First root: " << -b - sqrt(pow(b, 2) - 4 * a * c) << endl;
		cout << "Second root: " << -b + sqrt(pow(b, 2) - 4 * a * c) << endl;
	}
	else if (D == 0)
	{
		cout << "Discriminant = " << D << endl << endl;
		cout << "One root: " << (-b) / 2 * a << endl;
	}
	else
	{
		if (a == 0)
		{
			cout << "No solution!!!" << endl << endl;
		}
		else
		{
			cout << "Discriminant = " << D << endl << endl;
			cout << "No root!" << endl;
		}
	}
}

void main()
{
	Equation* root[2] = { new Linear_equation(3, -2), new Quadratic_equation(3, -2, -1) };
	for (int i = 0; i < 2; i++)
	{
		root[i]->roots();
		cout << endl;
	}
}