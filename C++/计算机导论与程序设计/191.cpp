#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (isupper(str[i])) str[i] = 'Z' + 'A' - str[i];
		else if (islower(str[i])) str[i] = 'z' + 'a' - str[i];
	}
	cout << str;
}
