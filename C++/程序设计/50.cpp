#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n][2];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i][0];
		int temp = a[i][0];
		int sum = 0;
		while (temp)
		{
			int x = temp % 10;
			sum += x;
			temp /= 10;
		}
		a[i][1] = sum;
	}
	int r[2];
	r[0] = a[0][0];
	r[1] = a[0][1];
	for (int i = 1; i < n; i++)
	{
		if (a[i][1] > r[1])
		{
			r[0] = a[i][0];
			r[1] = a[i][1];
		}
		else if (a[i][1] == r[1])
		{
			r[0] = a[i][0] > r[0] ? a[i][0] : r[0];
		}
	}
	cout << r[0];
}
