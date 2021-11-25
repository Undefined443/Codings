#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int x = a * b;
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	if (b == 0)
	{
		cout << a;
		return 0;
	}
	int c = a % b;
	while (c)
	{
		a = b;
		b = c;
		c = a % b;
	}
	cout << b << " " << x / b << endl;
}
