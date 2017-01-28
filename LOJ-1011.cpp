#include<bits/stdc++.h>
using namespace std;
int n,arr[17][17],dp[17][1<<16];
int rec(int idx,int mask) {
    if(idx==n)return 0;
    if(dp[idx][mask]!=-1)return dp[idx][mask];
    //int mx=-1;
    for(int i=0;i<n;i++){
        if(!(mask&(1<<i))){
            dp[idx][mask]=max(dp[idx][mask],rec(idx+1,mask|(1<<i))+arr[idx][i]);
        }
    }return dp[idx][mask];
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d",&n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                scanf("%d",&arr[i][j]);
            }
        }memset(dp,-1,sizeof(dp));
        cout<<"Case "<<z<<": "<<rec(0,0)<<"\n";
    }
    return 0;
}

