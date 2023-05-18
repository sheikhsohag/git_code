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

     int Coinchange(vector<vector<int> >&dp,int sz,vector<int>&coins,int amount)
    {
        if(sz<0)
        {
            if(amount==0) return  1;
            else
            return 0;
        }


        if(dp[sz][amount]!=-1) return dp[sz][amount];

        int ans=0,ans1=0;
        if(amount<coins[sz])
            return dp[sz][amount]=Coinchange(dp,sz-1,coins,amount);
        else
        {
            ans=dp[sz][amount]=Coinchange(dp,sz-1,coins,amount);
            ans1= dp[sz][amount]=Coinchange(dp,sz,coins,amount-coins[sz]);
             return dp[sz][amount]=ans+ans1;
        }


    }
    int coinChange(int amount,vector<int>&coins)
    {
        int sz=coins.size()-1;
        vector<vector<int> >dp(sz+3,vector<int>(amount+3,-1) );
        return Coinchange(dp,sz,coins,amount);

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

