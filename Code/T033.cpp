#include <iostream>  
#include <cstdio>  
#include <cstring>  

#define MAXBIT 100  
#define MAXNODE 1000   
#define MAXWEIGHT 1000  
using namespace std;
typedef struct
{
	int bit[MAXBIT];
	int start;
}HCodeType;

typedef struct
{
	int weight;
	int parent;
	int lchild;
	int rchild;
	char value;
}HNodeType;

void HuffmanTree(HNodeType HuffNode[], int n)
{
	int i, j;
	for (i = 0; i < 2 * n - 1; i++)
	{
		HuffNode[i].weight = 0;
		HuffNode[i].parent = -1;
		HuffNode[i].lchild = -1;
		HuffNode[i].rchild = -1;
		HuffNode[i].value = -1;
	}
	for (i = 0; i < n; i++)
		cin >> HuffNode[i].value;
	for (i = 0; i < n; i++)
		cin >> HuffNode[i].weight;
	for (i = 0; i < n - 1; i++)
	{
		int m1, m2;
		m1 = m2 = MAXWEIGHT;
		int x1, x2;
		x1 = x2 = 0;
		for (j = 0; j < n + i; j++)
		{
			if ((HuffNode[j].weight<m1) && (HuffNode[j].parent == -1))
			{
				m2 = m1;
				x2 = x1;
				m1 = HuffNode[j].weight;
				x1 = j;
			}
			else if ((HuffNode[j].weight<m2) && (HuffNode[j].parent == -1))
			{
				m2 = HuffNode[j].weight;
				x2 = j;
			}
		}
		HuffNode[x1].parent = n + i;
		HuffNode[x2].parent = n + i;
		HuffNode[n + i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
		HuffNode[n + i].lchild = x1;
		HuffNode[n + i].rchild = x2;
	}
}



int main()
{
	HNodeType HuffNode[MAXNODE];
	HCodeType HuffCode[MAXBIT], cd;
	int n, i;
	cin >> n;
	HuffmanTree(HuffNode, n);

	for (i = 0; i < n; i++)
	{
		cd.start = n - 1;
		int cur = i;
		int p = HuffNode[cur].parent;
		while (p != -1)
		{
			if (HuffNode[p].lchild == cur)
				cd.bit[cd.start] = 0;
			else
				cd.bit[cd.start] = 1; 
			cd.start--;
			cur = p;
			p = HuffNode[cur].parent;
		}
		for (int j = cd.start + 1; j<n; j++)
			HuffCode[i].bit[j] = cd.bit[j];
		HuffCode[i].start = cd.start;
	}
	char code[1000];
	cin >> code;
	for (i = 0; i < (int)strlen(code); i++)
	{

		for (int j = 0; j < n; j++)
		{
			if (code[i] == HuffNode[j].value)
			{
				for (int k = HuffCode[j].start + 1; k < n; k++)
				     cout << HuffCode[j].bit[k];
			}
		}
	}
	cout << "\n";
	cout << code << endl;
	return 0;
}