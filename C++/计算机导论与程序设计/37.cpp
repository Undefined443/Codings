#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int ji[n], ou[n];
	int xuhao_ji = 0, xuhao_ou = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		if (temp % 2 == 0)
		{
			ou[xuhao_ou] = temp;
			xuhao_ou += 1;
		}
		else
		{
			ji[xuhao_ji] = temp;
			xuhao_ji += 1;
		}
	}
	for (int j = 0; j < xuhao_ji - 1; j++)
	{
		for (int k = j + 1; k < xuhao_ji; k++)
		{
			if (ji[k] > ji[j])
			{
				int temp = ji[k];
				ji[k] = ji[j];
				ji[j] = temp;
			}
		}
	}
	for (int j = 0; j < xuhao_ou - 1; j++)
	{
		for (int k = j + 1; k < xuhao_ou; k++)
		{
			if (ou[k] > ou[j])
			{
				int temp = ou[k];
				ou[k] = ou[j];
				ou[j] = temp;
			}
		}
	}
	for (int i = 0; i < xuhao_ou; i++)
	{
		printf("%d ", ou[i]);
	}
	for (int i = 0; i < xuhao_ji; i++)
	{
		printf("%d ", ji[i]);
	}
}
