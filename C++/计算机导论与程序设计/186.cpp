#include <stdio.h>
#include <math.h>

double f(double x);
double f1(double x);

int main()
{
	double x, x0;
	scanf("%lf", &x0);
	double temp;
	do
	{
		x = x0 - f(x0) / f1(x0);
		temp = x0;
		x0 = x;
	}while(fabs(x - temp) > 1E-5);
	printf("%.2f", x);
}

double f(double x)
{
	return 2 * x * x * x - 4 * x * x + 3 * x - 6;
}

double f1(double x)
{
	return 6 * x * x - 8 * x + 3;
}
