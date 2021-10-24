#include <stdio.h>
#include <math.h>
int main()
{
	double x, c;
	scanf("%lf", &x);
	if (x < 0)
	{
		c = (x + 1) * (x + 1) + 2 * x + 1 / x;
	}
	else c = sqrt(x);
	printf("%.2f", c);
}

