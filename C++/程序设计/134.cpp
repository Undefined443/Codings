#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	int temp;
	int a[9] = { 0 };
	int i = 0;
	while (n)
	{
		temp = n % 10;
		a[i++] = temp;
		n /= 10;
	}
	bool flag;
	for (int j = 0; j < i; j++)
	{
		flag = 0;
		for (int k = 0; k < i - j - 1; k++)
		{
			if (a[k] < a[k + 1])
			{
				temp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = temp;
				flag = true;
			}
		}
		if (!flag) break;
	}
	for (int j = 0; j < i; j++)
	{
		cout << a[j] << ' ';
	}
}
