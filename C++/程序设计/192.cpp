#include <stdio.h>

int main()
{
	int a[5];
	for (int i = 0; i < 4; i++)
	{
		scanf("%d,", &a[i]);
	}
	scanf("%d", &a[4]);
	for (int i = 4; i >= 0; i--)
	{
		printf("%d ", a[i]);
	}
}
