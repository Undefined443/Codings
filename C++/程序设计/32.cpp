#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int a;
	cin >> a;
	int i = 0;
	while (a != 1)
	{
		if (a % 2 == 0) a /= 2;
		else a = 3 * a + 1;
		i++;
	}
	cout << i;
	return 0;
}
