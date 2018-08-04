#include <iostream>
# define MaxNumHead 100

using namespace std;

bool whetherVisit[MaxNumHead];
bool whetherGet = false;

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

int DFS(ALGraph *head, int nodeNum,int aimNode)
{
	whetherVisit[nodeNum] = true;
	int indexNum = findHeadIndex(head, nodeNum);
	ArcNode *tempNode = head->vertices[indexNum].nextArc;
	while (tempNode != NULL)
	{
		if (tempNode->nodeData == aimNode)
		{
			whetherGet = true;
			return 0;
	    }
		else
		{
			int nextNode = tempNode->nodeData;
			if (!whetherVisit[nextNode])
				DFS(head, nextNode, aimNode);
			tempNode = tempNode->nextArc;
		}
	}

	return 0;

}
void DFSTravel(ALGraph *head, int nodeNum)
{
	whetherVisit[nodeNum] = true;
	cout << nodeNum << endl;
	int indexNum = findHeadIndex(head, nodeNum);
	ArcNode *tempNode = head->vertices[indexNum].nextArc;
	while (tempNode != NULL)
	{
		int nextNode = tempNode->nodeData;
		if (!whetherVisit[nextNode])
			DFSTravel(head, nextNode);
		tempNode = tempNode->nextArc;
	}

}

int main()
{
	int numHead = 0;
	int numArc = 0;
	int beginNode = 0;
	int endNode = 0;

	cin >> numHead >> numArc;
	ALGraph *opearGraph = new ALGraph;
	opearGraph->numHeadNode = numHead;
	opearGraph->numArcNode = numArc;
    initHeadNode(opearGraph);
	getArcGraph(opearGraph);
	cin >> beginNode >> endNode;

	//DFSTravel(opearGraph, beginNode);

	DFS(opearGraph, beginNode, endNode);
	if (whetherGet)
		cout << "yes";
	else
		cout << "no";
	return 0;
}