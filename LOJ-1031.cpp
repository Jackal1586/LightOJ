#include<bits/stdc++.h>
using namespace std;
int n;
long long arr[103],dp[103][103];
long long rec(int st,int en){
    if(st<0 || en>=n || st>en)return 0;
    if(st==en)return dp[st][en]=arr[st];
    if(dp[st][en]>LONG_LONG_MIN)return dp[st][en];
    long long sum=0;
    //dp[st][en]=LONG_LONG_MIN;
    for(int i=st;i<=en;i++){
        sum+=(arr[i]);
        dp[st][en]=max(dp[st][en],sum-rec(i+1,en));
    }sum=0;
    for(int i=en;i>=st;i--){
        sum+=arr[i];
        dp[st][en]=max(dp[st][en],sum-rec(st,i-1));
    }return dp[st][en];
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lld",&arr[i]);
            for(int j=0;j<n;j++){
                dp[i][j]=LONG_LONG_MIN;
            }
        }
        cout<<"Case "<<z<<": "<<rec(0,n-1)<<"\n";
    }
    return 0;
}

