#include <iostream>
#include "AbstractQueue.h"
using namespace std;

class NoElementsException :public exception
{
public:
	NoElementsException(const char* msg) :
		exception(msg) {}
};

template <typename T>
struct Node 
{
	int a;
	Node* next;
};

template <typename T>
class Queue: AbstractQueue<T>
{
public: 
	Queue();
	Queue(T);
	Queue<T>& operator=(Queue&&);
	int GetSize() const override;
	void Push(T) override;
	void Pop(T&) override;
	bool HasElements() const;
	void Peek(T&)override;
private:
	Node<T>* next;
	Node<T>* tail;
	int size;
};