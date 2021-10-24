#include <iostream>
using namespace std;

int main()
{
	bool flag = false;
	int a[5][4] = { 0 };
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			cin >> a[x][y];
		}
	}
	int max, min, index_x, index_y;
	for (int y = 0; y < 4; y++)
	{
		max = a[0][y];
		index_x = 0;
		for (int x = 0; x < 5; x++)
		{
			if (a[x][y] > max)
			{
				max = a[x][y];
				index_x = x;
			}
			min = a[index_x][y];
		}
		for (int y = 0; y < 4; y++)
		{
			if (a[index_x][y] < min)
			{
				min = a[index_x][y];
			}
		}
		if (max == min)
		{
			cout << min << ' ' << y + 1 << ' ' << index_x + 1 << endl;
			flag = true;
		}
	}
	if (!flag) cout << "°°µã²»´æÔÚ";
}
