#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n);

int main()
{
	int n;
	cin >> n;
	int i;
	for (i = 3; i < n / 2; i += 2)
	{
		if (isPrime(i) && isPrime(n - i)) break;
	}
	cout << i << " " << n - i;
}

bool isPrime(int n)
{
	int i;
	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0) break;
	}
	if (i * i > n)
		return true;
	else
		return false;
}
