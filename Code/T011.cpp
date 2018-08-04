#include <iostream>

using namespace std;

void getArr(int* num, int len)
{
	for (int i = 0; i < len; i++)
		cin >> num[i];
}

void changeArr(int* num , int len)
{
	int temp = num[len-1];
	for (int i = len - 1; i >= 0; i--)
		num[i] = num[i - 1];
	num[0] = temp;
}

void printArr(int* num, int len)
{
	for (int i = 0; i < len-1; i++)
		cout << num[i] << " ";
	cout << num[len - 1];
}

int main()
{
	int lenArr = 0;
	int rightPlace = 0;
	int arr[110];

	cin >> lenArr;
	cin >> rightPlace;
	getArr(arr, lenArr);
	for (int i = 0; i < rightPlace; i++)
		changeArr(arr, lenArr);

	printArr(arr, lenArr);


	return 0;

}