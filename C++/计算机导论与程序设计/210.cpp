#include <iostream>
using namespace std;

void change(int* num, int n);

int main()
{
	int num[20] = { 0 };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	change(num, n);
	for (int i = 0; i < n; i++)
	{
		cout << num[i] << ' ';
	}
}

void change(int* num, int n)
{
	int max = num[0], min = num[0];
	int max_index = 0, min_index = 0;
	for (int i = 1; i < n; i++)
	{
		if (num[i] > max)
		{
			max = num[i];
			max_index = i;
		}
		else if (num[i] < min)
		{
			min = num[i];
			min_index = i;
		}
	}
	num[max_index] = min;
	num[min_index] = max;
}
