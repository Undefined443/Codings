#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int factorial = 1;
	int sumFac = 0;
	for (int i = 1; i <= n; i++)
	{
		factorial *= i;
	}
	cout << n << " " << factorial << " ";
	for (int i = 1; i <= n; i++)
	{
		factorial = 1;
		for (int k = 1; k <= i; k++)
		{
			factorial *= k;
		}
		sumFac += factorial;
	}
	cout << sumFac;
}
