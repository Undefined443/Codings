#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int W[n], sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> W[i];
        sum += W[i];
    }
    int lim = sum >> 1;
    bool dp[lim + 1]{ true };
    for (int i = 0; i < n; i++)
    {
        for (int j = lim; j >= W[i]; j--)
        {
            if (dp[j - W[i]]) dp[j] = true;
        }
    }
    for (int i = lim; i >= 0; --i)
    {
        if (dp[i])
        {
            cout << sum - 2 * i;
            break;
        }
    }
}
