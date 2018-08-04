#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string expression;
	vector<char> aimExpre;
	int lenExpre = 0;
	int lenAim = 0;

	cin >> expression;
	lenExpre = expression.length();
	for (int i = 0; i < lenExpre; i++)
		if (expression[i] == '#' || (expression[i] >= 'A' && expression[i] <= 'Z'))
			aimExpre.push_back(expression[i]);
	lenAim = aimExpre.size();
	for (int j = 0; j < lenAim; j++)
		cout << aimExpre[j];
    
	return 0;

}