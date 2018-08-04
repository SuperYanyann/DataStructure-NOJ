#include <iostream>

using namespace std;

int main()
{
	int num1[20];
	int num2[20];
	int num3[40];
	int lenNum1 = 0;
	int lenNum2 = 0;
	int lenNum3 = 0;
	int cursoe1 = 0;
	int cursoe2 = 0;
	int cursoe3 = 0;

	cin >> lenNum1;
	for (int i = 0; i < lenNum1; i++)
		cin >> num1[i];
	cin >> lenNum2;
	for (int j = 0; j < lenNum2; j++)
		cin >> num2[j];
	lenNum3 = lenNum1 + lenNum2;

	while (cursoe1 < lenNum1 && cursoe2<lenNum2)
	{
		if (num1[cursoe1] > num2[cursoe2])
		{
			num3[cursoe3] = num2[cursoe2];
			cursoe3++;
			cursoe2++;
		}
		else
		{
			num3[cursoe3] = num1[cursoe1];
			cursoe3++;
			cursoe1++;
		}
	}

	if (cursoe1 == lenNum1 && cursoe2 < lenNum2)
		for (int m = cursoe2; m < lenNum2; m++)
		{
			num3[cursoe3] = num2[cursoe2];
			cursoe3++;
			cursoe2++;
		}
	else if ( cursoe1 < lenNum1 && cursoe2 == lenNum2)
		for (int n = cursoe1; n < lenNum1; n++)
		{
			num3[cursoe3] = num1[cursoe1];
			cursoe3++;
			cursoe1++;
		}

	for (int k = 0; k < lenNum3; k++)
		cout << num3[k] << endl;

	//cin >> lenNum3;
	return 0;
}