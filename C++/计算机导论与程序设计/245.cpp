#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> light(n, 1);
	for (int i = 2; i <= m; i++)
	{
		int t = 1;
		while (i * t <= n)
		{
			light[i * t - 1] *= -1;
			t++;
		}
	}
	for (int j = 0; j < n; j++)
	{
		if (light[j] == 1)
		{
			cout << j + 1 << ' ';
		}
	}
}
