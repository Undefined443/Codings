#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a > c)
	{
		int temp = a;
		a = c;
		c = temp;
	}
	if (b > c)
	{
		int temp = b;
		b = c;
		c = temp;
	}
	if (a + b > c) cout << a + b + c;
	else cout << "no";
}
