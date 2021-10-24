#include <stdio.h>
int main()
{
	int a, b;
	char c;
	scanf("%d%c%d", &a, &c, &b);
	switch (c)
	{
	case '+':
		printf("%d%c%d=%d", a, c, b, a + b);
		break;
	case '-':
		printf("%d%c%d=%d", a, c, b, a - b);
		break;
	case '*':
		printf("%d%c%d=%d", a, c, b, a * b);
		break;
	case '/':
		if (b != 0) printf("%d%c%d=%d", a, c, b, a / b);
		break;
	case '%':
		if (b != 0) printf("%d%c%d=%d", a, c, b, a % b);
		break;
	default:
		break;
	}
	return 0;
}
