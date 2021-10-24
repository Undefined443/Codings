#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a;
	for (int i = 0; i < 3; i++)
	{
		cin >> b;
		if (b > a) a = b;
	}
	cout << a;
}
