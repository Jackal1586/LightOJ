#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,pr[10003],low[10003],disc[10003],_time;
bool vis[10003],ap[10003];
vector<int>g[10003];
void dfs(int src){
    vis[src]=1;
    int ch=0;
    _time++;
    disc[src]=low[src]=_time;
    for(int i=0;i<g[src].size();i++){
        if(!vis[g[src][i]]){
            ch++;
            pr[g[src][i]]=src;
            dfs(g[src][i]);
            low[src]=min(low[src],low[g[src][i]]);
            if(pr[src]==-1 && ch>1)ap[src]=1;
            if(pr[src]!=-1 && low[g[src][i]]>=disc[src])ap[src]=1;
        }else if(g[src][i]!=pr[u]){
            low[src]=min(low[src],disc[g[src][i]]);
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        _time=0;
        for(int i=1;i<=n;i++)g[i].clear();
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        memset(pr,-1,sizeof(pr));
        memset(vis,0,sizeof(vis));
        memset(ap,0,sizeof(ap));
        for(int i=1;i<=n;i++){
            if(!vis[i])dfs(i);
        }
        int ans=0;
        for(int i=1;i<=n;i++)ans+=ap[i];
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

