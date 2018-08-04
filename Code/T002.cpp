#include <iostream>
#include <vector>


using namespace std;

typedef struct node {
	int data;
	struct node *next;
}NODE;

int main()
{
	int temp = 0;
	int lenNum = 0;
	int num[1000];

	cin >> lenNum;
	for (int i = 0; i < lenNum; i++)
		cin >> num[i];
	
	/*
	NODE *head[1000];
	NODE *tempNode;
	tempNode = head;
	for (int j = 0; j < lenNum; j++)
	{
		tempNode = tempNode->next;
		tempNode->next = num[i];
	}
	*/
	

	for (int m = 0; m < lenNum / 2; m++)
	{
		temp = num[lenNum-m -1];
	    num[lenNum - m -1] = num[m];
	    num[m] = temp;
	}

	for (int j = 0; j < lenNum - 1; j++)
		cout << num[j] << " ";
	cout << num[lenNum - 1] << endl;


	for (int j = 0; j < lenNum - 1; j++)
		cout << num[j] << " ";
	cout << num[lenNum - 1] << endl;

	return 0;

}