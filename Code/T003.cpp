#include <iostream>
#include <vector>

using namespace std;

vector<int> numSame;

int findPlace(int aimNum, vector<int> num , int lenNum)
{
	for (int i = 0; i < lenNum; i++)
		if (num[i] == aimNum)
			return i;
	return -1;
}

void findSame(vector<int> num1 , vector<int> num2 ,int len1, int len2)
{

	if (len1 < len2)
	{
		for (int m = 0; m < len1; m++)
			if (findPlace(num1[m], num2, len2) != -1)
				numSame.push_back(num1[m]);
	}
	else
	{
		for (int n = 0; n < len2; n++)
			if (findPlace(num2[n], num1, len1) != -1)
				numSame.push_back(num2[n]);
	}
}

void printResult(vector<int> num,int lenNum)
{
	for (int i = 0; i < lenNum - 1; i++)
		cout << num[i] << " ";
	cout << num[lenNum - 1];
}

int main()
{
	int lenA = 0;
	int lenB = 0;
	int lenC = 0;
	int numInA = 0;

	cin >> lenA;
	cin >> lenB;
	cin >> lenC;

	vector<int> numA(lenA);
	vector<int> numB(lenB);
	vector<int> numC(lenC);


	for (int i = 0; i < lenA; i++)
		cin >> numA[i];
	for (int j = 0; j < lenB; j++)
		cin >> numB[j];
	for (int k = 0; k < lenC; k++)
		cin >> numC[k];

	findSame(numB, numC, lenB, lenC);
	if (numSame.size() == 0)
		printResult(numA, lenA);
	else
	{
		for (int h = 0; h < numSame.size(); h++)
		{
			numInA = findPlace(numSame[h], numA, lenA);
			if (numInA != -1)
			{
				numA.erase(numA.begin() + numInA);
				lenA--;
			}
		}

		printResult(numA, lenA);
			
	}

	return 0;


}