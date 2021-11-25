#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	int sum = 0;
	for (int i = 0; i < n - 2; i++)
	{
		int c;
		cin >> c;
		if ((c - b) * (b - a) < 0) sum++;
		a = b;
		b = c;
	}
	cout << sum << endl;
 } 
