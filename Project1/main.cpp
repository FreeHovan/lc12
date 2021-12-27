#include "Header.h"
#include <conio.h>
#include<iostream>
using namespace std;


template <typename T>
Queue<T>::Queue()
{
	next = tail = nullptr;
}

template <typename T>
Queue<T>::Queue(T a)
{
	next = new Node<T>;
	next->next = next;
	tail = next;
	next->a = a;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue&& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete next;
	next = other.next;
	other.next = nullptr;
}

template <typename T>
int Queue<T>::GetSize() const
{
	if (!HasElements()) { return 0; }
	return size;
}

template <typename T>
void Queue<T>::Push(const T a)
{
	Node<T>* newnode = new Node<T>;
	newnode->a = a;
	if (HasElements())
	{
		newnode->next = tail;
		next->next = newnode;
		tail = newnode;
	}
	else
	{
		newnode->next = next = tail = newnode;
	}
	size++;
}

template <typename T>
void Queue<T>::Pop(T& a)
{
	if (!HasElements()) { throw NoElementsException("Deck is Empty!"); };
	a = next->a;
	Node<T>* temp = new Node<T>;
	temp = tail;
	if (next == tail)
	{
		delete next;
		next = tail = nullptr;
		size = 0;
	}
	while (temp->next != next)
	{
		temp = temp->next;
	}
	size--;
	next = temp;
	next->next = tail;
}

template <typename T>
void Queue<T>::Peek(T& a)
{
	if (!HasElements()) { throw NoElementsException("Deck is Empty!"); };
	a = next->a;
}

template <typename T>
bool Queue<T>::HasElements() const
{
	if (this->next != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	Queue<double> a;
	double b;
	bool flag = true;
	while (flag)
	{
		cout << "1. Добавить элемент в очередь\n";
		cout << "2. Получить элемент из очереди\n";
		cout << "3. Посмотреть элемент из очереди\n";
		cout << "4. Длина очереди\n";
		cout << "5. Выход\n";
		switch (_getch())
		{
		case '1':
			cout << "Добавить элемент: ";
			cin >> b;
			a.Push(b);
			break;
		case '2':
			try
			{
				a.Pop(b);
				cout << "Полученный элемент " << b << endl;
			}
			catch (NoElementsException ex)
			{
				cout << "Очередь пуста\n";
			}
			break;
		case '3':
			try
			{
				a.Peek(b);
				cout << "Последний элемент " << b << endl;
			}
			catch (NoElementsException ex)
			{
				cout << "Очередь пуста\n";
			}
			break;
		case '4':
			b = a.GetSize();
			cout << "Длина очереди: " << b << endl;
			break;
		case '5':
			flag = false;
			break;

		}
	}

}