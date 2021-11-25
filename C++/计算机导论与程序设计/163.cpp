#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[20][20];
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cin >> a[x][y];
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i][i] + a[i][n - i - 1];
    }
    sum = n % 2 == 0 ? sum : sum - a[n / 2][n / 2];
    cout << sum;
}
