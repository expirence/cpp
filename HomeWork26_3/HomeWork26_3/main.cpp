# include<iostream>
# include<string.h>
# include<time.h>
using namespace std;
class Printer
{
	int * Wait; // �������
	int * Prioritet; // �������
	int * Stat; // �������
	int Max; // ���-� ������ �������
	int Length; // ������� ������ �������
public:
	Printer(int a); // �����������
	~Printer(); // ����������
	void Add(int x, int y); // ���������� ��������
	void Extract(); // ���������� ��������
	void Clear(); // ������� ������
	bool IsEmpty(); // �������� ���-��� ��������� � �������
	bool IsFull(); // �������� �� ������������ �������
	int GetCount(); // ���-�� ��������� � �������
	void Show(); // ����� �� ����� �������
};
Printer::Printer(int a)
{
	Max = a; //�������� ������
	Wait = new int[Max]; //������� �������
	Prioritet = new int[Max]; //������� ������� ����������
	Stat = new int[Max]; //������� ������� ����������
	Length = 0; // ���������� ������� �����
}
Printer :: ~Printer()
{
	delete[] Wait;
	delete[] Prioritet;
	delete[] Stat;
}
bool Printer::IsEmpty()
{
	return Length == 0; // ����?
}
bool Printer::IsFull()
{
	return Length == Max; // �����?
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
	Length = 0; // ����������� "�������" �������
}
int Printer::GetCount()
{
	return Length; // ���������� �������������� � ����� ���������
}
void Printer::Extract()
{
	// ���� � ������� ���� ��������, �� ���������� ���,
	// � �������� ��������� ��������� � �������� �������
	if (!IsEmpty()){

		for (int i = 0; i<Length - 1; i++){ //�������� ��� ��������
			Wait[i] = Wait[i + 1];
			Prioritet[i] = Prioritet[i + 1];
		}

		Length--; //��������� ����������
	}
}





void Printer::Show()
{
	time_t t = time(NULL);
	int max_pri = Prioritet[0];
	//� ������������ ������ = 0
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
		cout << "��������� ������ ������� - 1\n";
		cout << "����� ���������� ������ - 2\n";
		cout << "�������� � ��������� ����������� - 3\n";
		cout << "����� - 4\n";
		cin >> enter;
		time_t t = time(NULL);
		switch (enter)
		{
		case 1:
			cout << "��������� ������ ������� ����� �����\n\n";
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