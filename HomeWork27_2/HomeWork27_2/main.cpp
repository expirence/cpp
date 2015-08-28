#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Elem
{
	// Любые данные
	T data;
	Elem * next, *prev;
};

template <typename T>
class ListQueue
{
	// Голова хвост
	Elem<T> * Head, *Tail;
	int Count;
public:

	ListQueue();
	ListQueue(const ListQueue&);
	~ListQueue();
	int GetCount();
	Elem<T>* Extract();
	void DelAll();
	void Del(int);
	void AddTail();
	void AddTail(T);
	void Print();
	void Print(int pos);
	bool isEmpty();
};

template <typename T>
ListQueue<T>::ListQueue()
{
	Head = Tail = 0;
	Count = 0;
}

template <typename T>
ListQueue<T>::ListQueue(const ListQueue & L)
{
	Head = Tail = 0;
	Count = 0;
	Elem<T> * temp = L.Head;
	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
}

template <typename T>
ListQueue<T>::~ListQueue()
{
	DelAll();
}

template <typename T>
Elem<T>* ListQueue<T>::Extract()
{
	if (!isEmpty())
	{
		Elem<T> *temp = Head;
		Head = Head->next;
		Head->prev = 0;
		delete temp;
		Count--;
		return Head;
	}
	else
	{
		return NULL;
	}
}

template <typename T>
void ListQueue<T>::AddTail()
{
	Elem<T> * temp = new Elem<T>;

	temp->next = 0;
	int n;
	cout << "Input new number: ";
	cin >> n;

	temp->data = n;
	temp->prev = Tail;

	if (Tail != 0)
		Tail->next = temp;

	if (Count == 0)
		Head = Tail = temp;
	else
		Tail = temp;

	Count++;
}

template <typename T>
void ListQueue<T>::AddTail(T n)
{
	Elem<T> * temp = new Elem<T>;

	temp->next = 0;
	temp->data = n;
	temp->prev = Tail;
	if (Tail != 0)
		Tail->next = temp;
	if (Count == 0)
		Head = Tail = temp;
	else
		Tail = temp;
	Count++;
}

template <typename T>
void ListQueue<T>::Del(int n)
{
	if (n < 1 || n > Count)
	{
		cout << "Incorrect position !!!\n";
		return;
	}
	int i = 1;
	Elem<T> * Del = Head;
	while (i < n)
	{
		// Доходим до элемента, который удаляется
		Del = Del->next;
		i++;
	}
	// Доходим до элемента, который предшествует удаляемому
	Elem<T> * PrevDel = Del->prev;
	// Доходим до элемента, который следует за удаляемым
	Elem<T> * AfterDel = Del->next;
	if (PrevDel != 0 && Count != 1)
		PrevDel->next = AfterDel;
	if (AfterDel != 0 && Count != 1)
		AfterDel->prev = PrevDel;
	if (n == 1)
		Head = AfterDel;
	if (n == Count)
		Tail = PrevDel;
	delete Del;
	Count--;
}


template <typename T>
void ListQueue<T>::Print(int pos)
{
	// Позиция от 1 до Count?
	if (pos < 1 || pos > Count)
	{
		// Неверная позиция
		cout << "Incorrect position !!!\n";
		return;
	}
	Elem<T> * temp;
	// Определяем с какой стороны 
	// быстрее двигаться
	if (pos <= Count / 2)
	{
		// Отсчет с головы
		temp = Head;
		int i = 1;

		while (i < pos)
		{
			// Двигаемся до нужного элемента
			temp = temp->next;
			i++;
		}
	}
	else
	{
		// Отсчет с хвоста
		temp = Tail;
		int i = 1;

		while (i <= Count - pos)
		{
			// Двигаемся до нужного элемента
			temp = temp->prev;
			i++;
		}
	}
	// Вывод элемента
	cout << pos << " element: ";
	cout << temp->data << "\n";
}

template <typename T>
void ListQueue<T>::Print()
{
	if (Count != 0)
	{
		Elem<T> * temp = Head;
		while (temp != 0)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	cout << endl;
}

template <typename T>
void ListQueue<T>::DelAll()
{
	while (Count != 0)
		Del(1);
}

template <typename T>
int ListQueue<T>::GetCount()
{
	return Count;
}
template <typename T>
bool ListQueue<T>::isEmpty()
{
	if (Head->next != nullptr)
	{
		return false;
	}
}

void main()
{
	ListQueue <int> L;
	const int n = 10;
	int a[n] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (int i = 0; i < n; i++)
		L.AddTail(a[i]);
	// Распечатка списка
	cout << "List L:\n";
	L.Print();
	// Распечатка 2-го и 8-го элементов списка
	L.Print(2);
	L.Print(8);
	L.Extract();
	L.Print();
	L.Print(2);
	L.Print(8);
	ListQueue <char> L1;
	char b[n] = { 'H', 'i', ' ', 'w', 'o', 'r', 'l', 'd', '!', '\0' };
	for (int i = 0; i < n; i++)
	{
		L1.AddTail(b[i]);
	}
	L1.Print();
	L1.Print(2);
	L1.Print(8);
	L1.Extract();
	L1.Print();
	L1.Print(2);
	L1.Print(8);
	system("pause");
}