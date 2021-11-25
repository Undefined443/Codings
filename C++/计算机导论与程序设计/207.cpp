#include <iostream>
#include <cstring>
using namespace std;

void wd_sort(char(*str)[20], int n);

int main()
{
	char str[10][20] = { 0 };
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
	}
	wd_sort(str, N);
	for (int i = 0; i < N; i++)
	{
		cout << str[i] << endl;
	}
}

void wd_sort(char(*str)[20], int n)
{
	bool flag;
	for (int i = 0; i < n; i++)
	{
		flag = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (str[j][0] > str[j + 1][0])
			{
				char t[20] = { 0 };
				strcpy(t, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j + 1], t);
				flag = true;
			}
		}
		if (!flag) break;
	}
}
