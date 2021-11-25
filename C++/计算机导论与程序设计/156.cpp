#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	for (int i = 100; i <= 500; i++)
	{
		if ((i % 7 == 0 || i % 11 == 0) && (i % 77 != 0)) sum++;
	}
	cout << sum;
}
