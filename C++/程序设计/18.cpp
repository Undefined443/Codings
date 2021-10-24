#include <stdio.h>
int main()
{
	int a;
	char b;
	scanf("%d,%c", &a, &b);
	if ((a >= 0 && a<= 4) && (b >= '0' && b <= '5'))
	{
		printf("%d,%c", a + b, a + b);
	}
	return 0;
}
