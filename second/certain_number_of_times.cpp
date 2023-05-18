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


int coin_create(vector<int>&cost,int n,int taka,vector<vector<int>>&dp,int certain_number_of_times)
{
    if(n<0)
    {
        if(taka==0) return 1;
        else return 0;
    }


    if(dp[n][taka]!=-1) return dp[n][taka];

    // bool ans=false,ans1=false;
    int ans=0;
    ans+=coin_create(cost,n-1,taka,dp,certain_number_of_times);
    for(int i=1; i<=certain_number_of_times; i++)
    {
        if(cost[n]*i>taka)
      break;

          ans+=coin_create(cost,n-1,taka-cost[n]*i,dp,certain_number_of_times);
    }
    return dp[n][taka]=ans;
}

int main()
{
    int number_of_coin,taka,certain_number_of_times;

    cin>>number_of_coin>>taka>>certain_number_of_times;               //certain number of times to take a coin
    vector<int>cost(number_of_coin);
    for(int i=0; i<number_of_coin; i++) cin>>cost[i];

    vector<vector<int>>dp(number_of_coin+2,vector<int>(taka+2,-1));
    int ans = coin_create(cost,number_of_coin-1,taka,dp,certain_number_of_times);
    //cout<<dp[number_of_coin-1][taka]<<endl;
    cout<<ans<<endl;
}




