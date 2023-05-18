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
int const mod=100000007;
int const N=57,M=1007;
int dp[N][M];
 int cost[N],limit[N];

int main()
{
    int t;
    cin>>t;

    for(int tc=1; tc<=t; tc++)
    {
        int n,k;
        cin>>n>>k;


        for(int i=1; i<=n; i++) cin>>cost[i];
        for(int i=1; i<=n; i++) cin>>limit[i];

        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=k; j++) dp[i][j]=0;
        }


        dp[0][0]=1;

        for(int i=1; i<=n; i++)
        {
            for(int tar=0; tar<=k; tar++)
            {

                dp[i][tar]=dp[i-1][tar];

                for(int j=1; j<=limit[i]; j++)
                {
                    if(tar<j*cost[i])
                        break;

                    int ret=dp[i-1][tar-j*cost[i]];
                    dp[i][tar]=(dp[i][tar]+ret)%mod;
                }
            }
        }
        printf("Case %d: %d\n",tc,dp[n][k]);

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
    }
}
