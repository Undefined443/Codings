#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int x = n * n * n;
	int sum = 0;
	int start = 1;
	while (sum != x)
	{
		sum = 0;
		int temp = start;
		for (int i = 0; i < n; i++)
		{
			sum += temp;
			temp += 2;
		}
		start += 2;
	}
	start -= 2;
	for (int i = 0; i < n; i++)
	{
		cout << start << " ";
		start += 2;
	}
}
