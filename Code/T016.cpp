#include <iostream>
#include <string>

using namespace std;

int main()
{
	string expression;
	int lenExpre = 0;
	int numLeaf = 0;
	int sign = 0;

	cin >> expression;
	lenExpre = expression.length();
	for (int i = 0; i < lenExpre; i++)
	{
		if (expression[i] == '#')
			sign++;
		else
			sign = 0;

		if (sign == 2)
			numLeaf++;
	}

	cout << numLeaf;
	return 0;
}