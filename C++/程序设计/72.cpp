#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str, maxstr;
	int max = 0;
	while (getline(cin, str), str != "***end***")
	{
		if (str.length() > max)
		{
			maxstr = str;
			max = str.length();
		}
	}
	cout << max << endl << maxstr;
}
