#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	scanf("%d", &n);
	int cha = 0, chal = 0;
	int today, yesterday;
	scanf("%d", &yesterday);
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &today);
		chal = abs(today - yesterday);
		if (chal > cha) cha = chal;
		yesterday = today;
	}
	printf("%d", cha);
	return 0;
}
