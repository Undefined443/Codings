#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int i = 0;
	int temp = n;
	while (temp)
	{
		temp /= 10;
		i += 1;
	}
	cout << i << endl;
	temp = n;
	for (int n = 0; n < i; n++)
	{
		cout << temp % 10;
		temp /= 10;
	}
}
