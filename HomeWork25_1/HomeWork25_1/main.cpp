#include <iostream>
#include <ccomplex>

using namespace std;

class Complex
{
	double real, imag;

public:
	Complex();
	Complex(double re, double im);
	~Complex();

	void print();

	friend ostream &operator<<(ostream &output, Complex &n);

	Complex Complex::operator+ (Complex &n);
	Complex Complex::operator- (Complex &n);
	Complex Complex::operator* (Complex &n);
	Complex Complex::operator/ (Complex &n);
};

Complex::Complex()
{
	real = 0;
	imag = 0;
}

Complex::Complex(double re, double im)
{
	this->real = re;
	this->imag = im;
}

void Complex::print()
{
	cout << "(" << real << ", " << imag << 'i' << ")" << endl;
}

Complex::~Complex()
{
}

Complex Complex::operator+ (Complex &n)
{
	return Complex(real + n.real, imag + n.imag);
}

Complex Complex::operator- (Complex &n)
{
	return Complex(real - n.real, imag - n.imag);
}

Complex Complex::operator* (Complex &n)
{

	return Complex(real * n.real - imag * n.imag, real * n.imag + imag * n.real);

}

Complex Complex::operator/ (Complex &n)
{
	double res = n.real * n.real + n.imag * n.imag;
	return Complex((real * n.real + imag * n.imag) / res, (imag * n.real - real * n.imag) / res);
}

ostream &operator<< (ostream &output, Complex &n)
{
	output << "(" << n.real << ", " << n.imag << 'i' << ")";
	return output;
}

void main(){
	Complex a(1, 3);
	Complex b(4, -5);
	cout << "a = " << a << "; b =" << b << '.' << endl;
	Complex c = a + b;
	c.print();
	cout << "c = " << c << endl;
	cout << "a + b =  " << a + b << endl;
	cout << "a - b =  " << a - b << endl;
	cout << "a * b =  " << a * b << endl;
	cout << "a / b =  " << a / b << endl;
}