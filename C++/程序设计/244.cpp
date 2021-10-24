#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int cmp(const void* p1, const void* p2);

int main()
{
	char str[10][20] = { 0 };
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
	}
	qsort(str, N, 20, cmp);
	for (int i = 0; i < N; i++)
	{
		cout << str[i] << endl << endl;
	}
}

int cmp(const void* p1, const void* p2)
{
	return strcmp((char*)p1, (char*)p2);
}
