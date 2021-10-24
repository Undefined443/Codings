#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	double a = 1, b = 1;
	double sum = 0;
	int index = 1;
	for (int i = 0; i < n; i++)
	{
		sum += index * a / b;
		a += 1;
		b += 2;
		index = -index;
	}
	printf("%.3f", sum);
}
