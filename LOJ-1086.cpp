#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,degree[16];
int vis[16][16],dp[1<<15],w,sum;
vector<int>vv;
int rec(int mask){
    if(__builtin_popcount(mask)==(int)vv.size())return 0;
    if(dp[mask]!=-1)return dp[mask];
    int ret=1<<28;
    for(int i=0;i<(int)vv.size();i++){
        if(!(mask&(1<<i))){
            for(int j=i+1;j<(int)vv.size();j++){
                if(!(mask&(1<<j))){
                    ret=min(ret,rec(mask|(1<<i)|(1<<j))+vis[vv[i]][vv[j]]);
                }
            }
        }
    }
    return dp[mask]=ret;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d%d",&n,&m);
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                vis[i][j]=(i!=j)?1<<28:0;
            }
        }
        vv.clear();
        sum=0;
        memset(degree,0,sizeof(degree));
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            sum+=w;
            vis[u][v]=min(vis[u][v],w);
            vis[v][u]=vis[u][v];
            degree[u]++;
            degree[v]++;
        }
        for(int i=1;i<=n;i++){
            if(degree[i]&1){
                vv.push_back(i);
            }
        }
        if(vv.empty()){
            cout<<"Case "<<z<<": "<<sum<<"\n";
            continue;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    vis[i][j]=min(vis[i][j],vis[i][k]+vis[k][j]);
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<z<<": "<<sum+rec(0)<<"\n";
    }
    return 0;
}

