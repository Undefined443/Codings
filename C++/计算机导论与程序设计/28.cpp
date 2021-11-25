#include <iostream>
using namespace std;
int main()
{
	int year, month;
	cin >> year >> month;
	/*
		闰年分为普通闰年和世纪闰年。
		普通闰年：公历年份是4的倍数的，且不是100的倍数，为普通闰年。
		世纪闰年：公历年份是整百数的，必须是400的倍数才是世纪闰年。
	*/
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		if (month == 2) cout << 29 << endl;
		else goto usual;
	}
	else
	{
	usual:
		if (month == 2) cout << 28 << endl;
		else if (month < 8 && month % 2 == 1 || month >= 8 && month % 2 == 0) cout << 31 << endl;
		else cout << 30 << endl;
	}
	return 0;
}

