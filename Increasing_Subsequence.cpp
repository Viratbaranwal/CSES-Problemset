#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int m = 1e9 + 7;

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    vector<int> temp;
    temp.push_back(nums[0]);
    int len = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > temp.back())
        {
            temp.push_back(nums[i]);
            len++;
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }
    cout<<len;

    return 0;
}