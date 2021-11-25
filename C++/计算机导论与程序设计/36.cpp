#include <stdio.h>

int main()
{
	int m;
	scanf("%d", &m);
	int data[m][m];
	for (int row = 0; row < m; row++)
	{
		for (int column = 0; column < m; column++)
		{
			scanf("%d", &data[row][column]);
		}
	}
	int sum[m + m + 2] = { 0 };
	for (int row = 0; row < m; row++)
	{
		for (int column = 0; column < m; column++)
		{
			sum[row] += data[row][column];
		}
	}
	for (int column = 0; column < m; column++)
	{
		for (int row = 0; row < m; row++)
		{
			sum[m + column] += data[row][column];
		}
	}
	for (int row = 0, column = 0; row < m; row++, column++)
	{
		sum[m + m] += data[row][column];
	}
	for (int row = 0, column = m - 1; row < m; row++, column--)
	{
		sum[m + m + 1] += data[row][column];
	}
	for (int chose = 0; chose < m + m + 1; chose++)
	{
		for (int next = chose + 1; next < m + m + 2; next++)
		{
			if (sum[next] > sum[chose])
			{
				int temp = sum[chose];
				sum[chose] = sum[next];
				sum[next] = temp;
			}
		}
	}
	for (int i = 0; i < m + m + 2; i++)
	{
		printf("%d ", sum[i]);
	}
}
