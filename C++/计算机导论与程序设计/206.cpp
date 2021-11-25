#include <iostream>
#include <cstring>
using namespace std;

char* dele(char* str, char dele);

int main()
{
	char str[51] = { 0 };
	cin.getline(str, 51);
	char D = 0;
	cin >> D;
	cout << dele(str, D);
}

char* dele(char* str, char dele)
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] == dele)
		{
			str[i] = 0;
			strcat(str, str + i + 1);
			i--;
		}
	}
	return str;
}
