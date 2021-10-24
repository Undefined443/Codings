#include <iostream>
using namespace std;

int main()
{
	char str[101] = { 0 };
	cin.getline(str, 101);
	char left[100] = { 0 };
	char right[100] = { 0 };
	int i = 1;
	int m = 0, n = 0;
	while (str[i])
	{
		if (str[i] > str[0]) left[m++] = str[i];
		else right[n++] = str[i];
		i++;
	}
	bool flag;
	for (int i = 0; i < n; i++)
	{
		flag = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (right[j] > right[j + 1])
			{
				int t = right[j];
				right[j] = right[j + 1];
				right[j + 1] = t;
				flag = true;
			}
		}
		if (!flag) break;
	}
	cout << left << str[0] << right;
}
