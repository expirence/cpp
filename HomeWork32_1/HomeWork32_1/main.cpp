#include <iostream>
using namespace std;

// ����������� ������� �����
class Enployer
{
protected:
	char* prof;
public:
	Enployer(char* prof)
	{
		this->prof = prof;
	}
	virtual void Print() = 0;
};

// ����� ���������
class President : public Enployer
{
public:
	President(char* prof) : Enployer(prof) {};
	virtual void Print()
	{
		cout << prof << " say \"I'm a President!\"" << endl;
	}
};

// ����� ��������
class Manager : public Enployer
{
public:
	Manager(char* prof) : Enployer(prof) {};
	virtual void Print()
	{
		cout << prof << " say \"I'm a Manager!\"\n";
	}
};

// ����� �������
class Worker : public Enployer
{
public:
	Worker(char* prof) : Enployer(prof) {};
	virtual void Print()
	{
		cout << prof << " say \"I'm a Worker!\"\n";
	}
};

void main()
{
	Enployer* enployer[3] = {
		new President("president"),
		new Manager("manager"),
		new Worker("worker") };
	for (int i = 0; i < 3; i++)
	{
		enployer[i]->Print();
	}
}