#include <iostream>
using namespace std;

int main()
{
	while (1)
	{
		int time;
		cin >> time;
		if (time == 0) break;
		int turn = time / 90;
		int stream = turn * 60 * 3 + time % 90 * 3;
		cout << stream << endl;
	}
}
