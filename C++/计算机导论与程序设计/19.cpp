#include <stdio.h>
int main()
{
	float a, b, h;
	scanf("%f%f%f", &a, &b, &h);
	float V = a * b * h;
	printf("%-.3f", V);
	return 0;
}
