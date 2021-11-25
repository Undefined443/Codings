#include <stdio.h>
#include <ctype.h>

int main()
{
	char str[10000] = { 0 };
	char op;
	int num[2] = { 0 };
	int index = 0;
	gets(str);
	int i = 0;
	while (str[i])
	{
		if (isdigit(str[i]))
		{
			while (isdigit(str[i]))
			{
				num[index] = 10 * num[index] + str[i] - '0';
				i++;
			}
			index = 1;
			i--;
		}
		else if (ispunct(str[i]))
		{
			op = str[i];
		}
		i += 2;
	}
	switch (op)
	{
	case '+':
		printf("%d", num[0] + num[1]);
		break;
	case '-':
		printf("%d", num[0] - num[1]);
		break;
	case '*':
		printf("%d", num[0] * num[1]);
		break;
	case '/':
		printf("%d", num[0] / num[1]);
		break;
	case '%':
		printf("%d", num[0] % num[1]);
		break;
	default:
		break;
	}
}
