#include <stdio.h>

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int num[m][n];
	for (int row = 0; row < m; row++)//Input all the data
	{
		for (int column = 0; column < n; column++)
		{
			scanf("%d", &num[row][column]);
		}
	}
	for (int row = 0; row < m; row++)
	{
		int start[50] = {-1}, end[50] = {-1};
		int group = 0;
		if (num[row][0])
				start[0] = 0;
		for (int column = 1; column < n; column++)
		{
			
			if (num[row][column] && !num[row][column - 1])//0,1
			{
				start[group] = column;
			}
			else if (!num[row][column] && num[row][column - 1])//1,0
			{
				end[group] = column - 1;
				group += 1;
			}
		}
		if (num[row][n - 1])
		{
			end[group] = n - 1;
			group += 1;
		}
		int longestGrp = 0;
		int longest = 0;
		for (int i = 0; i < group; i++)
		{
			if (end[i] - start[i] > longest)
			{
				longest = end[i] - start[i];
				longestGrp = i;
			}
		}
		printf("%d %d\n", start[longestGrp], end[longestGrp]);
	}
}
