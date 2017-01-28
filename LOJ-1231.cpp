#include<bits/stdc++.h>
using namespace std;
int n,k;
long long int dp[1001][51];
int coin[51],amount[51];
int rec(int i,int am){
    if(i>=n){
        if(am==k)return 1;
        else return 0;
    }if(am==k)return 1;
    if(dp[am][i]!=-1)return dp[am][i];
    long long int ret=0;
    for(int j=1;j<=amount[i];j++){
        if((am+coin[i]*j)>k)break;
        ret+=(rec(i+1,am+j*coin[i])%100000007);
    }
    ret%=100000007;
    ret+=(rec(i+1,am)%100000007);
    ret%=100000007;
    dp[am][i]=ret;
    dp[am][i]%=100000007;
    return dp[am][i];
}
int main(){
int t;
cin>>t;
for(int z=1;z<=t;z++){
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>coin[i];
    for(int i=0;i<n;i++)cin>>amount[i];
    rec(0,0);
    printf("Case %d: %lld\n",z,(dp[0][0])%100000007);
}
return 0;
}
