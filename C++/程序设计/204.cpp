#include <stdio.h>
#include <string.h>

void count(char* str, char* find);

int main()
{
	char string[101] = { 0 };
	char word[9] = { 0 };
	char temp[9] = { 0 }; 
	gets(string);
	gets(word);
	count(string, word);
}

void count(char* str, char* find)
{
	char temp[9] = { 0 };
	int sum = 0;
	int i = 0, k = 0;
	while (i < strlen(str))
	{
		while (str[i] != ' ' && str[i])
		{
			temp[k++] = str[i];
			i++;
		}
		if (!strcmp(temp, find)) sum++;
		k = 0;
		memset(temp, 0, strlen(temp));
		i++;
	}
	printf("%s %d\n", find, sum);
}
