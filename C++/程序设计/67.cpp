#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	bool flag = false;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp == k)
		{
			cout << i << ' ';
			flag = true;
		}
	}
	if (!flag) cout << -1;
}
