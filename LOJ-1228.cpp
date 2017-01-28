#include<bits/stdc++.h>
using namespace std;
int n,k,dp[13][12][1<<12],q,vis[13][13],lim,x;
int rec(int pr,int _left,int mask){
    if(mask==(1<<n)-1)return 1;
    if(dp[pr][_left][mask]!=-1)return dp[pr][_left][mask];
    int ret=0;
    for(int i=0;i<n;i++){
        if(mask&(1<<i))continue;
        if(_left<vis[pr][i+1])continue;
        ret+=rec(i+1,_left-vis[pr][i+1],mask|(1<<i));
    }
    return dp[pr][_left][mask]=ret;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d%d%d",&n,&k,&q);
        memset(dp,-1,sizeof(dp));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            scanf("%d",&lim);
            while(lim--){
                scanf("%d",&x);
                vis[x][i+1]=1;
            }
        }
        cout<<"Case "<<z<<":\n";
        while(q--){
            scanf("%d",&x);
            if(k==0){
                cout<<rec(0,n-1,0)<<"\n";
                continue;
            }
            x=min(x/k,n-1);
            cout<<rec(0,x,0)<<"\n";
        }
    }
    return 0;
}

