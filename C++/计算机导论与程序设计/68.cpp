#include <iostream>
using namespace std;

int main()
{
	int year, day;
	cin >> year >> day;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) days[1] = 29;
	int temp = day;
	int i = 0;
	while (temp > 0)
	{
		temp -= days[i];
		i++;
	}
	int month = i;
	day = temp + days[i - 1];
	cout << month << " " << day;
}
