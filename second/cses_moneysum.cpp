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

int main()
{
    int n;
    cin>>n;
    int ar[n+4],sum=0;
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
        sum+=ar[i];
    }
    vector<int>dp(sum+2,0);
    dp[0]=1;


    for(int i=0; i<n; i++)
    {
        for(int j=sum; j>=0&&j>=ar[i]; j--)
        {
            if(dp[j-ar[i]]==1)
                dp[j]=1;
        }
    }

    int ans=0;
    for(int i=1; i<=sum; i++) if(dp[i]==1) ans++;
    cout<<ans<<endl;
    for(int i=1; i<=sum; i++) if(dp[i]==1) cout<<i<<" ";
    cout<<endl;

}

