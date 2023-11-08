#include <bits/stdc++.h>
using namespace std;
#define ll long long
// int solve(int i, int sum, vector<vector<int>> &dp, int a[])
// {
//     if (i == 0)
//     {
//         if (sum % a[i] == 0)
//         {
//             return sum / a[i];
//         }
//         else
//         {
//             return 1e9;
//         }
//     }
//     if (dp[i][sum] != -1)
//     {
//         return dp[i][sum];
//     }
//     int t = INT_MAX;
//     int nt = solve(i - 1, sum, dp, a);
//     if (sum >= a[i])
//     {
//         t = 1 + solve(i, sum - (a[i]), dp, a);
//     }
//     return dp[i][sum] = min(t, nt);
// }

int main()
{
    int n, sum;
    cin >> n >> sum;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    vector<vector<int> > dp(n, vector<int>(sum + 1, 0));
    for (int i = 0; i <= sum; i++)
    {
        if (i % a[0] == 0)
            dp[0][i] = i / a[0];
        else
            dp[0][i] = 1e9;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int t = INT_MAX;
            int nt = dp[i - 1][j];
            if (j >= a[i])
            {
                t = 1 + dp[i][j - a[i]];
            }
            dp[i][j] = min(t, nt);
        }
    }
    cout << ((dp[n - 1][sum]==1e9) ? -1 : dp[n - 1][sum]);

    return 0;
}