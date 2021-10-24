#include <stdio.h>
#include <ctype.h>
using namespace std;

int main()
{
	char password [51] = { 0 };
	gets(password );
	bool length = false, upper = false, lower = false, digit = false, punct = false;
	if (!password [0])
	{
		putchar('0');
		return 0;
	}
	if (password [8]) length = true;
	int i = 0;
	while (password [i])
	{
		if (isupper(password [i])) upper = true;
		if (islower(password [i])) lower = true;
		if (isdigit(password [i])) digit = true;
		if (ispunct(password [i])) punct = true;
		i++;
	}
	printf("%d", length + upper + lower + digit + punct);
}
