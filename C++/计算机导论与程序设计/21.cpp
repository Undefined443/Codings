#include <iostream>
using namespace std;
int main()
{
	int input, a, b, c, d, e;
	cin >> input;
	a = input / 10000 % 10;
	b = input / 1000 % 10;
	c = input / 100 % 10;
	d = input / 10 % 10;
	e = input % 10;
	cout << a << " " << b << " " << c << " " << d << " " << e;
	return 0;
}
