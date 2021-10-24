#include <stdio.h>
#include <string.h>

int main()
{
	char str[100] = { 0 };
	gets(str);
	int n = 0;
	bool flag = false;
	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 0; j < strlen(str) - n - 1; j++)
		{
			if (str[j] > str[j + 1])
			{
				int temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
				flag = true;
			}
		}
		if (!flag) break;
		n++;
	}
	puts(str);
}
