#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[11][10] = { 0 };
	a[1][0] = 1;
	int x = 1, y = 1;
	int length = 2;
	for (y = 1; y < n; y++)
	{
		for (x = 1; x <= length; x++)
		{
			a[x][y] = a[x - 1][y - 1] + a[x][y - 1];
		}
		length++;
	}
	length = 1;
	for (y = 0; y < n; y++)
	{
		for (x = 1; x <= length; x++)
		{
			cout << a[x][y] << ' ';
		}
		length++;
		cout << endl;
	}

}
