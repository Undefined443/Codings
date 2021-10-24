#include <iostream>
using namespace std;

int main()
{
	int a[3][2];
	int b[2][3];
	for (int y = 0; y < 2; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cin >> a[x][y];
		}
	}
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 2; x++)
		{
			cin >> b[x][y];
		}
	}
	int c[2][2] = { 0 };
	for (int y = 0; y < 2; y++)
	{
		for (int x = 0; x < 2; x++)
		{
			for (int i = 0; i < 3; i++)
			{
				c[x][y] += a[i][y] * b[x][i];
			}
			cout << c[x][y] << ' ';
		}
		cout << endl;
	}
}
