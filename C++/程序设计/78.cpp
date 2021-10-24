#include <stdio.h>

int main()
{
	int n, m, c, i, j, stp = 0;
	scanf("%d%d%d", &n, &m, &c);
	char a[22][22] = { 0 };
	for (i = 1; i <= n; i++)
	{
		getchar();
		for (j = 1; j <= m; j++)
		{
			scanf("%c", &a[i][j]);
		}
	}
	i = 1, j = c;
	while (a[i][j])
	{
		switch (a[i][j])
		{
		case 'N':
			a[i][j] = 1;
			i--;
			break;
		case 'W':
			a[i][j] = 1;
			j--;
			break;
		case 'S':
			a[i][j] = 1;
			i++;
			break;
		case 'E':
			a[i][j] = 1;
			j++;
			break;
		default:
			printf("loop %d", stp);
			return 0;
			break;
		}
		stp++;
	}
	printf("out %d", stp);
	return 0;
}
