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


int coin_create(vector<int>&cost,int n,int taka,vector<vector<int>>&dp)
{
    if(n<0)
    {
        if(taka==0) return 1;
        else return 0;
    }


    if(dp[n][taka]!=-1) return dp[n][taka];

    // bool ans=false,ans1=false;

    if(cost[n]>taka)
    {
       dp[n][taka]=coin_create(cost,n-1,taka,dp);

        //cout<<n<<" "<<taka<<" "<<dp[n][taka]<<endl;
        return dp[n][taka];
    }
    else
    {
        dp[n][taka]=coin_create(cost,n-1,taka,dp) + coin_create(cost,n-1,taka-cost[n],dp);

      //  cout<<n<<" "<<taka<<" "<<dp[n][taka]<<endl;
        return dp[n][taka];
    }
}

int main()
{
    int number_of_coin,taka;

    cin>>number_of_coin>>taka;
    vector<int>cost(number_of_coin);
    for(int i=0; i<number_of_coin; i++) cin>>cost[i];

    vector<vector<int>>dp(number_of_coin+2,vector<int>(taka+2,-1));
    int ans = coin_create(cost,number_of_coin-1,taka,dp);
    //cout<<dp[number_of_coin-1][taka]<<endl;
    cout<<ans<<endl;


}


