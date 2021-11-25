#include <iostream>
using namespace std;

void sort(int* num, int N, int* odd, int* even, int* m, int* n);

int main()
{
	int num[20] = { 0 };
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	int odd[20] = { 0 };
	int even[20] = { 0 };
	int m, n;
	sort(num, N, odd, even, &m, &n);
	for (int i = 0; i < m; i++)
	{
		cout << odd[i] << ' ';
	}
	cout << ' ' << ' ';
	for (int i = 0; i < n; i++)
	{
		cout << even[i] << ' ';
	}
}

void sort(int* num, int N, int* odd, int* even, int* m, int* n)
{
	*m = 0, *n = 0;
	bool flag;
	for (int i = 0; i < N; i++)
	{
		flag = false;
		for (int j = 0; j < N - i - 1; j++)
		{
			if (num[j] > num[j + 1])
			{
				int t = num[j];
				num[j] = num[j + 1];
				num[j + 1] = t;
				flag = true;
			}
		}
		if (!flag) break;
	}
	for (int i = 0; i < N; i++)
	{
		if (num[i] % 2) odd[(*m)++] = num[i];
		else even[(*n)++] = num[i];
	}
}
