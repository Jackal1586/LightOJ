#include<bits/stdc++.h>
using namespace std;
inline int RI() {
    int  ret = 0, flag = 1,ip = getchar_unlocked();
    for(; ip < 48 || ip > 57; ip = getchar_unlocked()) {
        if(ip == 45) {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}
struct edge{
    int v,rii;
    bool isb;
    edge(){}
    edge(int _v,int _rii){v=_v,rii=_rii,isb=0;}
};
int n,m,low[10004],vis[10004],u,v,_time,ans,cnt;
vector<edge>g[10004];
void dfs(int src,int pr){
    int ch=0;
    vis[src]=low[src]=_time;
    _time++;
    for(int i=0;i<(int)g[src].size();i++){
        if(g[src][i].v==pr)continue;
        if(vis[g[src][i].v]!=-1)low[src]=min(low[src],vis[g[src][i].v]);
        else{
            ch++;
            dfs(g[src][i].v,src);
            low[src]=min(low[src],low[g[src][i].v]);
            if(low[g[src][i].v]>vis[src]){
                g[src][i].isb=1;
                g[g[src][i].v][g[src][i].rii].isb=1;
            }
        }
    }
    return;
}
void dfsB(int src,bool cc,bool&f){
    cnt++;
    for(int i=0;i<(int)g[src].size();i++){
        if(!g[src][i].isb){
            if(vis[g[src][i].v]==-1){
                vis[g[src][i].v]=cc;
                dfsB(g[src][i].v,!cc,f);
            }else if(vis[src]==vis[g[src][i].v])f=1;
        }
    }
    return;
}
int main(){
    int t;
    t=RI();//scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=0;i<n;i++){
            g[i].clear();
        }
        n=RI(),m=RI();//scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            u=RI(),v=RI();//scanf("%d%d",&u,&v);
            g[u].push_back(edge(v,g[v].size()));
            g[v].push_back(edge(u,g[u].size()-1));
        }
        memset(vis,-1,sizeof(vis));
        _time=0;
        ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                dfs(i,-1);
            }
        }
        memset(vis,-1,sizeof(vis));
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                vis[i]=1;
                bool f=0;
                cnt=0;
                dfsB(i,0,f);
                if(f)ans+=cnt;
            }
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

