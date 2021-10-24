#include <iostream>
using namespace std;
int main()
{
	int week, index, number;
	cin >> week >> index >> number;
	int num = number % 10;
	if (index < 200 || week == 6 || week == 7) cout << num << " no";
	else if (index >= 200 && index < 400)
	{
		if (num % 5 == week) cout << num << " yes";
		else cout << num << " no";
	}
	else if (num % 2 == week % 2) cout << num << " yes";
	else cout << num << " no";
	return 0;
}
