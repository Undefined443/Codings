#include <stdio.h>
int main()
{
	double distance, cost;
	int time;
	scanf("%lf%d", &distance, &time);
	if (distance <= 0) cost = 0;
	else if (distance <= 3) cost = 10;
	else if (distance <= 10) cost = 10 + (distance - 3) * 2;
	else cost = 24 + (distance - 10) * 3;
	cost = cost + time / 5 * 2;
	int costl = cost + 0.5;
	printf("%d", costl);
	return 0;
}
