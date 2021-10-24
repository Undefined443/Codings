#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	char str[101] = { 0 };
	cin.getline(str, 101);
	int sum = 0;
	int i = 0;
	while (str[i])
	{
		if (isdigit(str[i]))
		{
			sum = sum * 10 + str[i] - '0';
		}
		i++;
	}
	for (int i = sum / 2; i > 1; i--)
	{
		if (sum % i == 0)
		{
			cout << i;
			return 0;
		}
	}
	cout << sum;
}
