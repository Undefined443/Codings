#include <iostream>
using namespace std;

int main()
{
	int a[3][3];
	int b[3][3];
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cin >> a[x][y];
			b[y][x] = a[x][y];
		}
	}
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			b[x][y] += a[x][y];
			cout << b[x][y] << ' ';
		}
		cout << endl;
	}
}
