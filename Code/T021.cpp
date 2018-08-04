#include <iostream>
#include <string>

#define PLUS      0
#define MINUS     1
#define MUL       2
#define DIVISION  3
#define LEFT      4
#define RIGHT     5
#define POUSI     6

using namespace std;

typedef struct stackNode
{
	char data;
	stackNode *next;
}stackNode, *linkStack;

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

// define the operation
// '1' == '>' , '-1' == '<' , '0' == '='
int opeartor[7][7] = { { 1, 1, -1, -1, -1, 1, 1 },
{ 1, 1, -1, -1, -1, 1, 1 },
{ 1, 1, 1, 1, -1, 1, 1 },
{ 1, 1, 1, 1, -1, 1, 1 },
{ -1, -1, -1, -1, -1, 0, 0 },
{ 1, 1, 1, 1, 0, 1, 1 },
{ -1, -1, -1, -1, -1, 0, 0 } };

// change char to int for using the "opeartor"
int char2int(char aim)
{
	if (aim == '+')
		return PLUS;
	else if (aim == '-')
		return MINUS;
	else if (aim == '*')
		return MUL;
	else if (aim == '/')
		return DIVISION;
	else if (aim == '(')
		return LEFT;
	else if (aim == ')')
		return RIGHT;
	else if (aim == '#')
		return POUSI;
}

bool isLetter(char aimChar)
{
	if ((aimChar >= 'a' && aimChar <= 'z') ||
		(aimChar >= 'A' && aimChar <= 'Z'))
		return true;
	else
		return false;
}

// compete the isp and the icp
int competition(int num1, int num2)
{
	return opeartor[num1][num2];
}

int changeExp(string expBef, char* expAft)
{
	myStack *operStack = new myStack;
	int lenExp = expBef.size();
	char isp_char;
	char icp_char;
	int isp_int = 0;
	int icp_int = 0;
	int compeRes = 0;
	int instrtIndex = 0;
	int loop = 0;

	operStack->stack_init();
	expBef += "#";
	operStack->stack_push('#');
	while (loop <= lenExp)
	{
		icp_char = expBef[loop];
		isp_char = operStack->stack_top();

		if (isLetter(icp_char))
		{
			expAft[instrtIndex++] = icp_char;
			cout << expAft[instrtIndex - 1];
			loop++;
		}

		else
		{
			isp_int = char2int(isp_char);
			icp_int = char2int(icp_char);
			compeRes = competition(isp_int, icp_int);
			if (compeRes == -1)
			{
				operStack->stack_push(icp_char);
				loop++;
			}
			else if (compeRes == 1)
			{
				expAft[instrtIndex++] = operStack->stack_top();
				cout << expAft[instrtIndex - 1];
				operStack->stack_pop();
			}
			else if (compeRes == 0)
			{
				operStack->stack_pop();
				loop++;
			}

		}
	}

	return instrtIndex;
}



int main()
{
	string expreBef;
	char expreAft[1000];
	int lenAte = 0;

	cin >> expreBef;

	lenAte = changeExp(expreBef, expreAft);

	return 0;
}