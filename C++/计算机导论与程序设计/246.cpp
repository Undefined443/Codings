#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void lower(char* str)
{
	int i = 0;
	while (str[i])
	{
		str[i] = tolower(str[i]);
		i++;
	}
}
int count(char* str, char* find)
{
	lower(str);
	lower(find);
	int start = 0, end = 0;
	int len = strlen(str);
	int sum = 0;
	while (start < len)
	{
		while (str[end] != ' ' && end < len)
		{
			end++;
		}
		str[end] = 0;
		if (!strcmp(&str[start], find)) sum++;
		start = ++end;
	}
	return sum;
}

int main()
{
	char str[100] = { 0 };
	char find[8] = { 0 };
	cin.getline(str, 100);
	cin >> find;
	cout << find << ' ' << count(str, find);
}
