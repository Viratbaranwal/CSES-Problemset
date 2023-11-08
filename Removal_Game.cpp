#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(vector<ll>&v,ll i,ll j,vector<vector<ll> >&dp )
{
    if(i>j)
    {
        return 0;
    }
    if(i==j)
    {
        return v[i];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    ll l = v[i] + min(solve(v, i+2, j,dp), solve(v, i+1, j-1, dp ));
    ll r = v[j] + min(solve(v, i, j-2, dp), solve(v, i+1, j-1, dp));
    return dp[i][j]=max(l,r);
}
 
int main()
{
    ll n,ans=0;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
        ans+=v[i];
    }
    vector<vector<ll> >dp(n,vector<ll>(n,-1));
    cout<<solve(v,0,n-1,dp);
     
    return 0;
}