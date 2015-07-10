#include <iostream>
#include <stdarg.h>

using namespace std;

class MyPrintf
{
public:
	MyPrintf(char * myStr, ...);
	~MyPrintf();
};

MyPrintf::MyPrintf(char * myString, ...)
{
	va_list parameters;
	va_start(parameters, myString);
	//пока не дойдем до конца управляющей строки - не останавливаемся.
	while (*myString != '\0')
	{
		if (*myString == '%')
		{
			myString++;

			if (*myString == '%')
			{
				cout << '%';
			}
			else if (*myString == 's')
			{
				cout << va_arg(parameters, char*);
			}
			else if (*myString == 'd')
			{
				cout << va_arg(parameters, int);
			}
			else if (*myString == 'f')
			{
				cout << va_arg(parameters, double);
			}
		}
		else
		{
			cout << *myString;
		}

		myString++;
	}

	va_end(parameters);
}

MyPrintf::~MyPrintf()
{

}

void main()
{
	MyPrintf("Hello world! My name is %s.\nI'am %d years old and %f I will be %d years old! ;)\n", "Sergey Ivanenko", 26, 11.07, 27);
}