// 实现参考《数据结构》课本
#include <iostream>
#include <string>

#define ATOM 0
#define LIST 1

using namespace std;

typedef struct GLNode
{
	int tag;
	char atom;
	struct { GLNode *headPoint = NULL;
	         GLNode *tailPoint = NULL; }ptr;
}*Node;

class GList
{
public:
	void getGList(Node& GList);
	int getDepth(Node& Glist);
	int depth;
private:
	void creatGList(Node& GList, string& str);
	void opertaString(string& str1, string& str2);

};

void GList::getGList(Node& GList)
{
	string charNum;
	cin >> charNum;
	creatGList(GList, charNum);
}

void GList::creatGList(Node& GList, string& aimStr)
{
	Node Node1, Node2;
	string str1, str2;

	if (aimStr ==  "()")
		GList = NULL;
	else
	{
		GList = new GLNode;
		if (aimStr.size() == 1)
		{
			GList->tag = ATOM;
			GList->atom = aimStr[0];
		}
		else
		{
			GList->tag = LIST;
			Node1 = GList;
			str1 = aimStr.substr(1, aimStr.size() - 2);
			while (!str1.empty())
			{
				opertaString(str1, str2);
				creatGList(Node1->ptr.headPoint, str2);
				Node2 = Node1;
				if (!str1.empty())
				{
					Node1 = new GLNode;
					Node1->tag = LIST;
					Node2->ptr.tailPoint = Node1;
				}
			}

		}
	}

}

int GList::getDepth(Node& Node1)
{
	int maxDeep = 0;
	int deep = 0;
	Node tempNode = Node1;

	if (Node1 == NULL)
		return 1;
	if (Node1->tag == ATOM)
		return 0;
	for (tempNode; tempNode; tempNode = tempNode->ptr.tailPoint)
	{
		deep = getDepth(tempNode->ptr.headPoint);
		if (deep > maxDeep)
			maxDeep = deep;
	}

	return ++maxDeep;
}

void GList::opertaString(string& str1, string& str2)
{
	int lenStr1 = str1.size();
	int loop1 = 0;
	int loop2 = 0;

	while (loop1 < lenStr1 && (str1[loop1] != ',' || loop2 != 0))
	{
		if (str1[loop1] == '(') 
			loop2++;
		else if (str1[loop1] == ')') 
			loop2--;
		loop1++;
	}
	if (loop1 < lenStr1)
	{
		str2 = str1.substr(0, loop1);
		str1 = str1.substr(loop1 + 1, lenStr1 - loop1 - 1);
	}
	else
	{
		str2 = str1;
		str1.erase(str1.begin(), str1.end());
    }
}


int main()
{
	GList List1;
	Node Node1 ;
	int testPoint = 0;

	List1.getGList(Node1);

	cout << List1.getDepth(Node1) << endl;
	cout << List1.getDepth(Node1) << endl;

	return 0;

}