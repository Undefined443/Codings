#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int temp = n;
	int wei = 0;
	while (temp)
	{
		temp /= 10;
		wei++;
	}
	int digit[wei];
	temp = n;
	int sum = 0;
	for (int i = 0; i < wei; i++)
	{
		digit[i] = temp % 10;
		sum += digit[i];
		temp /= 10;
	}
	int reverse = 0;
	for (int i = 0; i < wei; i++)
	{
		reverse += pow(10, i) * digit[wei - 1 - i];
	}
	if (reverse == n)
		cout << sum;
	else
		cout << "no";
}
