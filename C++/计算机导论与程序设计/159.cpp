#include <stdio.h>

int Mul(int i);
double P(int m, int n);

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	printf("%.2f", P(m, n));
}

int Mul(int x)
{
	int temp = x - 1;
	while (temp)
	{
		x *= temp;
		temp -= 1;
	}
	return x;
}

double P(int m, int n)
{
	if (n > m)
	{
		int temp = m;
		m = n;
		n = temp;
	}
	return Mul(m) / Mul(n) / Mul(m - n);
}
