#include <stdio.h>
#include <math.h>
void functionSolver(double, double, double);
int main()
{
	double a, b, c;
	scanf("%lf%*c%lf%*c%lf", &a, &b, &c);
	functionSolver(a, b, c);
}
void functionSolver(double a, double b, double c)
{
	double D = b * b - 4 * a * c;
	if (D > 0)
	{
		double x1 = sqrt(-b + (b * b - 4 * a * c)) / (2 * a);
		double x2 = sqrt(-b - (b * b - 4 * a * c)) / (2 * a);
		printf("x1=%f, x2=%.2f\n", x1, x2);
	}
	else
	{
		if (D == 0)
		{
			double x = -b / (2 * a);
			printf("x1=x2=%.2f\n", x);
		}
		else
		{
			if (D < 0)
			{
				printf("方程没有实根\n");
			}
		}
	}
}
