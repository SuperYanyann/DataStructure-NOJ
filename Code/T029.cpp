#include <iostream>

using namespace std;

int getArr(int arr[][3])
{
	int len = 0;
	cin >> arr[0][0];
	cin >> arr[0][1];
	cin >> arr[0][2];
	while (!(arr[len][0] == 0 && arr[len][1] == 0
		&& arr[len][2] == 0))
	{
		cin >> arr[++len][0];
		cin >> arr[len][1];
		cin >> arr[len][2];
	}

	return len;
}

void changeTwo(int arr[][3], int no1, int no2)
{
	int temp1 = 0;
	int temp2 = 0;
	int temp3 = 0;
	temp1 = arr[no1][0];
	temp2 = arr[no1][1];
	temp3 = arr[no1][2];
	arr[no1][0] = arr[no2][0];
	arr[no1][1] = arr[no2][1];
	arr[no1][2] = arr[no2][2];
	arr[no2][0] = temp1;
	arr[no2][1] = temp2;
	arr[no2][2] = temp3;

	cout << no1 << " , " << no2 << endl;
}

void sortArr_1(int arr[][3],int len)
{
	int sortCol = 1;

	for (int i = 0; i < len - 1; i++)
		for (int j = i + 1; j<len;j++)
			if (arr[i][sortCol] > arr[j][sortCol])
				changeTwo(arr,i,j);

}

void sortArr_2(int arr[][3], int len)
{
	int sortCol = 0;
	int sortCol2 = 1;

	for (int i = 0; i < len - 1; i++)
		for (int j = 0; j < len; j++)
			if (arr[i][sortCol] == arr[j][sortCol] &&
				arr[i][sortCol2] > arr[j][sortCol2])
				changeTwo(arr, i, j);
			else if (arr[i][sortCol] != arr[j][sortCol])
			    break;
}

void printArr(int arr[][3], int len)
{
	for (int i = 0; i < len; i++)
		cout << arr[i][1] << " " << arr[i][0] << " " << arr[i][2] << endl;
}

int main()
{
	int row = 0;
	int col = 0;
	int lenArr = 0;
	int oriArr[400][3];

	cin >> row;
	cin >> col;
	lenArr = getArr(oriArr);

	sortArr_1(oriArr, lenArr);
	sortArr_2(oriArr, lenArr);

	printArr(oriArr, lenArr);


	return 0;

}