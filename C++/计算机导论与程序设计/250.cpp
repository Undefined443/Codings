#include <iostream>
using namespace std;

int main()
{
	int x_, y_;
	cin >> y_ >> x_;
	int a[x_ + 2][y_ + 2] = { 0 };
	for (int i = 0; i < x_ + 2; i++)
	{
		a[i][0] = a[i][y_ + 1] = 1;
	}
	for (int i = 1; i < y_ + 1; i++)
	{
		a[0][i] = a[x_ + 1][i] = 1;
	}
	int x = 1, y = 1;
	int put = 1;
	while (put <= x_ * y_)
	{
		while (a[x][y] < 1)
		{
			a[x][y] = put;
			put++;
			x++;
		}
		x--;
		y++;
		while (a[x][y] < 1)
		{
			a[x][y] = put;
			put++;
			y++;
		}
		y--;
		x--;
		while (a[x][y] < 1)
		{
			a[x][y] = put;
			put++;
			x--;
		}
		x++;
		y--;
		while (a[x][y] < 1)
		{
			a[x][y] = put;
			put++;
			y--;
		}
		y++;
		x++;
	}
	for (int y = 1; y <= y_; y++)
	{
		for (int x = 1; x <= x_; x++)
		{
			cout << a[x][y] << ' ';
		}
		cout << endl;
	}
}

