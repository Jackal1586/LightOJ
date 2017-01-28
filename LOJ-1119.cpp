#include<bits/stdc++.h>
using namespace std;
int n;
long long arr[15][15],dp[1<<14];
long long rec(int mask){
    if(mask==((1<<n)-1))return 0;
    if(dp[mask]!=-1)return dp[mask];
    dp[mask]=LONG_LONG_MAX;
    for(int i=0;i<n;i++){
        long long sum=arr[i][i];
        if(!(mask&(1<<i))){
            for(int j=0;j<n;j++){
                if(mask&(1<<j)&&(i!=j))sum+=arr[i][j];
            }
            dp[mask]=min(dp[mask],sum+rec(mask|(1<<i)));
        }
    }return dp[mask];
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int  z=1; z<=t; z++) {
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%lld",&arr[i][j]);
            }
        }memset(dp,-1,sizeof(dp));
        cout<<"Case "<<z<<": "<<rec(0)<<"\n";
    }
    return 0;
}

