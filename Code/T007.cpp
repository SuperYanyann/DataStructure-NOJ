#include <iostream>
#include <string>

using namespace std;

typedef struct stackNode
{
	char data;
	stackNode *next;
}stackNode,*linkStack;

class myStack
{
public:
	linkStack operaNode;
	int sumItem;
public:
	void stack_init();
	bool stack_empty();
	void stack_push(char aimData);
	void stack_pop();
	char stack_top();
};

void myStack::stack_init()
{
	this->operaNode = NULL;
	this->sumItem = 0;
}

void myStack::stack_push(char aimData)
{ 
	linkStack p = new stackNode;
	p->data = aimData;
	p->next = this->operaNode;
	this->operaNode = p;
	this->sumItem++;
}

void myStack::stack_pop()
{
	linkStack p = new stackNode;
	p = this->operaNode;
	this->operaNode = this->operaNode->next;
	delete p;
	this->sumItem--;
}

char myStack::stack_top()
{
	return this->operaNode->data;
}

bool myStack::stack_empty()
{
	if (this->sumItem == 0)
		return true;
	else
		return false;
}

bool mateRoNot(char data1, char data2)
{
	if ((data1 == '(') && (data2 == ')'))
		return true;
	else if ((data1 == '[') && (data2 == ']'))
		return true;
	else if ((data1 == '{') && (data2 == '}'))
		return true;

	return false;
}

int main()
{
	string expression;
	myStack *stackBra = new myStack;
	int lenExp = 0;
	char temp;
	bool sign = true;

	stackBra->stack_init();
	cin >> expression;
	lenExp = expression.size();

	for (int i = 0; i < lenExp; i++)
	{
		if ((expression[i] == '(') || (expression[i] == '[')
			|| (expression[i] == '{'))
			stackBra->stack_push(expression[i]);

		if ((expression[i] == ')') || (expression[i] == ']')
			|| (expression[i] == '}'))
			if (mateRoNot(stackBra->stack_top(), expression[i]))
				stackBra->stack_pop();
			else
				sign = false;
	}

	if (!stackBra->stack_empty())
		sign = false;

	if (sign)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}