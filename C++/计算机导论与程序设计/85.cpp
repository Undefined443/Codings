#include <cstdio>
#include <cstring>
#include <cctype>

void lower(char* str);
double similarity(char* str1, char* str2);

int main()
{
	char s1[101] = { 0 }, s2[101] = { 0 };
	gets(s1);
	gets(s2);
	lower(s1);
	lower(s2);
	printf("%.3f", similarity(s1, s2));
}

void lower(char* str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		str[i] = tolower(str[i]);
	}
}

double similarity(char* str1, char* str2)
{
	int max = 0, length = 0, len1 = strlen(str1), len2 = strlen(str2);
	for (int i = 0; i < len2; i++)
	{
		for (int j = 0; j < len1; j++)
		{
			if (str2[i] == str1[j])
			{
				int m = i;
				while (str2[m] == str1[j] && m < len2 && j < len1)
				{
					m++;
					j++;
					length++;
				}
				j--;
				if (length > max) max = length;
				length = 0;
			}
		}
	}
	return 2.0 * max / (len1 + len2);
}
