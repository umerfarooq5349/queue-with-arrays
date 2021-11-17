#include<iostream>
using namespace std;

#define size 10
class Queue {
	int* list;
	int front;
	int back;
	int numitems;
public:
	Queue() {
		list = new int[size];
		front, back = -1;

	}
	bool isEmpty() {
		if (front == -1) {
			return true;
		}
	}
	bool isFull() {
		if (back > size) {
			return true;
		}
	}
	void enqueue(int a) {

		if (back==(size-1)) {
			cout << "Queue is full (:" << endl;
		}
		else {
			back++;
			list[back] = a;
			cout << a << " is added " << endl;
		}
	}
	void dequeue() {
		if (front==-1) {
			cout << "Queue is empty ):" << endl;
		}
		else {
			front++;
			cout << front << endl;
		//	return front;
		}
	}
	int top() {
		if (front==-1) {
			cout << "Queue is empty ):" << endl;
		}
		else {
			return front;
		}
	}
};
int main() {
	Queue q1;
	for (int i = 0; i < 10; i++) {
		q1.enqueue(i);
		cout << endl;
	}
	cout << " now dequeeing all " << endl;
	for (int i = 0; i < 10; i++) {
		q1.dequeue();
		q1.top();
	}
	return 0;
}







