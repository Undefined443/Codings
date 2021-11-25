#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	double intpart, fpart;
	fpart = modf(sqrt(n), &intpart);
	if (fpart == 0.0)
	{
		cout << int(intpart);
	}
	else cout << "no";
}
