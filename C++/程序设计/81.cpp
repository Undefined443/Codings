#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main()
{
	string find, str, temp;
	bool toggle;
	int n = 0;
	cin >> find >> toggle >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		str = temp;
		if (!toggle)
		{
			for (int i = 0; i < temp.length(); i++)
			{
				str[i] = tolower(temp[i]);
			}
			for (int i = 0; i < find.length(); i++)
			{
				find[i] = tolower(find[i]);
			}
		}
		if (str.find(find) != string::npos) cout << temp << endl;
	}
}
