#include <iostream>
#include <cstdlib>
using namespace std;

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int n;
	cin >> n;
	int W[n + 1] = { 0 };
	double ave = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> W[i];
		ave += W[i];
	}
	qsort(W, n + 1, sizeof(W[0]), cmp);
	ave /= 2.0;
	int bag = ave;
	int B[n + 1][500] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		for (int m = 1; m <= bag; m++)
		{
			if (m < W[i]) B[i][m] = B[i - 1][m];
			else B[i][m] = max(B[i - 1][m], B[i - 1][m - W[i]] + W[i]);
		}
	}
	cout << 2 * (ave - B[n][bag]);
}
