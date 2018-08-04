#include <iostream>

using namespace std;

typedef struct Qnode
{
	int data;
	Qnode *next;
}QNode,*QueuePtr;

class myQueue
{
public:
	QueuePtr front;
	QueuePtr rear;
public:
	void queue_init();
	void queue_pop();
	void queue_push(int num);
	int queue_back();
	int queue_front();
};

void myQueue::queue_init()
{
	this->front = this->rear = new QNode;
	this->front->next = NULL;
}

void myQueue::queue_push(int num)
{
	QueuePtr p = new QNode;
	p->data = num;
	p->next = NULL;
	this->rear->next = p;
	this->rear = p;
}

void myQueue::queue_pop()
{
	QueuePtr p = this->front->next;
	int e = p->data;
	this->front->next = p->next;
	delete p;
}

int myQueue::queue_front()
{
	return this->front->next->data;
}

int myQueue::queue_back()
{
	return this->rear->data;
}

int main()
{
	int maxNum = 0;
	int couNum = 0;
	int temp1 = 1;
	int sumOfk = 1;
	myQueue *fibArr = new myQueue;

	fibArr->queue_init();
	cin >> maxNum;
	cin >> couNum;
	for (int i = 0; i < couNum - 1; i++)
		fibArr->queue_push(0);
	fibArr->queue_push(1);

	while (sumOfk <= maxNum)
	{
		fibArr->queue_push(sumOfk);
		sumOfk = sumOfk - fibArr->queue_front() + fibArr->queue_back();
		fibArr->queue_pop();
	}

	if (couNum == 1)
		cout << fibArr->queue_back() << endl;
	else
	{
		for (int i = 0; i < couNum - 1; i++)
		{
			cout << fibArr->queue_front() << " ";
			fibArr->queue_pop();
		}
		cout << fibArr->queue_front() << endl;
	}

	return 0;
}