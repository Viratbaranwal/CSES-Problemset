#include<bits/stdc++.h>
using namespace std;
#define int long long
const int m=1e9+7;
int power(int x, int y, int mod)
{
    int res = 1;
    x = x % mod;
    if (x == 0)
        return 0;
    while (y)
    {
        if (y % 2)
        {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}
int inversemod(int n, int mod)
{
    return power(n, mod - 2,mod);
}
int solve(int i,vector<int>& a,int sum,vector<vector<int> >&dp)
{
    if(sum==0)
    {
        return 1;
    }
    if(i==0)
    {
        return a[0]==sum;
    }
    if(dp[i][sum]!=-1)
    {
        return dp[i][sum];
    }
    int t=0;
    int nt=solve(i-1,a,sum,dp);
    if(sum>=a[i])
    {
        t=solve(i-1,a,sum-a[i],dp);
    }
    return dp[i][sum]=(t%m+nt%m)%m;


}
signed main()
{
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=1;i<=n;i++)
    {
        arr[i-1]=i;
    }
    int sum=(n*(n+1))/2;
    if(sum%2==1)
    {
        cout<<0;
    }
    else
    {
        sum/=2;
        vector<vector<int> >dp(n,vector<int>(sum+1,-1));
        int ans=solve(n-1,arr,sum,dp);
        int p=inversemod(2,m);
        // cout<<p<<endl;

        ans=(ans*p)%m;
        cout<<ans;
    }
     
}