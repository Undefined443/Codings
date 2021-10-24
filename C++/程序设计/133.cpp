#include <cstdio>
#include <cstdlib>
using namespace std;

bool flag = false;

class NUM
{
public:
	int coefficient;
	int exponent;
	void show();
};

int cmp(const void* p1, const void* p2);

int main()
{
	int n, m, t;
	scanf("%d%d%d", &n, &m, &t);
	NUM num[n + m];
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &num[i].coefficient, &num[i].exponent);
	}
	for (int i = n; i < n + m; i++)
	{
		scanf("%d%d", &num[i].coefficient, &num[i].exponent);
		if (t) num[i].coefficient *= -1;
	}
	qsort(num, n + m, sizeof(num[0]), cmp);
	int i = 1;
	if (num[0].exponent != num[1].exponent) num[0].show();
	else
	{
		num[1].coefficient += num[0].coefficient;
		num[1].show();
		i = 2;
	}
	while (i < n + m - 1)
	{
		if (num[i].exponent != num[i + 1].exponent)
		{
			if (num[i].coefficient > 0) putchar('+');
			num[i].show();
		}
		else num[i + 1].coefficient += num[i].coefficient;
		i++;
	}
	if (num[n + m - 1].coefficient > 0) putchar('+');
	num[n + m - 1].show();
	if (!flag) putchar('0');
}

void NUM::show()
{
	if (coefficient)
	{
		if (exponent == 0) printf("%d", coefficient);
		else if (coefficient == 1 && exponent == 1) printf("x");
		else if (coefficient == 1) printf("x^%d", exponent);
		else if (coefficient == -1 && exponent == 1) printf("-x");
		else if (coefficient == -1) printf("-x^%d", exponent);
		else if (exponent == 1) printf("%dx", coefficient);
		else printf("%dx^%d", coefficient, exponent);
		flag = true;
	}
}

int cmp(const void* p1, const void* p2)
{
	return ((NUM*)p1)->exponent - ((NUM*)p2)->exponent;
}
