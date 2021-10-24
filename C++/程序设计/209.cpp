#include <iostream>
#include <cstring>
using namespace std;

char* char_ch(char* str, char* ch, int n);

int main()
{
	char str[50] = { 0 };
	cin.getline(str, 50);
	int n;
	cin >> n;
	char ch[50] = { 0 };
	cout << char_ch(str, ch, n);
}

char* char_ch(char* str, char* ch, int n)
{
	strcpy(ch, str + n + 1);
	return ch;
}
