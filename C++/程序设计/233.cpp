#include <iostream>
#include <cstring>
using namespace std;

char* copystr(char* str, int n);

int main()
{
	char str[101] = { 0 };
	cin.getline(str, 101);
	int n;
	cin >> n;
	cout << copystr(str, n);
}

char* copystr(char* str, int n)
{
	if (strlen(str) < n) strcpy(str + n - 1, "error");
	return str + n - 1;
}
