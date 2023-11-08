#include <bits/stdc++.h>
using namespace std;
#define ll long long

// int solve(int i, int j, vector<vector<int>> &dp, vector<int> &a, vector<int> &b)
// {

//     if (i == 0)
//     {
//         if (a[0] <= j)
//         {
//             return b[0];
//         }
//         return 0;
//     }
//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }
//     int nt = solve(i - 1, j, dp, a, b);
//     int t = 0;
//     if (j >= a[i])
//     {
//         t = b[i] + solve(i - 1, j - a[i], dp, a, b);
//     }
//     return dp[i][j] = max(t, nt);
// }
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<vector<int> > dp(n, vector<int>(m + 1, 0));
    for (int i = 0; i <= m; i++)
    {
        if (i >= a[0])
        {
            dp[0][i] = b[0];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            int nt = dp[i - 1][j];
            int t = 0;
            if (j >= a[i])
            {
                t = b[i] + dp[i - 1][j - a[i]];
            }
            dp[i][j] = max(t, nt);
        }
    }
    // cout << solve(n - 1, m, dp, a, b);
    cout<<dp[n-1][m];

    return 0;
}