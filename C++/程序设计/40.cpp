#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[100];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	bool flag;
	for (int i = 0; i < n; i++)
	{
		flag = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = true;
			}
		}
		if (!flag) break;
	}
	int d = a[1] - a[0];
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i + 1] - a[i] != d)
		{
			cout << "no";
			return 0;
		}
	}
	cout << d;
}
