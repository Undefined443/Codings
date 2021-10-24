#include <iostream>
using namespace std;

int main()
{
	int num, price, day;
	int cash = 0;
	cin >> num >> price >> day;
	int hold = num;
	for (int i = 0; i < day; i++)
	{
		cin >> num >> price;
		hold += num;
		cash -= num * price;
	}
	cout << hold * price + cash;
}
