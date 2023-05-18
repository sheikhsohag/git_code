#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;

#define For(i,n)             for(int i=0;i<n;i++)
#define ll                   int long long
#define pb                   push_back
#define pf                   push_front
#define pr                   pair<int,int>
#define ff                   first
#define sec                  second
#define ft_in_out      ios_base::sync_with_stdio(false); cin.tie(NULL);


class Solution
{
public:

    int coinchange(vector<vector<int>>&dp,int sz,vector<int>&coins,int amount)
    {
        if(sz<0)
        {
            if(amount==0) return  0;

            return 1e5;
        }


        if(dp[sz][amount]!=-1) return dp[sz][amount];

        int ans=1e5,ans1=1e5;
        if(amount<coins[sz])
            return dp[sz][amount]=coinchange(dp,sz-1,coins,amount);
        else
        {
            ans=dp[sz][amount]=coinchange(dp,sz-1,coins,amount);
            ans1= dp[sz][amount]=coinchange(dp,sz,coins,amount-coins[sz])+1;
        }
        return dp[sz][amount]=min(ans,ans1);

    }
    int coinChange(vector<int>& coins, int amount)
    {
        int sz=coins.size()-1;
        vector<vector<int>>dp(sz+3,vector<int>(amount+3,-1));
        int ans=coinchange(dp,sz,coins,amount);
        if(ans==1e5) return -1;
        else return ans;
    }
};


int main()
{
    int n,amount;
    cin>>n>>amount;
    vector<int>coins(n);
    for(int i=0; i<n; i++) cin>>coins[i];
    Solution st;

    cout<<st.coinChange(coins,amount);

}
