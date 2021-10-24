#include <stdio.h>

int main()
{
	double h = 100.0;
	int n;
	scanf("%d", &n);
	double S = 0.0;
	for (int i = 0; i < n; i++)
	{
		S += h;
		h /= 2;
		S += h;
	}
	S -= h;
	printf("S=%.3f h=%.3f", S, h);
}
