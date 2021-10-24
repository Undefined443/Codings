#include <cstdio>

void place(int(*target)[7], int m, int n, int *data);

int main()
{
	int a[7][7] = { 0 };
	int m, n;
	scanf("%d%d", &n, &m);
	int data[100] = { 0 };
	for (int i = 0; i < m * n; i++)
	{
		scanf("%d", &data[i]);
	}
	bool flag;
	for (int i = 0; i < m * n; i++)
	{
		flag = false;
		for (int j = 0; j < m * n - i - 1; j++)
		{
			if (data[j] > data[j + 1])
			{
				int t = data[j];
				data[j] = data[j + 1];
				data[j + 1] = t;
				flag = true;
			}
		}
		if (!flag) break;
	}
	place(a, m, n, data);
	for (int y = 0; y < n - 1; y++)
	{
		for (int x = 0; x < m; x++)
		{
			printf("%3d", a[x][y]);
		}
		printf("\n");
	}
	for (int x = 0; x < m; x++)
	{
		printf("%3d", a[x][n - 1]);
	}
}

void place(int(*target)[7], int m, int n, int *data)
{
	int i = 0;
	int x;
	int y = 0;
	while (i < m * n)
	{
		for (x = m - 1; x >= 0; x--)
		{
			target[x][y] = data[i++];
		}
		y++;
		for (x = 0; x < m; x++)
		{
			target[x][y] = data[i++];
		}
		y++;
	}
}
