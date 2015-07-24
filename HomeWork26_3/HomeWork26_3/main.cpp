# include<iostream>
# include<string.h>
# include<time.h>
using namespace std;
class Printer
{
	int * Wait; // очередь
	int * Prioritet; // очередь
	int * Stat; // очередь
	int Max; // мак-й размер очереди
	int Length; // текущий размер очереди
public:
	Printer(int a); // конструктор
	~Printer(); // диструктор
	void Add(int x, int y); // добавление элемента
	void Extract(); // извлечение элемента
	void Clear(); // очистка потока
	bool IsEmpty(); // проверка сущ-ния элементов в очереди
	bool IsFull(); // Проверка на переполнение очереди
	int GetCount(); // кол-во элементов в очереди
	void Show(); // показ на экран очереди
};
Printer::Printer(int a)
{
	Max = a; //получаем размер
	Wait = new int[Max]; //создаем очередь
	Prioritet = new int[Max]; //создаем очередь приоритета
	Stat = new int[Max]; //создаем очередь статистики
	Length = 0; // Изначально очередь пуста
}
Printer :: ~Printer()
{
	delete[] Wait;
	delete[] Prioritet;
	delete[] Stat;
}
bool Printer::IsEmpty()
{
	return Length == 0; // Пуст?
}
bool Printer::IsFull()
{
	return Length == Max; // Полон?
}
void Printer::Add(int x, int y)
{
	if (!IsFull())
	{
		Wait[Length] = x;
		Prioritet[Length] = y;
		Length++;
	}
}
void Printer::Clear()
{
	Length = 0; // Эффективная "очистка" очереди
}
int Printer::GetCount()
{
	return Length; // Количество присутствующих в стеке элементов
}
void Printer::Extract()
{
	// Если в очереди есть элементы, то возвращаем тот,
	// у которого наивысший приоритет и сдвигаем очередь
	if (!IsEmpty()){

		for (int i = 0; i<Length - 1; i++){ //сдвинуть все элементы
			Wait[i] = Wait[i + 1];
			Prioritet[i] = Prioritet[i + 1];
		}

		Length--; //уменьшаем количество
	}
}





void Printer::Show()
{
	time_t t = time(NULL);
	int max_pri = Prioritet[0];
	//а приоритетный индекс = 0
	int pos_max_pri = 0;

	for (int i = 0; i<Length; i++)
	{
		for (int j = Length - 1; j>i; j--)
		{
			if (Prioritet[j] > Prioritet[j - 1])
			{
				max_pri = Prioritet[j - 1];
				Prioritet[j - 1] = Prioritet[j];
				Prioritet[j] = max_pri;
				pos_max_pri = j;
			}

		}
	}
	for (int i = 0; i<Length; i++)
	{

		cout << Wait[i] << " - " << Prioritet[i] << " ";
		cout << "\n";

	}
}
void main()
{
	setlocale(LC_CTYPE, "rus");
	srand(time(0));
	Printer New(25);
	int s;
	int enter;
	do
	{
		cout << "Добавляем нового клиента - 1\n";
		cout << "Показ статистики печати - 2\n";
		cout << "Удаление с наивысшим приоритетом - 3\n";
		cout << "Выход - 4\n";
		cin >> enter;
		time_t t = time(NULL);
		switch (enter)
		{
		case 1:
			cout << "Уважаемый клиент введите любую цыфру\n\n";
			cin >> s;
			New.Add(s, rand() % 12);
			cout << ctime(&t) << "\n\n";
			break;
		case 2:
			New.Show();
			cout << ctime(&t) << "\n\n";
			cout << "\n\n";
			break;
		case 3:
			New.Extract();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "Error\n";
		}

	} while (enter != 5);
	cout << "exit\n";
}