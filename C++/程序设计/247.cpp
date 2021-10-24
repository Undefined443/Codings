#include <iostream>
using namespace std;

int main()
{
	int y, d;
	cin >> y >> d;
	bool flag = false;
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) flag = true;
	int days[12]{ 31,28 + flag,31,30,31,30,31,31,30,31,30,31 };
	int i = 0;
	while (d > 0)
	{
		d -= days[i++];
	}
	d += days[--i];
	cout << i + 1 << ' ' << d;
}
