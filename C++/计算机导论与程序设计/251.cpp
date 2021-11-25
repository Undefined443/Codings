#include <stdio.h>

struct Time
{
	int year;
	int month;
	int day;
} time;

int main()
{
	int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i, k = 0;
	scanf("%d,%d,%d", &time.year, &time.month, &time.day);
	if ((time.year % 4 == 0 && time.year % 100 != 0) || time.year % 400 == 0)
	{
		k = 1;
	}
	for (i = 0; i < time.month - 1; i++)
	{
		if (i == 1 && k == 1)
		{
			time.day += a[i] + 1;
		}
		else
		{
			time.day += a[i];
		}
	}
	printf("%d", time.day);
}
