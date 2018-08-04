#include <iostream>
#include <vector>
#include <stdio.h>
#include <String>

using namespace std;

int main()
{
	int lenArr = 0;
	int frontPoint = 0;
	int rearPoint = 0;
	int denum = 0;
	string arr2;

	cin >> lenArr;

	vector<int> arr(lenArr);

	for (int i = 0;; i++)
	{
		if (rearPoint == lenArr)
			break;
		else
		{
			cin >> arr[rearPoint++];
			if (getchar() == '\n')
				break;
		}

	}
	/*
	if (rearPoint == lenArr)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
		*/
	cin >> arr2;
	cin >> denum;

	while (denum != arr[frontPoint])
		frontPoint++;
	frontPoint++;
	if (rearPoint == lenArr)
	{
		for (int k = frontPoint; k < lenArr - 1; k++)
			cout << arr[k] << " ";
		cout << arr[lenArr - 1] << endl;
		cout << arr[frontPoint];
	}
	else
	{
		for (int m = frontPoint; m < lenArr - 2; m++)
			cout << arr[m] << " ";
		cout << arr[lenArr - 2] << endl;
		cout << arr[frontPoint] << endl;
	}


	return 0;
}