#include<bits/stdc++.h>
using namespace std;
long long n,x,dp[26][155];
long long rec(int ii,int sum){
    if(ii==n){
        if(sum>=x)return 1;
        return 0;
    }
    if(dp[ii][sum]!=-1)return dp[ii][sum];
    dp[ii][sum]=0;
    for(int i=1;i<=6;i++){
        dp[ii][sum]+=rec(ii+1,sum+i);
    }
    return dp[ii][sum];
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%lld%lld",&n,&x);
        /*if(x<n || (x>(6*n))){
            cout<<"Case "<<z<<": 0\n";
            continue;
        }*/
        memset(dp,-1,sizeof(dp));
        long long ans=rec(0,0);
        long long den=1;
        for(int i=0;i<n;i++){
            den*=6;
        }
        long long x=__gcd(ans,den);
        ans/=x;
        den/=x;
        if(den==1)cout<<"Case "<<z<<": "<<ans<<"\n";
        else cout<<"Case "<<z<<": "<<ans<<"/"<<den<<"\n";
    }
    return 0;
}
