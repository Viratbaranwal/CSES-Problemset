#include<bits/stdc++.h>
using namespace std;
#define ll long long
int m=1e9+7;

int solve(int i,int j,vector<vector<int> >&dp, vector<vector<char> >&v)
{
    if(i==0 && j==0)
    {
        return 1;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int up=0,left=0;
    if(i>0 && v[i-1][j]=='.')
    {
        up=solve(i-1,j,dp,v);
    }
    if(j>0 && v[i][j-1]=='.')
    {
        left=solve(i,j-1,dp,v);
    }
    return dp[i][j]=(left+up)%m;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<char> >v(n,vector<char>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    if(v[0][0]=='*' || v[n-1][n-1]=='*')
    {
        cout<<0;
        return 0;
    }
    vector<vector<int> >dp(n,vector<int>(n,-1));
    cout<<solve(n-1,n-1,dp,v);
     
    return 0;
}