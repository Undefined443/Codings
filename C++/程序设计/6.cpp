#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int a[n][2];
	int sum = 0;
	int temp = 0;
	for (int i = 0; i < n; i++)//�����ȡ����ֵ��a[i][0]
	{
		scanf("%d", &a[i][0]);
		temp = a[i][0];
		while (temp)//�����λ�ĺͲ���ֵ��a[i][1] 
		{
			sum += temp % 10;
			temp /= 10;
		}
		a[i][1] = sum;
		sum = 0;
	}
	for (int i = 0; i < n - 1; i++)//����ȽϺ͵Ĵ�С��������ΪҪ��i+1�Ƚϴ�С�����ѭ����n-1ֹͣ 
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
			else if (a[x][1] == a[i][1] && a[x][0] < a[i][0])//�������ͬ�����
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
