#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int p;
	cin >> p;
	for (int i = p + 1; i < 10; i++)
	{
		cout << array[i] << ' ';
	}
	for (int i = 0; i <= p; i++)
	{
		cout << array[i] << ' ';
	}
}
