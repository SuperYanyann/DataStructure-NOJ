#include <iostream>
#include <vector>

using namespace std;

vector<int> sameItem;

struct listNode
{
	int data;
	listNode* next;
};

void creatList(listNode* head,int len)
{
	listNode* p = head;
	for (int i = 0; i < len; i++)
	{
		listNode* newNode = new listNode;
		cin >> newNode->data;
		p->next = newNode;
		p = p->next;
	}
}

bool whetherIn(listNode* list, int num,int len)
{
	listNode* p = list;
	for (int i = 0; i < len; i++)
	{
		p = p->next;
		if (num == p->data)
			return true;
	}

	return false;
}

bool whetherInVec(int num)
{
	int len = sameItem.size();
	for (int i = 0; i < len; i++)
		if (num == sameItem[i])
    {
      return true;
    }


	return false;
}

void findSame(listNode* list1, listNode* list2, int len1, int len2)
{
	listNode* loop = list1;

	for (int i = 0; i < len1; i++)
	{
		loop = loop->next;
		if (whetherIn(list2, loop->data, len2))
    {
      sameItem.push_back(loop->data);
    }
	}
}

void printList(listNode* list,int len)
{
  listNode* p = new listNode;
  p = list;
  for (int j = 0; j < len - 1; j++)
  {
    p = p->next;
    cout << p->data << " ";
  }
  p = p->next;
  cout << p->data << endl;
}

int main()
{
	int lenA = 0;
	int lenB = 0;
	int lenC = 0;
	listNode* listA = new listNode;
	listNode* listB = new listNode;
	listNode* listC = new listNode;
	listNode* tempNode = new listNode;
	listNode* tempNode2 = new listNode;
	listNode* turnNode = new listNode;

	cin >> lenA;
	cin >> lenB;
	cin >> lenC;
	creatList(listA, lenA);
	creatList(listB, lenB);
	creatList(listC, lenC);

	findSame(listB, listC, lenB, lenC);

	tempNode = listA;
  tempNode2 = tempNode;
	tempNode = tempNode->next;
	for (int i = 0; i < lenA; i++)
	{

		if (whetherInVec(tempNode->data))
		{
			turnNode = tempNode2;
			turnNode->next = tempNode->next;
			tempNode = turnNode->next;
			lenA--;
		}
		else
		{
			tempNode2 = tempNode;
			tempNode = tempNode->next;
		}
	}

  printList(listA,lenA);

	return 0;

}