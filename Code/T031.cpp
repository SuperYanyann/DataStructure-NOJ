#include <iostream>  
#include <cstdio>  
#include <stdlib.h>  

using namespace std;

typedef struct listNode
{
	int row, col;
	int value;
	struct listNode *rightNode, *downNode;
}*listLink;

typedef struct
{
	listLink*rowHead, *colHead;
	int numRow, numCol;
	int numItem;
}crossList;

void createList(crossList &operaList, int numR, int numC, int numIt)
{
	operaList.numRow = numR ;
	operaList.numCol = numC ;
	operaList.numItem = numIt;
	operaList.rowHead = (listLink*)malloc((operaList.numRow + 1)*sizeof(listLink));
	operaList.colHead = (listLink*)malloc((operaList.numCol + 1)*sizeof(listLink));
	
	int loop = 0;
	for (loop = 1; loop <= operaList.numRow; loop++)
		operaList.rowHead[loop] = NULL;
	for (loop = 1; loop <= operaList.numCol; loop++)
		operaList.colHead[loop] = NULL;
	for (loop = 1; loop <= operaList.numItem; loop++)
	{
		int Row = 0;
		int Col = 0;
		int Item = 0;
		listLink loopNode;
		listLink tempNode = (listNode*)malloc(sizeof(listNode));

		cin >> Row >> Col >> Item;
        tempNode->row = Row;
		tempNode->col = Col;
		tempNode->value = Item;
        if (operaList.rowHead[Row] == NULL || operaList.rowHead[Row]->col > Col)
		{
			tempNode->rightNode = operaList.rowHead[Row];
			operaList.rowHead[Row] = tempNode;
		}
		else
		{
			for (loopNode = operaList.rowHead[Row]; (loopNode->rightNode) && (loopNode->rightNode->col < Col); loopNode = loopNode->rightNode)
				;
			tempNode->rightNode = loopNode->rightNode;
			loopNode->rightNode = tempNode;
		}
		tempNode->downNode = NULL;
		if (operaList.colHead[Col] == NULL || operaList.colHead[Col]->row > Row)
		{
			tempNode->downNode = operaList.colHead[Col];
			operaList.colHead[Col] = tempNode;
		}
		else
		{
			for (loopNode = operaList.colHead[Col]; (loopNode->downNode) && (loopNode->downNode->row < Row); loopNode = loopNode->downNode)
				;
			tempNode->downNode = loopNode->downNode;
			loopNode->downNode = tempNode;
		}
		tempNode->rightNode = NULL;
	}
}

void DestroyList(crossList &operaList)
{
	listLink tempList;
	for (int k = 1; k <= operaList.numRow; k++)
	{
		tempList = operaList.rowHead[k];
		while (tempList)
		{
			operaList.rowHead[k] = tempList->rightNode;
			free(tempList);
			tempList = operaList.rowHead[k];
		}
	}
	operaList.numRow = 0;
	operaList.numCol = 0;
	operaList.numItem = 0;
}

void InsertNode(crossList &operaList, listLink &tempNode)
{
	int i = tempNode->row, j = tempNode->col;
	int numDeleted = 0, numAdd = 0;
	if (operaList.rowHead[i] == NULL)
	{
		operaList.rowHead[i] = tempNode;
		operaList.numItem++;
	}
	else
	{
		listLink q = operaList.rowHead[i];
		listLink pre = q;
		while (q && (q->col < tempNode->col))
		{
			pre = q;
			q = q->rightNode;
		}
		if (q != NULL && q->col == tempNode->col)
		{
			q->value += tempNode->value;
			if (q->value == 0)
			{
				if (pre == q)
					operaList.rowHead[i] = q->rightNode;
				else
					pre->rightNode = q->rightNode;
				operaList.numItem--;
				numDeleted = 1;
			}
			else
				numAdd = 1;
		}
		if (!numDeleted && !numAdd)
		{
			if (pre == q)
			{
				operaList.rowHead[i] = tempNode;
				tempNode->rightNode = q;
			}
			else
			{
				pre->rightNode = tempNode;
				tempNode->rightNode = q;
			}
			operaList.numItem++;
		}
	}

	if (operaList.colHead[j] == NULL)
		operaList.colHead[j] = tempNode;
	else
	{
		listLink q = operaList.colHead[j];
		listLink pre = q;
		while (q && (q->row < tempNode->row))
		{
			pre = q;
			q = q->downNode;
		}
		if (numDeleted)
		{
			if (q != NULL)
			{
				if (pre == q)
					operaList.colHead[j] = q->downNode;
				else
					pre->downNode = q->downNode;
				free(q);
				free(tempNode);
				return;
			}
		}
		if (!numAdd)
		{
			if (pre == q)
			{
				operaList.colHead[j] = tempNode;
				tempNode->downNode = q;
			}
			else
			{
				pre->downNode = tempNode;
				tempNode->downNode = q;
			}
		}
	}

}

void addList(crossList &M, crossList &N)
{
	listLink Node1, Node2;
	Node1 = (listNode*)malloc(sizeof(listNode));
	for (int k = 1; k <= N.numRow; k++)
	{
		Node1 = N.rowHead[k];
		while (Node1)
		{
			Node2 = (listNode*)malloc(sizeof(listNode));
			Node2->downNode = Node1->downNode;
			Node2->rightNode = Node1->rightNode;
			Node2->value = Node1->value;
			Node2->row = Node1->row;
			Node2->col = Node1->col;
			InsertNode(M, Node2);
			Node1 = Node1->rightNode;
		}
	}
}

void printList(crossList &operaList)
{
	for (int k = 1; k <= operaList.numRow; k++)
	{
		listLink p = operaList.rowHead[k];
		for (int t = 1; t <= operaList.numCol; t++)
		{
			if (p && (t == p->col))
			{
				printf("%d %d %d\n", p->row, p->col, p->value);
				p = p->rightNode;
			}
		}
	}
}
int main()
{

	int numRow = 0;
	int numCol = 0;
	int numItem1 = 0;
	int numItem2 = 0;

	cin >> numRow >> numCol >> numItem1 >> numItem2;
	crossList list1, list2;
	createList(list1, numRow, numCol, numItem1);
	createList(list2, numRow, numCol, numItem2);
	addList(list1, list2);
	printList(list1);
	return 0;
}