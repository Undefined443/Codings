#include <iostream>
using namespace std;

int main()
{
	int S, A = 0, fee = 0;
	cin >> S;
	A = S - 3500;
	if (A > 0)
	{
		if (A > 35000)
		{
			fee += (A - 35000) * 0.3;
			A = 35000;
		}
		if (A > 9000)
		{
			fee += (A - 9000) * 0.25;
			A = 9000;
		}
		if (A > 4500)
		{
			fee += (A - 4500) * 0.2;
			A = 4500;
		}
		if (A > 1500)
		{
			fee += (A - 1500) * 0.1;
			A = 1500;
		}
		fee += A * 0.03;
	}
	cout << S - fee;
}
