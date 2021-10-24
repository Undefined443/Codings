#include <stdio.h>
#include <ctype.h>

int main()
{
	char c;
	int n;
	int sum = 0;
	scanf("%c%d", &c, &n);
	char str[101] = { 0 };
	scanf("%s", &str);
	int i = 0;
	while (str[i])
	{
		switch (n)
		{
		case 0:
			if (str[i] == toupper(c) || str[i] == tolower(c)) sum++;
			break;
		case 1:
			if (str[i] == c) sum++;
			break;
		default:
			break;
		}
		i++;
	}
	printf("%d", sum);
}
