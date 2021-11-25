#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int x);

int main()
{
	int n;
	cin >> n;
	if (isPrime(n))
		return 0;
	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0 && isPrime(i))
		{
			cout << i;
			n /= i;
			if (n != 1)
				cout << '*';
			i--;
		}
	}
}

bool isPrime(int x)
{
	if (x < 2)
		return false;
	int i;
	for (i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
			break;
	}
	if (i > sqrt(x))
		return true;
	else
		return false;
}
