#include <stdio.h>
#include <math.h>
int main()
{
	double d, p, r, m;
	scanf("%lf%lf%lf", &d, &p, &r);
	m = log(p / (p - d * r)) / log(1 + r);
	printf("%.2f", m);
}
