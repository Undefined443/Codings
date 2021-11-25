#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char cmd[256] = { 0 };
	cin.getline(cmd, 101);
	char a[100] = { 0 };
	int i = 0;
	int k = 0;
	while (cmd[i])
	{
		if (cmd[i] == '-') a[k++] = cmd[i + 1];
		i++;
	}
	bool flag = false;
	for (int i = 0; i < k; i++)
	{
		flag = false;
		for (int j = 0; j < k - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				char temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = true;
			}
			else if (a[j] == a[j + 1])
			{
				a[j + 1] = 0;
				strcat(a, a + j + 2);
				k--;
			}
		}
		if (!flag) break;
	}
	for (int i = 0; i < k; i++)
	{
		cout << '-' << a[i] << ' ';
	}
	if (k == 0) cout << "no";
}
