#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long fact[1001];
long long ncr[1001][1001];
long long dp[1001][1001];
long long rec(int ii,int kk){
    if(ii<0 || kk<0)return 0;
    if(dp[ii][kk]!=-1)return dp[ii][kk];
    if(kk==0)return dp[ii][kk]=fact[ii];
    if(kk==1)return dp[ii][kk]=((ii-1)*rec(ii-1,kk-1))%mod;
    return dp[ii][kk]=((ii-1)*rec(ii-1,kk-1)+(kk-1)*rec(ii-2,kk-2))%mod;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    fact[0]=1;
    for(long long i=1;i<=1000;i++)fact[i]=(i*fact[i-1])%mod;
    for(int i=0; i<=1000; i++)ncr[i][0]=1;
    for(int i=1; i<=1000; i++){
        ncr[i][1] = i;
        for(int j=2; j<=i; j++)ncr[i][j] = (ncr[i-1][j-1]%mod+ncr[i-1][j]%mod)%mod;
    }
    memset(dp,-1,sizeof(dp));
    for(int z=1; z<=t; z++) {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        cout<<"Case "<<z<<": "<<(ncr[m][k]*rec(n-k,m-k))%mod<<"\n";
    }
    return 0;
}

