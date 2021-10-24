#include <iostream>
using namespace std;
int main()
{
	int a, sum = 0;
	cin >> a;
	while (a)
	{
		int temp = a % 10;
		a /= 10;
		sum += temp;
	}
	cout << sum << endl;
}
