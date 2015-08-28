#include <iostream>
using namespace std;
// узел списка
struct node
{
	// значение
	int value;
	// указатель на следующий узел списка
	node* next;
};

class list
{
private:
	// голова
	node* phead;
	// хвост
	node* ptail;
	// количество элементов списка
	int count;
public:
	list();
	~list();
	// добавление элемента в список
	void add(int value);
	// удаление элемента из списка
	void del();
	// удаление всех элементов из списка(удалние списка)
	void del_all();
	// получение количества элементов в списке
	int getCount();
	// печать списка
	void print();
	// вставка элемента в заданную позицию
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
	// новый элемент становится последним элементом списка, если он не первый добавленный	
	if (phead != nullptr)
	{
		ptail->next = new node;
		ptail = ptail->next;
		ptail->value = value;
		ptail->next = NULL;
		count++;
	}
	// новый элемент становится единственным, если он первый добавленный
	else
	{
		// создание нового элемента
		phead = new node;
		ptail = phead;
		// заполнение данными
		ptail->value = value;
		// следующий элемент отсутствует
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
	// возвращаем количество элементов
	return count;
}

void list::print()
{
	// запоминаем адрес головного элемента
	node* nxt = phead;
	// Пока еще есть элементы
	while (nxt)
	{
		// Выводим данные
		cout << nxt->value << " ";
		// Переходим на следующий элемент
		nxt = nxt->next;
	}
	cout << endl;
	cout << "Head: " << phead << endl << "Tail: " << ptail << endl;
}

void list::insertPos(int pos)
{
	// если параметр отсутствует или равен 0, то запрашиваем его
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;		
	}
	// позиция от 1 до count?
	if (pos < 1 || pos > count + 1)
	{
		// неверная позиция
		cout << "Incorrect position !!!\n";
		return;
	}
	// Счетчик
	int i = 1;	
	node* ins = new node;
	// Вводим данные
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
		// Отсчитываем от головы n-1 элементов
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
	// если параметр отсутствует или равен 0, то запрашиваем его
	if (pos == 0)
	{
		cout << "Input position to delete: ";
		cin >> pos;
		cout << endl;
	}
	// позиция от 1 до count?
	if (pos < 1 || pos > count)
	{
		// неверная позиция
		cout << "Incorrect position !!!\n";
		return;
	}
	// Счетчик
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
		// Отсчитываем от головы n-1 элементов
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
	// если элемент отсутствует или равен 0, то запрашиваем его
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