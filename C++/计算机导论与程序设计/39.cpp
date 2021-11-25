#include <iostream>
using namespace std;

int main()
{
	int x_, y_;
	cin >> y_ >> x_;
	int a[100][100];
	bool flag = false;
	bool flag_ = true;
	for (int y = 0; y < y_; y++)
	{
		for (int x = 0; x < x_; x++)
		{
			cin >> a[x][y];
		}
	}
	int min;
	int index_x, index_y;
	for (int y = 0; y < y_; y++)
	{
		flag_ = true;
		min = a[0][y];
		index_x = 0;
		index_y = y;
		for (int x = 1; x < x_; x++)
		{
			if (a[x][y] < min)
			{
				min = a[x][y];
				index_x = x;
			}
		}
		for (int y = 0; y < y_; y++)
		{
			if (a[index_x][y] > a[index_x][index_y])
			{
				flag_ = false;
				break;
			}
		}
		if (flag_)
		{
			cout << y << ' ' << index_x << ' ' << min << endl;
			flag = true;
		}
	}
	if (!flag) cout << "no" << endl;
}
