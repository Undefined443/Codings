#include <iostream>
using namespace std;

int main()
{
	int x_, y_;
	cin >> y_ >> x_;
	int a;
	int a_[16] = { 0 };
	for (int y = 0; y < y_; y++)
	{
		for (int x = 0; x < x_; x++)
		{
			cin >> a;
			a_[a]++;
		}
	}
	for (int i = 0; i < 16; i++)
	{
		if (a_[i]) cout << i << ' ' << a_[i] << endl;
	}
}
