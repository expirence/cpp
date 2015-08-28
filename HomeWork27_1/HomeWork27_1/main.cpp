#include <iostream>
using namespace std;
// ���� ������
struct node
{
	// ��������
	int value;
	// ��������� �� ��������� ���� ������
	node* next;
};

class list
{
private:
	// ������
	node* phead;
	// �����
	node* ptail;
	// ���������� ��������� ������
	int count;
public:
	list();
	~list();
	// ���������� �������� � ������
	void add(int value);
	// �������� �������� �� ������
	void del();
	// �������� ���� ��������� �� ������(������� ������)
	void del_all();
	// ��������� ���������� ��������� � ������
	int getCount();
	// ������ ������
	void print();
	// ������� �������� � �������� �������
	void insertPos(int pos = 0);
	void delPos(int pos = 0);
	void search_elem(int elem = 0);
};

list::list()
{
	phead = ptail = nullptr;
	count = 0;
}

list::~list()
{
	del_all();
}

void list::add(int value)
{
	// ����� ������� ���������� ��������� ��������� ������, ���� �� �� ������ �����������	
	if (phead != nullptr)
	{
		ptail->next = new node;
		ptail = ptail->next;
		ptail->value = value;
		ptail->next = NULL;
		count++;
	}
	// ����� ������� ���������� ������������, ���� �� ������ �����������
	else
	{
		// �������� ������ ��������
		phead = new node;
		ptail = phead;
		// ���������� �������
		ptail->value = value;
		// ��������� ������� �����������
		ptail->next = NULL;
		count++;
	}
}

void list::del()
{
	if (getCount() != 0)
	{
		node* nxt = phead;
		phead = phead->next;
		delete nxt;
		count--;
	}
	else
	{
		cout << "List is empty." << endl;
	}
}

void list::del_all()
{
	while (phead != nullptr)
	{
		del();
	}
	if (phead == nullptr)
	{
		cout << "Destructor in work: cleaning list...List is empty." << endl;
	}
}

int list::getCount()
{
	// ���������� ���������� ���������
	return count;
}

void list::print()
{
	// ���������� ����� ��������� ��������
	node* nxt = phead;
	// ���� ��� ���� ��������
	while (nxt)
	{
		// ������� ������
		cout << nxt->value << " ";
		// ��������� �� ��������� �������
		nxt = nxt->next;
	}
	cout << endl;
	cout << "Head: " << phead << endl << "Tail: " << ptail << endl;
}

void list::insertPos(int pos)
{
	// ���� �������� ����������� ��� ����� 0, �� ����������� ���
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;		
	}
	// ������� �� 1 �� count?
	if (pos < 1 || pos > count + 1)
	{
		// �������� �������
		cout << "Incorrect position !!!\n";
		return;
	}
	// �������
	int i = 1;	
	node* ins = new node;
	// ������ ������
	cout << "Input new number: ";
	cin >> ins->value;
	cout << endl;
	if (pos == 1)
	{
		node* prev = phead;
		ins->next = prev;
		phead = ins;
	}
	else
	{
		node* prev = phead;
		// ����������� �� ������ n-1 ���������
		while (i < pos - 1)
		{
			prev = prev->next;
			i++;
		}
		node* nxt = prev->next;
		ins->next = nxt;
		prev->next = ins;
	}
	count++;
}

void list::delPos(int pos)
{
	// ���� �������� ����������� ��� ����� 0, �� ����������� ���
	if (pos == 0)
	{
		cout << "Input position to delete: ";
		cin >> pos;
		cout << endl;
	}
	// ������� �� 1 �� count?
	if (pos < 1 || pos > count)
	{
		// �������� �������
		cout << "Incorrect position !!!\n";
		return;
	}
	// �������
	int i = 1;	
	if (pos == 1)
	{
		node* nxt = phead;
		phead = phead->next;
		delete nxt;		
	}
	else
	{
		node* prev = phead;
		// ����������� �� ������ n-1 ���������
		while (i < pos - 1)
		{
			prev = prev->next;
			i++;
		}
		node* nxt = prev->next;
		nxt = nxt->next;
		prev->next = nxt;
	}
	count--;
}

void list::search_elem(int elem)
{
	// ���� ������� ����������� ��� ����� 0, �� ����������� ���
	if (elem == 0)
	{
		cout << "Input element: ";
		cin >> elem;		
	}
	int pos = 1;
	node* nxt = phead;
	int mas[] = { 0 };
	while (nxt)
	{		
		if (elem == nxt->value)
		{
			cout << "Element " << elem << " is " << pos << " position" << endl;
		}
		else
		{
			cout << "Element " << elem << " not found!" << endl;
		}
		nxt = nxt->next;
		pos++;
	}
}

void main()
{
	{
		list list;
		int arr[] = { 1,2,3,4,5,6,7 };
		for (int i = 0; i < 7; i++)
		{
			list.add(arr[i]);
		}
		list.print();
		cout << "Number elements in list: " << list.getCount() << endl;
		cout << endl;
		list.insertPos();
		list.print();
		cout << "Number elements in list: " << list.getCount() << endl;
		list.delPos();
		list.print();
		cout << "Number elements in list: " << list.getCount() << endl;
		list.search_elem();
		list.del();
		list.print();
		cout << "Number elements in list: " << list.getCount() << endl;
		cout << endl;
		list.del_all();
		list.print();
		cout << "Number elements in list: " << list.getCount() << endl;
	}
	system("pause");
}