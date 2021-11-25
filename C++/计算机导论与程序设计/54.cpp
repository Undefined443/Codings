#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int a = 1; a < 10; a++)
	{
		for (int b = 0; b < 10; b++)
		{
			for (int c = 1; c < 10; c++)
			{
				if ((a + c) * 100 + 2 * b * 10 + a + c == n) cout << a << " " << b << " " << c << endl;
			}
		}
	}
}
