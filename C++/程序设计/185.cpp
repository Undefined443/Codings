#include <stdio.h>
int main()
{
	double a;
	scanf("%lf", &a);
	double x = a;
	double temp;
	do
	{
		temp = x;
		x = (x + a / x) / 2;
	} while (temp - x >= 0.00001);
	printf("%.5f", x);
}
