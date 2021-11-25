#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[80] = { 0 };
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	bool flag = false;
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
	int i = n / 2;
	while (a[i] == a[n / 2])
	{
		i++;
	}
	int length = i;
	i = n / 2;
	while (a[i] == a[n / 2])
	{
		i--;
	}
	length -= i + 2;
	if ((n - length) % 2) cout << a[i + 1];
	else cout << -1;
}
