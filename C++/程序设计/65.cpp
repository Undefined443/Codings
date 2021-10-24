#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int sum;
	do
	{
		sum = 0;
		while (n)
		{
			int temp = n % 10;
			n /= 10;
			sum += temp;
		}
		n = sum;
	} while (sum > 9);
	cout << sum;
}
