#include <iostream>

using namespace std;

int getMat(int mat[][3])
{
	int len = 0;
	do
	{
		cin >> mat[len][0];
		cin >> mat[len][1];
		cin >> mat[len++][2];
	} while (!(mat[len-1][0] == 0 && mat[len-1][1] == 0
		     && mat[len-1][2] == 0));

	return len;
}


int mulMat(int mat1[][3], int row1, int col1,int len1,
	        int mat2[][3], int row2, int col2,int len2,
	        int mat3[][3])
{
	int notZeroMat2PerRow[1000];
	int indexNotZeroMat2PerRow[1000];
	int len3 = 0;
	int loopA = 0;
	int loopB = 0;
	int loopC = 0;
	int temp[1000];
	int firstNotZeroMat1 = 0;
	int lowIndexMat2 = 0;
	
	for (int i = 0; i <= row1; i++)
		notZeroMat2PerRow[i] = 0;
	for (int i = 0; i < len2; i++)
	{
		notZeroMat2PerRow[mat2[i][0]]++;
	}

	indexNotZeroMat2PerRow[1] = 0;
	for (int i = 2; i <= row2; i++)
	{
		indexNotZeroMat2PerRow[i] = indexNotZeroMat2PerRow[i - 1] + notZeroMat2PerRow[i - 1];
	}


	for (int i = 1; i <= row1; i++)
	{
		for (int j = 1; j <= col2; j++)
			temp[j] = 0;

		while (i == mat1[loopA][0])
		{
			firstNotZeroMat1 = mat1[loopA][1];
			if (firstNotZeroMat1 < row2)
				lowIndexMat2 = indexNotZeroMat2PerRow[firstNotZeroMat1+1];
			else
				lowIndexMat2 = len2;
			for (int q = indexNotZeroMat2PerRow[firstNotZeroMat1]; q < lowIndexMat2; q++)
			{
				loopB = mat2[q][1];
				temp[loopB] += mat1[loopA][2] * mat2[q][2];
			}
			loopA++;
		}
		for (int k = 1; k <= col2;k++)
			if (temp[k] != 0)
			{
				mat3[len3][0] = i;
				mat3[len3][1] = k;
				mat3[len3][2] = temp[k];
				len3++;
			}
	}

	return len3;

}

void printMat(int mat[][3], int len)
{
	for (int i = 0; i < len; i++)
		cout <<mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
}

int main()
{
	int rowA = 0;
	int colA = 0;
	int rowB = 0;
	int colB = 0;
	int lenA = 0;
	int lenB = 0;
	int lenC = 0;
	int matA[1000][3];
	int matB[1000][3];
	int matC[1000][3];

	cin >> rowA >> colA;
	lenA = getMat(matA);
	cin >> rowB >> colB;
	lenB = getMat(matB);

	lenC = mulMat(matA, rowA, colA, lenA,
		matB, rowB, colB, lenB,
		matC);

	printMat(matC, lenC);

	return 0;

}