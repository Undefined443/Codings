#include <iostream>
using namespace std;

int main()
{
	char str[101] = { 0 };
	cin.getline(str, 101);
	int i = 0;
	while (str[i])
	{
		i++;
	}
	cout << i;
}
