#include <iostream>
using namespace std;
int main()
{
	int grade;
	cin >> grade;
	if (grade < 60) cout << 'E';
	else if (grade < 70) cout << 'D';
	else if (grade < 80) cout << 'C';
	else if (grade < 90) cout << 'B';
	else cout << 'A';
}
