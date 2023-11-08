#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
    int n;
    cin>>n;
    vector<int>dp(n+1,1e9);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        int k=i;
        while(k)
        {
            int w=k%10;
            dp[i]=min(dp[i],dp[i-w]+1);
            k/=10;
        }
    }
    cout<<dp[n]<<endl;
     
    return 0;
}