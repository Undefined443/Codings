#include <iostream>
using namespace std;

int main()
{
	char str[101] = { 0 };
	cin.getline(str, 101);
	int length = 0;
	int max = 0;
	int i = 0;
	while (str[i] != '.')
	{
		if (str[i] == ' ')
		{
			if (length > max) max = length;
			length = 0;
			i++;
			continue;
		}
		length++;
		i++;
	}
	if (length > max) max = length;
	cout << max;
}
