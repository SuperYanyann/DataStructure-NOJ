#include <iostream>  
#include <cstdio>  
#include <cmath>  
#include <stdlib.h> 

using namespace std;

typedef struct listNode
{
	int row, col;
	int value;
	listNode *rightNode, *downNode;
}*listLink;

struct crossList
{
	listLink *rowHeadNode, *colHeadNode;
	int numRow, numCol;
	int numItem;
};

void creatHeadNodeForCross(int numR, int numC, crossList &operaList)
{
	operaList.rowHeadNode = (listLink*)malloc((numR+1) * sizeof(listLink));
	operaList.colHeadNode = (listLink*)malloc((numC+1) * sizeof(listLink));

	for (int i = 1; i <= numR; i++)
		operaList.rowHeadNode[i] = NULL;
	for (int i = 1; i <= numC; i++)
		operaList.colHeadNode[i] = NULL;
}

listLink getNode()
{
	int numrow = 0;
	int numcol = 0;
	int item = 0;
	listLink tempNode = new listNode;

	cin >> numrow >> numcol >> item;
	tempNode->row = numrow;
	tempNode->col = numcol;
	tempNode->value = item;

	return tempNode;
}

void creatCrossList(int numR, int numC, int numIt, crossList &operaList)
{
	operaList.numRow = numR;
	operaList.numCol = numC;
	operaList.numItem = numIt;
	listLink tempNode;
	listLink loopNode;

	creatHeadNodeForCross(numR, numC, operaList);
	for (int i = 1; i <= numIt; i++)
	{
		tempNode = getNode();

		if (operaList.rowHeadNode[tempNode->row] == NULL ||
			operaList.rowHeadNode[tempNode->row]->col > tempNode->col)
		{
			tempNode->rightNode = operaList.rowHeadNode[tempNode->row];
			operaList.rowHeadNode[tempNode->row] = tempNode;
		}
		else
		{
			loopNode = operaList.colHeadNode[tempNode->row];
			for (loopNode; (loopNode->rightNode) && (loopNode->rightNode->col < tempNode->col);
				loopNode = loopNode->rightNode)
				;
			tempNode->rightNode = loopNode->rightNode;
			loopNode->rightNode = tempNode;
		}

		tempNode->downNode = NULL;
		if (operaList.colHeadNode[tempNode->col] == NULL ||
			operaList.colHeadNode[tempNode->col]->row > tempNode->row)
		{
			tempNode->downNode = operaList.colHeadNode[tempNode->col];
			operaList.colHeadNode[tempNode->col] = tempNode;
		}
		else
		{
			loopNode = operaList.colHeadNode[tempNode->col];
			for (loopNode; (loopNode->downNode) && (loopNode->downNode->row < tempNode->row);
				loopNode = loopNode->downNode)
				;
			tempNode->downNode = loopNode->downNode;
			loopNode->downNode = tempNode;
		}
		tempNode->rightNode = NULL;

	}

}

void DestroyList(crossList &operaList)
{
	listLink tempNode;
	for (int k = 1; k <= operaList.numRow; k++)
	{
		tempNode = operaList.rowHeadNode[k];
		while (tempNode)
		{
			operaList.rowHeadNode[k] = tempNode->rightNode;
			free(tempNode);
			tempNode = operaList.rowHeadNode[k];
		}
	}
	operaList.numRow = 0;
	operaList.numCol = 0;
	operaList.numItem = 0;
}

void InsertNode(crossList &operaList, listLink &p)
{
	int i = p->row, j = p->col;
	int deleted = 0, plused = 0;
	if (operaList.rowHeadNode[i] == NULL)
	{
		operaList.rowHeadNode[i] = p;
		operaList.numItem++;
	}
	else
	{
		listLink q = operaList.rowHeadNode[i];
		listLink pre = q;
		while (q && (q->col < p->col))
		{
			pre = q;
			q = q->rightNode;
		}
		if (q != NULL && q->col == p->col)
		{
			q->value += p->value;
			if (q->value == 0)
			{
				if (pre == q)
					operaList.rowHeadNode[i] = q->rightNode;
				else
					pre->rightNode = q->rightNode;
				operaList.numItem--;
				deleted = 1;
			}
			else
				plused = 1;
		}
		if (!deleted && !plused)
		{
			if (pre == q)
			{
				operaList.rowHeadNode[i] = p;
				p->rightNode = q;
			}
			else
			{
				pre->rightNode = p;
				p->rightNode = q;
			}
			operaList.numItem++;
		}
	}

	if (operaList.colHeadNode[j] == NULL)
		operaList.colHeadNode[j] = p;
	else
	{
		listLink q = operaList.colHeadNode[j];
		listLink pre = q;
		while (q && (q->row < p->row))
		{
			pre = q;
			q = q->downNode;
		}
		if (deleted)
		{
			if (q != NULL)
			{
				if (pre == q)
					operaList.colHeadNode[j] = q->downNode;
				else
					pre->downNode = q->downNode;
				free(q);
				free(p);
				return;
			}
		}
		if (!plused)
		{
			if (pre == q)
			{
				operaList.colHeadNode[j] = p;
				p->downNode = q;
			}
			else
			{
				pre->downNode = p;
				p->downNode = q;
			}
		}
	}

}


void AddList(crossList &operaList1, crossList &operaList2)
{
	listLink p, q;
	p = (listNode*)malloc(sizeof(listNode));
	for (int k = 1; k <= operaList2.numRow; k++)
	{
		p = operaList2.rowHeadNode[k];
		while (p)
		{
			q = (listNode*)malloc(sizeof(listNode));
			q->downNode = p->downNode;
			q->rightNode = p->rightNode;
			q->value = p->value;
			q->row = p->row;
			q->col = p->col;
			InsertNode(operaList1, q);
			p = p->rightNode;
		}
	}
}

void PrintList(crossList &operaList)
{
	for (int k = 1; k <= operaList.numRow; k++)
	{
		listLink p = operaList.rowHeadNode[k];
		for (int t = 1; t <= operaList.numCol; t++)
		{
			if (p && (t == p->col))
			{
				cout << p->row << " " << p->col << " " << p->value << endl;
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
	crossList list1, list2;

	cin >> numRow >> numCol >> numItem1 >> numItem2;
	creatCrossList(numRow, numCol, numItem1, list1);
	creatCrossList(numRow, numCol, numItem2, list2);
	AddList(list1, list2);
	PrintList(list1);
	return 0;
}

