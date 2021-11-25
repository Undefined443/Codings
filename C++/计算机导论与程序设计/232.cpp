#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str[51] = { 0 };
	cin.getline(str, 50);
	int len = strlen(str);
	int i = 0, j = len - 1;
	for (; i < len / 2; i++, j--)
	{
		if (str[i] != str[j]) break;
	}
	if (i >= j) cout << "yes";
	else cout << "no";
}
