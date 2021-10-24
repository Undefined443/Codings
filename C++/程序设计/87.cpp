#include <iostream>
using namespace std;

int main()
{
	int score, sum = 0, lianXu = 0;
	while (cin >> score, score)
	{
		if (score == 1)
		{
			lianXu = 0;
			sum += 1;
		}
		else
		{
			lianXu += 1;
			sum += 2 * (lianXu);
		}
	}
	cout << sum;
}
