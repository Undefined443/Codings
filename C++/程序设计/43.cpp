#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int temp = 0;
	if (n)
	{
		temp = n % 10;
		n /= 10;
	}
	int max, min;
	max = min = temp;
	int i = 1;
	while (n)
	{
		temp = n % 10;
		if (temp > max)
			max = temp;
		else if (temp < min)
			min = temp;
		i++;
		n /= 10;
	}
	printf("%d %d %d", i, max, min);
}
