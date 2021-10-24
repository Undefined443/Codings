#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

int cmp(const void* a, const void* b)
{
	return (*(int*)b) - (*(int*)a);
}

int main()
{
	string str;
	int num[10] = { 0 };
	int k = 0;
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (isdigit(str[i]))
		{
			while (isdigit(str[i]))
			{
				num[k] = num[k] * 10 + str[i] - '0';
				i++;
			}
			k++;
		}
	}
	qsort(num, k, 4, cmp);
	for (int i = 0; i < k; i++)
	{
		cout << num[i] << ' ';
	}
}
