#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int data[n][n];
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> data[y][x];
		}
	}
	int index = 0;
	for (int scan = 0; scan < n + n - 1; scan++)
	{
		if (scan - n + 1 > 0)
			index = scan - n + 1;
		if (scan % 2)
		{
			for (int y = index, x = scan - index; y <= scan - index; x--, y++)
			{
				cout << data[y][x] << ' ';
			}
		}
		else
		{
			for (int x = index,y = scan - index; x <= scan - index; x++, y--)
			{
				cout << data[y][x] << ' ';
			}
		}
	}
}
