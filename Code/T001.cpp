#include <iostream>

using namespace std;

int main()
{
	int lenNum = 0;
	int insertNum = 0;
	int insertPlace = 0;
	int num[1000];

	cin >> lenNum;

	for (int i = 0; i < lenNum; i++)
		cin >> num[i];

	cin >> insertNum;
	for (int j = 0; j < lenNum; j++)
		if (insertNum > num[j])
			insertPlace++;
		else
			break;

	for (int m = lenNum - 1; m > insertPlace -1; m--)
		num[m + 1] = num[m];
	num[insertPlace] = insertNum;


	for (int k = 0; k < lenNum ; k++)
		cout << num[k] <<" "  ;
	cout << num[lenNum];

	return 0;

}