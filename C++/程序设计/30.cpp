#include <iostream>
using namespace std;
int main()
{
	int max, min;
	cin >> min >> max;
	if (min <= 1) min = 2;
	for (int num = min; num < max; num++)
	{
		int sum = 0;
		for (int i = 1; i < num; i++)
		{
			if ((num % i) == 0)
			{
				sum += i;
			}
		}
		if (sum == num) cout << num << endl;
	}
}
