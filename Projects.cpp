#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll m=1e9+7;

ll check(ll key,ll low,vector<vector<ll> >&v)
{
    ll high = v.size() - 1;

        ll ans = v.size();
        while(low <= high){
            ll mid = (low+high)/2;
            if(v[mid][0] > key){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
}

ll solve(ll i,vector<vector<ll> >&v,vector<ll>&dp)
{
    if(i==v.size())
    {
        return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    ll nt=solve(i+1,v,dp);
    ll next=check(v[i][1],i,v);
    ll t=v[i][2]+solve(next,v,dp);
    return dp[i]=max(t,nt);
}
int main()
{
    ll n;
    cin>>n;
    vector<vector<ll> >v(n,vector<ll>(3));
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<3;j++)
        {
            cin>>v[i][j];
        }
    }
    sort(v.begin(),v.end());
    vector<ll>dp(n,-1);
    cout<<solve(0,v,dp);
     
    return 0;
}