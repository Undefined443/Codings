#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int a[n][2];
	int sum = 0;
	int temp = 0;
	for (int i = 0; i < n; i++)//逐个读取并赋值给a[i][0]
	{
		scanf("%d", &a[i][0]);
		temp = a[i][0];
		while (temp)//计算各位的和并赋值给a[i][1] 
		{
			sum += temp % 10;
			temp /= 10;
		}
		a[i][1] = sum;
		sum = 0;
	}
	for (int i = 0; i < n - 1; i++)//逐个比较和的大小并排序。因为要和i+1比较大小，因此循环在n-1停止 
	{
		for (int x = i + 1; x < n; x++)
		{
			if (a[x][1] > a[i][1])
			{
				temp = a[x][1];
				a[x][1] = a[i][1];
				a[i][1] = temp;
				temp = a[x][0];
				a[x][0] = a[i][0];
				a[i][0] = temp;
			}
			else if (a[x][1] == a[i][1] && a[x][0] < a[i][0])//处理和相同的情况
			{
				temp = a[x][0];
				a[x][0] = a[i][0];
				a[i][0] = temp;
				temp = a[x][1];
				a[x][1] = a[i][1];
				a[i][1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", a[i][0], a[i][1]);
	}
}
