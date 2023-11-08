#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int m = 1e9 + 7;

int solve(int n, int m, vector<vector<int> > &dp)
{
    if (m <= 0 || n <= 0)
    {
        return 0;
    }
    if (m == n)
    {
        return 1;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    int ans = 1e8;
    for (int i = 1; i <= min(m, n); i++)
    {
        ans = min(ans, 1 + min(solve(i, m - i, dp) + solve(n - i, m, dp), solve(n - i, i, dp) + solve(n, m - i, dp)));
    }
    if (ans == 1e8)
    {
        return dp[n][m] = 0;
    }
    return dp[n][m] = ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, -1));
    cout << solve(n, m, dp)-1;
    return 0;
}