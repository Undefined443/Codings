#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int New, Old;
	cin >> Old;
	int x = 1;
	for (int i = 1; i < n; i++)
	{
		cin >> New;
		if (New != Old) x += 1;
		Old = New;
	}
	cout << x;
	return 0;
}
