#include <iostream>
using namespace std;

int main()
{
	for (int a = 1; a <= 20; a++)
	{
		for (int b = 0; b <= 33; b++)
		{
			int c = 100 - a - b;
			if (5 * a + 3 * b + c / 3.0 == 100)
				cout << a << ' ' << b << ' ' << c << endl;
		}
	}
}
