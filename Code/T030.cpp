#include <iostream>

using namespace std;

void getMat(int mat[][3], int len)
{
	for (int i = 0; i < len; i++)
		for (int j = 0; j < 3; j++)
			cin >> mat[i][j];
}


int whichPush(int mat1[][3], int mat2[][3], int no1, int no2)
{
	if (mat1[no1][0] == mat2[no2][0] && mat1[no1][1] == mat2[no2][1])
		return 0;
	else if (mat1[no1][0] < mat2[no2][0])
		return 1;
	else if (mat1[no1][0] == mat2[no2][0] && mat1[no1][1] < mat2[no2][1])
		return 1;
	else
		return 2;
}

int oneAdd(int mat1[][3], int mat2[][3], int no1, int no2)
{
	return (mat1[no1][2] + mat2[no2][2]);
}

void pushToMat(int mat[][3], int row, int col, int num, int countNum)
{
	mat[countNum][0] = row;
	mat[countNum][1] = col;
	mat[countNum][2] = num;
}

int addMat(int mat1[][3], int mat2[][3], int mat3[][3], int len1, int len2)
{
	int cursor1 = 0;
	int cursor2 = 0;
	int judge = -1;
	int tempAdd = 0;
	int lenAftAdd = 0;

	while (cursor1 < len1 && cursor2 < len2)
	{
		judge = whichPush(mat1, mat2, cursor1, cursor2);
		if (judge == 0)
		{
			tempAdd = oneAdd(mat1, mat2, cursor1, cursor2);
			// !!!! Attention when sum == 0,the sum cannot be pushed into the Mat3 
			if (tempAdd != 0)
			{
				pushToMat(mat3, mat1[cursor1][0], mat1[cursor1][1], tempAdd, lenAftAdd++);
				cursor1++;
				cursor2++;
			}
			else
			{
				cursor1++;
				cursor2++;
			}

		}
		else if (judge == 1)
		{
			pushToMat(mat3, mat1[cursor1][0], mat1[cursor1][1], mat1[cursor1][2], lenAftAdd++);
			cursor1++;
		}
		else if (judge == 2)
		{
			pushToMat(mat3, mat2[cursor2][0], mat2[cursor2][1], mat2[cursor2][2], lenAftAdd++);
			cursor2++;
		}
	}
	if (cursor1 == len1 && cursor2 < len2)
	{
		for (int i = cursor2; i < len2; i++)
		{
			pushToMat(mat3, mat2[cursor2][0], mat2[cursor2][1], mat2[cursor2][2], lenAftAdd++);
			cursor2++;
		}
	}
	else if (cursor2 == len2 && cursor1 < len1)
	{
		for (int i = cursor1; i < len1; i++)
		{
			pushToMat(mat3, mat1[cursor1][0], mat1[cursor1][1], mat1[cursor1][2], lenAftAdd++);
			cursor1++;
		}
	}

	return lenAftAdd;

}

void printMat(int mat[][3], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < 2; j++)
			cout << mat[i][j] << " ";
		cout << mat[i][2] << endl;
	}
	for (int j = 0; j < 2; j++)
		cout << mat[len-1][j] << " ";
	cout << mat[len-1][2];
}

int main()
{
	int countA = 0;
	int countB = 0;
	int countC = 0;
	int row = 0;
	int col = 0;
	int matA[100][3];
	int matB[100][3];
	int matC[200][3];
    
    cin >> row;
    cin >> col;
	cin >> countA;
	cin >> countB;
	getMat(matA, countA);
	getMat(matB, countB);

	countC = addMat(matA, matB, matC, countA, countB);
	printMat(matC, countC);

	return 0;

}