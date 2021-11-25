#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	bool a[100][100] = { false };
	int xl, yl, xr, yr;
	for (int i = 0; i < n; i++)
	{
		cin >> xl >> yl >> xr >> yr;
		for (int y = yl; y < yr; y++)
		{
			for (int x = xl; x < xr; x++)
			{
				a[x][y] = true;
			}
		}
	}
	int sum = 0;
	for (int y = 0; y < 100; y++)
	{
		for (int x = 0; x < 100; x++)
		{
			if (a[x][y]) sum++;
		}
	}
	cout << sum;
}
