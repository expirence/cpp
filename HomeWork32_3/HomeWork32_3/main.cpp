#include <iostream>
using namespace std;

class Figure
{
public:
	virtual void Square() = 0;
};

class Rectangle : public Figure
{
	double a, b;
public:
	Rectangle(double a_ = 1, double b_ = 1) :a(a_), b(b_) {}
	virtual void Square()
	{
		cout << "Rectangle square: " << a * b << endl;
	}
};

class Rectangular_triangle : public Figure
{
	double a, b;
public:
	Rectangular_triangle(double a_ = 1, double b_ = 1) :a(a_), b(b_) {}
	virtual void Square()
	{
		cout << "Rectangular triangle square: " << (a * b) / 2 << endl;
	}
};

class Circle : public Figure
{
	const double pi = 3.14;
	double r;
public:
	Circle(double r_ = 1) :r(r_) {}
	virtual void Square()
	{
		cout << "Circle square: " << pi * pow(r, 2) << endl;
	}
};

class Trapeze : public Figure
{
	double a, b, h;
public:
	Trapeze(double a_ = 1, double b_ = 1, double h_ = 1) :a(a_), b(b_), h(h_) {}
	virtual void Square()
	{
		cout << "Trapeze triangle square: " << (a * b) / 2 << endl;
	}
};

void main()
{
	//Figure *figure[4] = {new Rectangle(2, 3), new Rectangular_triangle(3),new Ñircle(1.5), new Trapeze(4) };
	Figure &rect = Rectangle(2, 3);
	rect.Square();
	Figure &rect_trian = Rectangular_triangle(3);
	rect_trian.Square();
	Figure &circ = Circle(1.5);
	circ.Square();
	Figure &trup = Trapeze(4);
	trup.Square();
	cout << "--------------------------------\n";
	cout << endl;

	Figure* figure[4] = { &rect, &rect_trian, &trup, &circ };	
	for (int i = 0; i < 4; i++)
	{
		figure[i]->Square();
	}
	cout << endl << endl;
}