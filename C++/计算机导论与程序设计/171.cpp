#include <stdio.h>

typedef struct
{
public:
	int ID;
	int h1, m1;
	int h2, m2;
	int sum;
}Stu;

void sort(Stu* a, int n, const char* mode);
void swap(Stu* a, Stu* b);

int main()
{
	Stu a[100];
	Stu b[100];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d:%d %d:%d", &a[i].ID, &a[i].h1, &a[i].m1, &a[i].h2, &a[i].m2);
		a[i].sum = (a[i].h2 - a[i].h1) * 60 + (a[i].m2 - a[i].m1);
	}
	sort(a, n, "ID");
	b[0] = a[0];
	int k = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i - 1].ID != a[i].ID)
		{
			b[++k] = a[i];
		}
		else
		{
			b[k].sum += a[i].sum;
		}
	}
	sort(b, k + 1, "sum");
	for (int i = 0; i < k+1; i++)
	{
		printf("%d %d\n", b[i].ID, b[i].sum);
	}
}

void sort(Stu* a, int n, const char* mode)
{
	int flag;
	if (mode == "ID")
	{
		for (int i = 0; i < n; i++)
		{
			flag = 0;
			for (int j = 0; j < n - i - 1; j++)
			{
				if (a[j].ID > a[j+1].ID)
				{
					swap(&a[j], &a[j + 1]);
					flag = 1;
				}
			}
			if (!flag) break;
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			flag = 0;
			for (int j = 0; j < n - i - 1; j++)
			{
				if (a[j].sum < a[j + 1].sum)
				{
					swap(&a[j], &a[j + 1]);
					flag = 1;
				}
				else if (a[j].sum == a[j + 1].sum && a[j].ID > a[j + 1].ID)
				{
					swap(&a[j], &a[j + 1]);
					flag = 1;
				}
			}
			if (!flag) break;
		}
	}
}

void swap(Stu* a, Stu* b)
{
	Stu temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
