#include <stdio.h>
#include <math.h>
int main()
{
	int n, fn = 0;
	scanf("%d", &n);
	for (int index = n; index >= 1; index--)
	{
		fn = fn + pow(-1, index - 1) * index * (index + 1);
	}
	printf("fn=%d", fn);
}
