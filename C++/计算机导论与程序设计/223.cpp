#include <iostream>
using namespace std;

int main()
{
	int a[3][3];
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cin >> a[x][y];
		}
	}
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += a[i][i];
	}
	cout << sum;
}
