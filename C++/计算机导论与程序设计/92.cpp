#include <stdio.h>
int main()
{
	int salary;
	scanf("%d", &salary);
	int a = salary / 100, al = salary % 100;
	int b = al / 50, bl = al % 50;
	int c = bl / 20, cl = bl % 20;
	int d = cl / 10, dl = cl % 10;
	int e = dl / 5;
	int f = dl % 5;
	printf("%d %d %d %d %d %d", a, b, c, d, e, f);
	return 0;
}
