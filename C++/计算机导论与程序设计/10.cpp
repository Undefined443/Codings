#include <stdio.h>
int main()
{
	int T;
	scanf("%d", &T);
	double t = (T - 32.0) * 5.0 / 9.0;
	printf("%.2f", t);
	return 0;
}
