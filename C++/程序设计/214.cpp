#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	char str[101] = { 0 };
	cin.getline(str, 101);
	int upper = 0, lower = 0, space = 0, digit = 0, other = 0;
	int i = 0;
	while (str[i])
	{
		if (isupper(str[i])) upper++;
		else if (islower(str[i])) lower++;
		else if (isdigit(str[i])) digit++;
		else if (isspace(str[i])) space++;
		else other++;
		i++;
	}
	cout << upper << ' ' << lower << ' ' << space << ' ' << digit << ' ' << other;
}
