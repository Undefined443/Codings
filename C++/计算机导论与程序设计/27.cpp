#include <stdio.h>
int main()
{
	double powerUsage, cost;
	scanf("%lf", &powerUsage);
	if (powerUsage <= 110.0) cost = 0.5 * powerUsage;
	else if (powerUsage <= 210.0) cost = 55.0 + 0.55 * (powerUsage - 110.0);
	else cost = 110.0 + 0.7 * (powerUsage - 210.0);
	printf("%.2f", cost);
	return 0;
}
