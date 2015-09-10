#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

class List
{
protected:
	// голова, хвост
	node *head, *tail;
	// количество элементов списка
	int count;
public:
	List();
	~List();
	virtual void push(int value);
	virtual void pop();
	virtual void print();
	virtual int getCount();

};

List::List()
{
	head = tail = nullptr;
	count = 0;
}

List::~List()
{
	while (head != nullptr)
	{
		pop();
	}
	if (head == nullptr)
	{
		cout << "\nDestructor: empty...\n" << endl;
	}
}

void List::push(int value)
{
	// новый элемент становится последним элементом списка, если он не первый добавленный	
	if (head != nullptr)
	{
		tail->next = new node;
		tail = tail->next;
		tail->data = value;
		tail->next = nullptr;
		count++;
	}
	// новый элемент становится единственным, если он первый добавленный
	else
	{
		// создание нового элемента
		head = new node;
		tail = head;
		// заполнение данными
		tail->data = value;
		// следующий элемент отсутствует
		tail->next = nullptr;
		count++;
	}
}

void List::pop()
{
	if (getCount() != 0)
	{
		node* nxt = head;
		head = head->next;
		delete nxt;
		count--;
	}
	else
	{
		cout << "List is empty..." << endl;
	}
}

void List::print()
{
	node* nxt = head;
	while (nxt)
	{
		cout << nxt->data << " ";
		nxt = nxt->next;
	}
	if (head == nullptr)
	{
		cout << "List is empty!\n";
	}
	cout << endl;
}

int List::getCount()
{
	return count;
}

class Stack : public List
{
public:
	virtual void push(int value);
	virtual void pop();
	virtual void print();
};

void Stack::push(int value)
{
	// новый элемент становится последним элементом списка, если он не первый добавленный	
	if (head != nullptr)
	{
		tail->next = new node;
		tail = tail->next;
		tail->data = value;
		tail->next = nullptr;
		count++;
	}
	// новый элемент становится единственным, если он первый добавленный
	else
	{
		head = new node;
		tail = head;
		tail->data = value;
		tail->next = nullptr;
		count++;
	}
}

void Stack::pop()
{
	if (getCount() != 0 && count > 1)
	{
		node* nxt = head;
		if (nxt->next == tail)
		{
			nxt = nxt->next;
			tail = head;
			tail->next = nullptr;
			delete nxt;
			count--;
		}
		else
		{
			while (nxt->next != tail)
			{
				nxt = nxt->next;
			}
			tail = nxt;
			nxt = nxt->next;
			tail->next = nullptr;
			delete nxt;
			count--;
		}
	}
	else if (getCount() == 1)
	{
		delete head;
		head = nullptr;

	}
	else
	{
		cout << "Stack is empty..." << endl;
	}
}

void Stack::print()
{
	node* nxt = head;
	while (nxt)
	{
		cout << nxt->data << " ";
		nxt = nxt->next;
	}
	if (head == nullptr)
	{
		cout << "Stack is empty!\n";
	}
	cout << endl;
}

class Queue:public List
{
public:
	virtual void push(int value);
	virtual void pop();
	virtual void print();
};

void Queue::push(int value)
{
	// новый элемент становится последним элементом списка, если он не первый добавленный	
	if (head != nullptr)
	{
		tail->next = new node;
		tail = tail->next;
		tail->data = value;
		tail->next = nullptr;
		count++;
	}
	// новый элемент становится единственным, если он первый добавленный
	else
	{
		head = new node;
		tail = head;
		tail->data = value;
		tail->next = nullptr;
		count++;
	}
}

void Queue::pop()
{
	if (getCount() != 0)
	{
		node* nxt = head;
		head = head->next;
		delete nxt;
		count--;
	}
	else
	{
		cout << "Queue is empty..." << endl;
	}
}

void Queue::print()
{
	node* nxt = head;
	while (nxt)
	{
		cout << nxt->data << " ";
		nxt = nxt->next;
	}
	if (head == nullptr)
	{
		cout << "Queue is empty!\n";
	}
	cout << endl;
}

void main()
{
	List* list;
	Stack* stack = new Stack;
	Queue* queue = new Queue;

	list = stack;
	cout << "\t STACK\n";
	for (int i = 1; i < 6; i++)
	{
		list->push(i);
	}
	list->print();
	cout << "Elements in list: " << list->getCount() << endl;
	for (int i = 0; i < 2; i++)
	{
		list->pop();
	}
	list->print();
	cout << "Elements in list: " << list->getCount() << endl;
	cout << "-------------------" << endl;
	list = queue;
	cout << "\t QUEUE\n";
	for (int i = 5; i > 0; i--)
	{
		list->push(i);
	}
	list->print();
	cout << "Elements in list: " << list->getCount() << endl;
	for (int i = 0; i < 2; i++)
	{
		list->pop();
	}
	list->print();
	cout << "Elements in list: " << list->getCount() << endl;
	cout << "-------------------" << endl;

	delete stack;
	delete queue;
}
