#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int result = abs(a[1] - a[0]);
	int temp = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			temp = abs(a[j] - a[i]);
			if (temp < result) result = temp;
		}
	}
	cout << result;
	return 0;
}
