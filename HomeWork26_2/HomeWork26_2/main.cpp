#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class BusStop
{
	enum { empty = -1, full = 15 };
	int bus[full];
	int top;
public:
	BusStop() : top(empty) {};
	void push(int value);
	void pop();
	int Top();
};

void BusStop::push(int value)
{
	if (++top < full)
	{
		bus[top] = value;
	}
	else
	{
		cout << "No free place!" << endl;
	}
}

void BusStop::pop()
{
	if (top != -1)
	{
		bus[top--] = -1;
	}
	else
	{
		cout << "Bus empty: ";
	}
}

int BusStop::Top()
{
	if (top != -1)
	{
		return bus[top];
	}
	else
	{
		return 0;
	}
}

void main()
{
	setlocale(0, "");
	srand(time(NULL));

	BusStop Sputnik;
	int max_place = 15;
	int free_place = rand() % 16;

	cout << "\t\t\tОстановка \"СПУТНИК\"." << endl << endl;
	float passengers_time;
	float minibus_time;
	cout << "Введите среднее время между появлением пассажиров: ";
	cin >> passengers_time;
	cout << "Введите среднее время между появлением маршруток: ";
	cin >> minibus_time;
	int people_on_busstop = minibus_time / passengers_time + 0.5;
	cout << "\nСколько человек придут на остановку за это время: " << people_on_busstop << endl;
	cout << endl;
	cout << "Чтобы на остановке не находилось больше " << people_on_busstop << " человек(а)";
	cout << " среднее время появления \nмаршрутки не реже: " << people_on_busstop * passengers_time << " минут." << endl;
	cout << "\nСвободный мест в маршрутке: " << free_place << endl;
	
	if (free_place == 0)
	{
		cout << "Нет свободный мест! Ждите следущую маршрутку..." << endl;
	}
	else if (people_on_busstop > free_place)
	{
		for (int i = max_place - free_place; i > 0; i--)
		{
			Sputnik.push(1);
		}
		for (int i = free_place; i > 0; i--)
		{
			Sputnik.push(1);
			cout << Sputnik.Top() << ' ';
		}
		cout << "\nНа остановке осталось " << people_on_busstop - free_place << "человек." << endl;
	}
	else
	{
		for (int i = max_place - free_place; i > 0; i--)
		{
			Sputnik.push(1);
		}
		for (int i = free_place; i > 0; i--)
		{
			Sputnik.push(1);
			cout << Sputnik.Top() << ' ';
		}
		cout << "\nНа остановке осталось 0 человек." << endl;
		cout << "Свободных мест осталось " << free_place - people_on_busstop << endl;		
	}
	cout << endl;
}




