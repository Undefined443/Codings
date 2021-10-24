#include <iostream>
using namespace std;

bool seat[20][5]{};

int length(int row)
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (!seat[row][i]) sum++;
	}
	return sum;
}

void book(int p, const int row)
{
	for (int i = 0; i < 5; i++)
	{
		if (!seat[row][i])
		{
			seat[row][i] = true;
			cout << 5 * row + i + 1 << ' ';
			p--;
			if (!p) break;
		}
	}
	cout << endl;
}

int random(int p)
{
	for (int row = 0; row < 20; row++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (!seat[row][i])
			{
				seat[row][i] = true;
				cout << 5 * row + i + 1 << ' ';
				p--;
				if (!p)
				{
					cout << endl;
					return 0;
				}
			}
		}
	}
}

int main()
{
	int n, p, row;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		for (row = 0; row < 20; row++)
		{
			if (length(row) >= p)
			{
				book(p, row);
				break;
			}
		}
		if (row == 20) random(p);
	}
}
