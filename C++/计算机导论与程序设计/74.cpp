#include <stdio.h>

int main()
{
	char str[51] = { 0 };
	gets(str);
	int i = 0;
	int a = 0, b = 0, c = 0;//'(', ')', '[', ']', '{', '}'
	while (str[i])
	{
		switch (str[i])
		{
		case '(':
			a++;
			break;
		case ')':
			a--;
			break;
		case '[':
			b++;
			break;
		case ']':
			b--;
			break;
		case '{':
			c++;
			break;
		case '}':
			c--;
			break;
		default:
			break;
		}
		i++;
	}
	if (!(a || b || c)) printf("yes");
	else printf("no");
}
