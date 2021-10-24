#include <iostream>
using namespace std;

int main()
{
	int x_, y_, t, find;
	cin >> y_ >> x_ >> t >> find;
	bool flag = true;
	int a[20][20] = { 0 };
	//input
	int x, y;
	int start_x, start_y;
	for (y = 1; y <= y_; y++)
	{
		for (x = 1; x <= x_; x++)
		{
			cin >> a[x][y];
			if (a[x][y] == find && flag)//remark the first by the way
			{
				start_x = x, start_y = y;
				flag = false;
			}
		}
	}
	//find the end
	x = start_x, y = start_y;
	while (a[x][y] == find) x++;
	x--;
	while (a[x][y] == find) y++;
	y--;
	int end_x = x, end_y = y;
	int sum = 0;
	if (a[start_x - 1][start_y]) sum++;
	if (a[start_x][start_y - 1]) sum++;
	if (a[end_x + 1][end_y]) sum++;
	if (a[end_x][end_y + 1]) sum++;
	for (x = start_x; x < end_x; x++)
	{
		if (a[x][start_y - 1] != a[x + 1][start_y - 1]) sum++;
		if (a[x][end_y + 1] != a[x + 1][end_y + 1]) sum++;
	}
	for (y = start_y; y < end_y; y++)
	{
		if (a[start_x - 1][y] != a[start_x - 1][y + 1]) sum++;
		if (a[end_x + 1][y] != a[end_x + 1][y + 1]) sum++;
	}
	cout << sum;
}
