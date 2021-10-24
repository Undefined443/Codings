#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int num;
	scanf("%d", &num);
	int max[2] = { num,0 };
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &num);
		if (num > max[0])
		{
			max[0] = num;
			max[1] = i;
		}
	}
	printf("%d %d %d", n, max[0], max[1]);
}
