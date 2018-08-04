#include <iostream>
#include <queue>
# define MaxNumHead 100

using namespace std;

bool whetherVisit[MaxNumHead];
bool whetherGet = false;

typedef struct QNode
{
	int data;
	QNode* nextNode;
}QNode,*QueuePtr;


typedef struct LinkNode
{
	QueuePtr front;
	QueuePtr rear;
};

void initQueue(LinkNode *Q)
{
	Q->front = Q->rear = new QNode;
	Q->front->nextNode = NULL;
}

void pushQueue(LinkNode *que, int nodeNum)
{
	QNode *temp = new QNode;
	temp->data = nodeNum;
	temp->nextNode = NULL;
	que->rear->nextNode = temp;
	que->rear = temp;
}

int popQueue(LinkNode *que)
{
	int aimData = que->front->nextNode->data;
	QNode *temp = que->front->nextNode;
	que->front->nextNode = temp->nextNode;
	delete temp;
	return aimData;
}

bool emptyQueue(LinkNode *que)
{
	if (que->front == que->rear)
		return true;
	else
		return false;
}

struct ArcNode
{
	int nodeData;
	ArcNode *nextArc;
};

typedef struct headNode
{
	int nodeData;
	ArcNode *nextArc;
};

struct ALGraph
{
	headNode vertices[MaxNumHead];
	int numHeadNode;
	int numArcNode;
};

int findHeadIndex(ALGraph *head, int headNodeName)
{
	int numHead = head->numHeadNode;
	for (int i = 0; i < numHead; i++)
		if (head->vertices[i].nodeData == headNodeName)
			return i;
	return -1;
}

void initHeadNode(ALGraph *head)
{
	int numHead = head->numHeadNode;
	for (int i = 0; i < numHead; i++)
	{
		cin >> head->vertices[i].nodeData;
		head->vertices[i].nextArc = NULL;
	}
}

void getArcGraph(ALGraph *head)
{
	int numArc = head->numArcNode;
	int tempHeadNode = 0;
	int tempArcNode = 0;
	int indexHeadNode = 0;

	for (int i = 1; i <= numArc; i++)
	{
		cin >> tempHeadNode >> tempArcNode;

		indexHeadNode = findHeadIndex(head, tempHeadNode);
		ArcNode *tempNode = new ArcNode;
		tempNode->nodeData = tempArcNode;
		tempNode->nextArc = head->vertices[indexHeadNode].nextArc;
		head->vertices[indexHeadNode].nextArc = tempNode;
	}
}

int BFS(ALGraph *head, int beginNode, int aimNode)
{
	queue<int> operaQueue;
	ArcNode *loopArcNode = new ArcNode;
	int topNode = 0;
	int nodeIndex = 0;

	whetherVisit[beginNode] = true;
	operaQueue.push(beginNode);
	while (!operaQueue.empty())
	{
		topNode = operaQueue.front();
		operaQueue.pop();
		nodeIndex = findHeadIndex(head, topNode);
		loopArcNode = head->vertices[nodeIndex].nextArc;
		for (loopArcNode; loopArcNode != NULL; loopArcNode = loopArcNode->nextArc)
		{
			if (loopArcNode->nodeData == aimNode)
			{
				whetherGet = true;
				return 0;
			}
			if (!whetherVisit[loopArcNode->nodeData])
			{
				whetherVisit[loopArcNode->nodeData] = true;
				operaQueue.push( loopArcNode->nodeData);
			}
		}
    }
	return 0;
}


int main()
{
	int numHead = 0;
	int numArc = 0;
	int beginNode = 0;
	int endNode = 0;
	ALGraph *opearGraph = new ALGraph;

	cin >> numHead >> numArc;
    opearGraph->numHeadNode = numHead;
	opearGraph->numArcNode = numArc;
	initHeadNode(opearGraph);
	getArcGraph(opearGraph);
	cin >> beginNode >> endNode;

	BFS(opearGraph, beginNode, endNode);

	if (whetherGet)
		cout << "yes";
	else
		cout << "no";
	return 0;
}