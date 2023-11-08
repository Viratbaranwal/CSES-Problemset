#include <bits/stdc++.h>
using namespace std;
#define ll long long
int m = 1e9 + 7;
// int solve(int i, int j, vector<vector<int>> &dp, vector<int> &a)
// {
//     if (i == 0)
//     {
//         return (j % a[0] == 0);
//     }
//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }
//     int nt = solve(i - 1, j, dp, a);
//     int t = 0;
//     if (j >= a[i])
//     {
//         t = solve(i, j - a[i], dp, a);
//     }
//     return dp[i][j] = (t + nt) % m;
// }
int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int> >dp(n, vector<int>(sum + 1, 0));
    for (int i = 0; i <= sum; i++)
    {
        if (i % a[0] == 0)
        {
            dp[0][i] = 1;
        }
    }
    // cout<<solve(n-1,sum,dp,a);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int nt = dp[i - 1][j];
            int t = 0;
            if (j >= a[i])
            {
                t = dp[i][j - a[i]];
            }
            dp[i][j] = (t + nt) % m;
        }
    }
    cout<<dp[n-1][sum]<<endl;;

    return 0;
}