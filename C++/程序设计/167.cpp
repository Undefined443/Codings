#include <iostream>
#include <cstring>
using namespace std;

typedef struct
{
	int num;
	int frequency = 1;
}Num;

int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	Num b[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	bool flag;
	for (int i = 0; i < n; i++)
	{
		flag = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = true;
			}
		}
		if (!flag) break;
	}
	int k = 0;
	b[0].num = a[0];
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == a[i + 1]) b[k].frequency++;
		else b[++k].num = a[i + 1];
	}
	k++;
	for (int i = 0; i < k; i++)
	{
		flag = false;
		for (int j = 0; j < k - i - 1; j++)
		{
			if (b[j].frequency < b[j + 1].frequency)
			{
				swap(b[j], b[j + 1]);
				flag = true;
			}
			else if (b[j].frequency == b[j + 1].frequency && b[j].num > b[j + 1].num)
			{
				swap(b[j], b[j + 1]);
				flag = true;
			}
		}
		if (!flag) break;
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d %d\n", b[i].num, b[i].frequency);
	}
}
