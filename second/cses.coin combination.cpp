//it is can not solve by memorization limit.

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
const int mod=1e9+7;


int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> coins(n+3);
  for(int i=0;i<n;i++) cin>>coins[i];

    vector<int> dp(target+1,0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i-coins[j] >= 0)
            {
                (dp[i] += dp[i-coins[j]])%mod;
                dp[i]%=mod;
            }
        }
    }
    cout << dp[target] << endl;
}



