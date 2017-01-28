#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long dp[220][52],fact[52];
long long rec(int ii,int kk){
    if(kk>ii)return 0;
    if(kk==0)return ii==0;
    if(dp[ii][kk]!=-1)return dp[ii][kk];
    return dp[ii][kk]=((rec(ii-1,kk-1)+(rec(ii-1,kk)))*((long long)kk))%mod;
}
long long BM(long long b,long long p){
    long long ret=1;
    while(p>0){
        if(p&1)ret=(ret*b)%mod;
        p>>=1LL;
        b=(b*b)%mod;
    }
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    fact[0]=1;
    for(long long i=1;i<=50;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    for(int z=1;z<=t;z++){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        n++;
        m++;
        long long ans=0;
        for(int i=1;i<k;i++){
            long long temp=(fact[k]*BM((fact[i]*fact[k-i])%mod,mod-2))%mod;
            temp=(temp*rec((n*m+1)/2,i))%mod;
            ans+=(temp*BM(k-i,(n*m)/2))%mod;
            ans%=mod;
        }
        if(k==1){
            if(n*m==1)ans=1;
            else ans=0;
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

