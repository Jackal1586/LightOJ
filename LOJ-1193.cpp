#include<bits/stdc++.h>
using namespace std;
const long long mod=100000007;
long long dp[2][15003],sum[15003];
int main(){
    int t,n,k,s;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d%d%d",&n,&k,&s);
        memset(dp,0,sizeof(dp));
        bool pr=0,ps=1;
        dp[ps][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<=s;j++){
                if(j==0)sum[j]=dp[ps][j];
                else sum[j]=(sum[j-1]+dp[ps][j])%mod;
            }
            dp[pr][0]=0;
            for(int j=1;j<=s;j++){
                dp[pr][j]=dp[pr][j-1]+sum[j-1]-(((j-k-1)>=0)?sum[j-k-1]:0)-((long long)k)*(((j-k-1)>=0)?dp[ps][j-k-1]:0);
                dp[pr][j]%=mod;
                dp[pr][j]+=mod;
                dp[pr][j]%=mod;
            }
            swap(pr,ps);
        }
        cout<<"Case "<<z<<": "<<dp[ps][s]<<"\n";
    }
    return 0;
}

