#include <iostream>
using namespace std;

int main()
{
	for (int a = 0; a <= 3; a++)
	{
		for (int b = 0; b <= 4; b++)
		{
			for (int c = 0; c <= 5; c++)
			{
				if (a + b + c == 8)
					cout << a << ' ' << b << ' ' << c << endl;
			}
		}
	}
}
