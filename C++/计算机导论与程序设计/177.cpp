#include <iostream>
using namespace std;

int main()
{
	char str[101] = { 0 };
	cin.getline(str, 101);
	int sum = 0;
	int i = 0;
	while (str[i])
	{
		sum += str[i];
		i++;
	}
	int x = sum % 256;
	cout << x;
}
