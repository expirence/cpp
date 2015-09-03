#include <iostream>
using namespace std;

class Student
{
protected:
	char* name;
	int age;
	char* curse;
public:
	Student();
	void setInfo();
	void print();
	~Student();
};

Student::Student()
{
	age = 0;
	name = new char[15];
	curse = new char[10];
}

void Student::setInfo()
{
	cout << "What is your name?: ";
	cin >> name;
	cout << "How old are you?: ";
	cin >> age;
	cout << "Which course?: ";
	cin >> curse;
}

void Student::print()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Curse: " << curse << endl;
}

Student::~Student()
{
	delete[] name;
	delete[] curse;
	cout << "Student!\n";
}

class Aspirant : public Student
{
	
public:
	Aspirant() : Student()
	{}
	~Aspirant()
	{
		cout << "Aspirant!\n";
	}
};

void main()
{
	Student A;
	A.setInfo();
	cout << endl;
	A.print();
	cout << "\n\n";
	Aspirant B;
	B.setInfo();
	cout << endl;
	B.print();
}
