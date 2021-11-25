#include <stdio.h>
int main()
{
	double A[3] = { 2,3 };
	double B[3] = { 1,2 };
	double sum = 2 + 3.0 / 2;
	int n;
	scanf("%d", &n);
	for (int i = 2; i < n; i++)
	{
		A[2] = A[1] + A[0];
		B[2] = B[1] + B[0];
		sum += A[2] / B[2];
		A[0] = A[1];
		A[1] = A[2];
		B[0] = B[1];
		B[1] = B[2];
	}
	printf("%.2f", sum);
}
