#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,dp[(1<<15)+5];
bool mark[15][(1<<15)],vis[1<<15];
vector<int>g[15];
void dfs(int src,int visMask){
    if(mark[src][visMask])return;
    mark[src][visMask]=1;
    vis[visMask]=1;
    for(int i=0;i<g[src].size();i++){
        dfs(g[src][i],visMask|(1<<g[src][i]));
    }
    return;
}
int rec(int mask){
    if(mask==0)return 0;
    if(dp[mask]!=-1)return dp[mask];
    int ret=12345678,x=mask;
    while(x>0){
        x=mask&x;
        if(vis[x]){
            ret=min(ret,rec(mask^x)+1);
        }
        x--;
    }
    return dp[mask]=ret;
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        for(int i=0; i<n; i++)g[i].clear();
        scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++) {
            scanf("%d%d",&u,&v);
            u--;
            v--;
            g[u].push_back(v);
        }
        memset(mark,0,sizeof(mark));
        memset(vis,0,sizeof(vis));
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            dfs(i,1<<i);
        }
        cout<<"Case "<<z<<": "<<rec((1<<n)-1)<<"\n";
    }
    return 0;
}

