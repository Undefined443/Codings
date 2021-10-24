#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int x);

int main()
{
	int n;
	cin >> n;
	int a1 = 1, a2 = 1, a3 = 1;
	for (int i = 2; i < n; i++)
	{
		a3 = a1 + a2;
		a1 = a2;
		a2 = a3;
	}
	if (isPrime(a3))
		cout << "yes";
	else
		cout << a3;
}

bool isPrime(int x)
{
	int i;
	for (i = 2; i <= int(sqrt(x)); i++)
	{
		if (x % i == 0)
			break;
	}
	if (i == int(sqrt(x)) + 1)
		return true;
	else
		return false;
}
