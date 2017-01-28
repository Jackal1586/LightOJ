#include<bits/stdc++.h>
using namespace std;
const int mod=100000007;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n,k;
        scanf("%d%d",&n,&k);
        int coin[n];
        for(int i=0;i<n;i++)scanf("%d",&coin[i]);
        int dp[k+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=coin[i];j<=k;j++){
                if(dp[j-coin[i]]){
                    dp[j]+=dp[j-coin[i]];
                    dp[j]%=mod;
                }
            }
        }
        cout<<"Case "<<z<<": "<<dp[k]%mod<<"\n";
    }
    return 0;
}

