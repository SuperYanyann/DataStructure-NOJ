
/*
#include <iostream>
#include <list>

using namespace std;

list<int> epoch;
list<int> sum;

void creatPI(int num)
{
int len = num;
int temp = 0;
int ret = 0;
list<int>::reverse_iterator reverseIt1,reverseIt2;
list<int>::iterator it;

epoch.push_back(2);
sum.push_back(2);
for(int i =1;i<len;i++)
{
epoch.push_back(0);
sum.push_back(0);
}

for (int j = 1;j<100000;j++)
{
ret = 0;
for (reverseIt1 = epoch.rbegin(); reverseIt1!=epoch.rend();reverseIt1++)
{
temp = *reverseIt1 * j + ret;
*reverseIt1 = temp%10;
ret = temp/10;
}
ret = 0;
for (it = epoch.begin(); it!=epoch.end(); it++)
{
temp = *it + ret*10;
*it = temp/(2*j+1);
ret = temp%(2*j+1);
}
ret = 0;
for (reverseIt1 = sum.rbegin(),reverseIt2 = epoch.rbegin();
reverseIt1 != sum.rend()  && reverseIt2 != epoch.rend();
reverseIt1++,reverseIt2++)
{
temp = *reverseIt1 + *reverseIt2 + ret;
*reverseIt1 = temp%10;
ret = temp/10;
}
}
}


int main()
{
int needLen = 0;
cin >> needLen;
list<int>::iterator loop;

creatPI(550);

loop = sum.begin();
cout << 3 << "." ;
loop++;
for (int i =0;i<needLen;i++)
{
cout << *loop;
loop++;
}
cout << endl;

return 0;
}

*/

//注释内为使用STL版本，提交为未使用STL版本

#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct listNode
{
	int data;
	struct listNode *preNode, *nextNode;
}listNode, *listLink;

void ListCreate(listLink L, int n)
{
	int i;
	listLink p, s;
	p = L;

	L->preNode = L->nextNode = L;                         

	for (i = 0; i < n; i++)
	{
		s = (listLink)malloc(sizeof(listNode));
		s->data = 0;

		p->nextNode = s;                                
		s->preNode = p;

		s->nextNode = L;                         
		L->preNode = s;
		p = s;
	}
}

listNode epoch, sum;
listLink pr, ps;

void ListTraverse(listLink L)
{
	listLink p = L;
	while (p->nextNode != L)
	{
		p = p->nextNode;
		cout << p->data;

	}
	cout << endl;
}

void creatPI(int num)
{
	int len = num;
	int i;


	for (i = 1; i < num; i++)
	{
		pr = epoch.preNode, ps = sum.preNode;
		int ret = 0, temp;

		while (pr != &epoch)
		{
			temp = (pr->data*i) + ret;
			ret = temp / 10;
			pr->data = temp % 10;
			pr = pr->preNode;
		}
		ret = 0;
		pr = pr->nextNode;
		while (pr != &epoch)
		{
			temp = (ret * 10 + pr->data);
			ret = temp % (2 * i + 1);
			pr->data = temp / (2 * i + 1);
			pr = pr->nextNode;
		}

		ret = 0;
		pr = pr->preNode;
		while (pr != &epoch && ps != &sum)
		{
			temp = (ret + pr->data + ps->data);
			ret = temp / 10;
			ps->data = temp % 10;
			pr = pr->preNode;
			ps = ps->preNode;
		}

	}
}

int main()
{
	int n;
	ListCreate(&epoch, 550);
	ListCreate(&sum, 550);
	epoch.nextNode->data = 2;
	sum.nextNode->data = 2;

	creatPI(100000);


	cin >> n;
    cout << "3.";
	ps = ps->nextNode;
	for (ps = ps->nextNode; n; ps = ps->nextNode, n--)
		cout << ps->data;
	cout << endl;
	return 0;
}