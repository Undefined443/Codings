#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	char ori[51] = {0};
	char str[101] = {0};
	cin.getline(ori, 51);
	int i = 0;
	int k = 0;
	int sum = 0;
	while (ori[i])
	{
		if (isdigit(ori[i]))
		{
			char t = ori[i - 1];
			while (isdigit(ori[i]))
			{
				sum = sum * 10 + ori[i] - '0';
				i++;
			}
			i--;
			for (int j = 1; j < sum; j++)
			{
				str[k++] = t;
			}
			sum = 0;
		}
		else
		{
			str[k++] = ori[i];
		}
		i++;
	}
	cout << str;
}
