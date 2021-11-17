#include<iostream>
using namespace std;
class DynIntQueue
{
private:
	struct QueueNode
	{
		int value;
		QueueNode* next;
	};
	QueueNode* front;
	QueueNode* rear;
	int numItems;
public:
	DynIntQueue(void);
	~DynIntQueue(void);
	void enqueue(int);
	int dequeue(void);
	bool isEmpty(void);
	void makeNull(void);
};
DynIntQueue::DynIntQueue(void)
{
	front = NULL;
	rear = NULL;
	numItems = 0;
}
DynIntQueue::~DynIntQueue(void)
{
	makeNull();
}
void DynIntQueue::enqueue(int num)
{
	QueueNode* newNode;
	newNode = new QueueNode;
	newNode->value = num;
	newNode->next = NULL;
	if (isEmpty())
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
	numItems++;
}
int DynIntQueue::dequeue(void)
{
	QueueNode* temp;
	int num;
	if (isEmpty())
		cout << "The queue is empty.\n";
	else
	{
		num = front->value;
		temp = front->next;
		delete front;
		front = temp;
		numItems--;
	}
	return num;
}
bool DynIntQueue::isEmpty(void)
{
	if (numItems)
		return false;
	else
		return true;
}
void DynIntQueue::makeNull()
{
	while (!isEmpty())
		dequeue();
}
int main()
{
	DynIntQueue iQueue;
	for (int x = 0; x < 5; x++)
		iQueue.enqueue(x);
	cout << "The values in the queue were:\n";
	while (!iQueue.isEmpty())
	{
		int value;
		value = iQueue.dequeue();
		cout << value << endl;
	}
	return 0;
}