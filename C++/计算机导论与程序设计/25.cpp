#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	char a;
	cin >> a;
	if (a > 96) a -= 32;
	else a += 32;
	cout << a;
	return 0;
}
