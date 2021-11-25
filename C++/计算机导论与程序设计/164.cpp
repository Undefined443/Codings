#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[100] = { 0 };
	gets(str);
	char upper[100] = { 0 };
	int i = 0;
	int k = 0;
	while (str[i])
	{
		if (isupper(str[i])) upper[k++] = str[i];
		i++;
	}
	bool flag = false;
	for (int i = 0; i < k; i++)
	{
		flag = false;
		for (int j = 0; j < k - i - 1; j++)
		{
			if (upper[j] > upper[j + 1])
			{
				int temp = upper[j];
				upper[j] = upper[j + 1];
				upper[j + 1] = temp;
				flag = true;
			}
		}
		if (!flag) break;
	}
}
