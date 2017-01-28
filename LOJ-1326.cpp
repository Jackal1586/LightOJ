#include<bits/stdc++.h>
using namespace std;
int ncr[1003][1003],dp[1003];
const int mod=10056;
int rec(int n){
    if(n==0)return 1;
    if(dp[n]!=-1)return dp[n];
    int ret=0;
    for(int i=1;i<=n;i++){
        ret+=(ncr[n][i]*(rec(n-i)%mod));
        ret%=mod;
    }
    return dp[n]=ret%mod;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    for(int i=0; i<=1000; i++)ncr[i][0]=1;
    for(int i=1; i<=1000; i++){
        ncr[i][1] = i;
        for(int j=2; j<=i; j++)ncr[i][j] = (ncr[i-1][j-1]%mod+ncr[i-1][j]%mod)%mod;
    }
    int t;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    //rec(1000);
    for(int z=1;z<=t;z++){
        int n;
        scanf("%d",&n);
        cout<<"Case "<<z<<": "<<rec(n)<<"\n";
    }
    return 0;
}

