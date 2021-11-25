#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	char ISBN[14] = { 0 };
	cin >> ISBN;
	int sum = 0;
	int k = 1;
	for (int i = 0; i < 11; i++)
	{
		if (isdigit(ISBN[i]))
		{
			sum += (ISBN[i] - '0') * k++;
		}
	}
	sum %= 11;
	sum = sum == 10 ? 'X' : sum + '0';
	if (sum == ISBN[12]) cout << "Right";
	else
	{
		ISBN[12] = sum;
		cout << ISBN;
	}
}
