#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	if (b > a)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	int x = a * b;
	int c = a % b;
	while (c)
	{
		a = b;
		b = c;
		c = a % b;
	}
	cout << b << ' ' << x / b;
}
