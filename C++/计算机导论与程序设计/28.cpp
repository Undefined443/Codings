#include <iostream>
using namespace std;
int main()
{
	int year, month;
	cin >> year >> month;
	/*
		�����Ϊ��ͨ������������ꡣ
		��ͨ���꣺���������4�ı����ģ��Ҳ���100�ı�����Ϊ��ͨ���ꡣ
		�������꣺����������������ģ�������400�ı��������������ꡣ
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

