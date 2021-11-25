#include <iostream>
using namespace std;

int main()
{
	int x_, y_;
	cin >> y_ >> x_;
	int b[100][100] = { 0 };
	for (int y = 0; y < y_; y++)
	{
		for (int x = 0; x < x_; x++)
		{
			cin >> b[x][y];
		}
	}
	for (int x = 0; x < x_; x++)
	{
		for (int y = y_ - 1; y >= 0; y--)
		{
			cout << b[x][y] << ' ';
		}
		cout << endl;
	}
}
