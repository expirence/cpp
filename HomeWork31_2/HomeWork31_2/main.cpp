#include <iostream>
using namespace std;

class Passport
{
protected:
	//имя
	char* name;
	//фамилия
	char* soname;
	//дата рождения
	char* date_birthday;
	//место рождения
	char* place_birthday;
	//серия паспорта
	char* serial_number;
	//кем выдан
	char* issued_by;
	//когда выдан
	char* date_issued;
	// имя документа
	char* doc_name;
public:
	Passport();
	~Passport();
	void print();

};

Passport::Passport()
{
	name = new char[10];
	strcpy(name, "Ivan");
	soname = new char[15];
	strcpy(soname, "Ivanosky");
	date_birthday = new char[15];
	strcpy(date_birthday, "01.01.1991");
	place_birthday = new char[15];
	strcpy(place_birthday, "Minsk");
	issued_by = new char[25];
	strcpy(issued_by, "Minsk goverments");
	date_issued = new char[15];
	strcpy(date_issued, "01.05.2015");
	serial_number = new char[15];
	strcpy(serial_number, "BM 1234567");
	doc_name = new char[20];
	strcpy(doc_name, "\tPASSPORT\n");
}

Passport::~Passport()
{
	delete[] name;
	delete[] soname;
	delete[] date_birthday;
	delete[] place_birthday;
	delete[] issued_by;
	delete[] date_issued;
	delete[] serial_number;
	delete[] doc_name;	
}

void Passport::print()
{
	cout << doc_name
		<< "Имя: " << name << endl
		<< "Фамилия: " << soname << endl
		<< "Дата рождения: " << date_birthday << endl
		<< "Место рождения: " << place_birthday << endl
		<< "Дата получения: " << date_issued << endl
		<< "Кем выдан: " << issued_by << endl
		<< "Серия паспорта: " << serial_number << endl;
}

class ForeignPassport : public Passport
{
	char* visa_info;
	int number;
public:
	ForeignPassport() : Passport()
	{
		visa_info = new char[20];
		strcpy(visa_info, "16.08.2015 Gernamy");
		number = 12345;
		strcpy(doc_name, "\t FOREN PASSPORT\n");
	}
	void print()
	{
		Passport::print();
		cout << "Визы: " << visa_info << endl
			<< "Номер заграничного паспорта: " << number << endl;
	}
	~ForeignPassport()
	{
		delete[] visa_info;
	}
};

void main()
{
	setlocale(0, "");
	Passport a;
	a.print();
	cout << endl;
	ForeignPassport b;
	b.print();
}