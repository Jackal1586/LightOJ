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
int n,m,u,v,pr[1005],t;
bool vis[1005];
vector<int>g[1005];
bool dfs(int src){
    if(vis[src])return 0;
    vis[src]=1;
    for(int i=0;i<g[src].size();i++){
        if(pr[g[src][i]]==-1 || dfs(pr[g[src][i]])){
            pr[g[src][i]]=src;
            return 1;
        }
    }
    return 0;
}
int BPM(int n){
    int ret=n;
    memset(pr,-1,sizeof(pr));
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i))ret--;
    }
    return ret;
}
int main(){
    t=RI();
    //scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=0;i<=n;i++)g[i].clear();
        n=RI(),m=RI();
        //scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            u=RI(),v=RI();
            //scanf("%d%d",&u,&v);
            g[u].push_back(v);
        }
        cout<<"Case "<<z<<": "<<BPM(n)<<"\n";
    }
    return 0;
}

