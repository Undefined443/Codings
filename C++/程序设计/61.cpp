#include <stdio.h>
int main()
{
	int input, a, b, c;
	scanf("%d", &input);
	a = input / 100 % 10;
	b = input / 10 % 10;
	c = input % 10;
	printf("%d %d %d", a, b, c);
	return 0;
}
