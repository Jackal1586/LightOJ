#include<bits/stdc++.h>
using namespace std;
vector<int>g[102];
int cap[102][102],n,c,s,t,u,v,w,pr[102];
bool vis[102];
int bfs(){
    memset(vis,0,sizeof(vis));
    memset(pr,-1,sizeof(pr));
    vis[s]=1;
    queue<pair<int,int> >q;
    q.push(make_pair(s,1<<28));
    while(!q.empty()){
        pair<int,int>src=q.front();
        q.pop();
        for(int i=0;i<g[src.first].size();i++){
            if(!vis[g[src.first][i]] && cap[src.first][g[src.first][i]]>0){
                vis[g[src.first][i]]=1;
                pr[g[src.first][i]]=src.first;
                if(g[src.first][i]==t){
                    return min(src.second,cap[src.first][g[src.first][i]]);
                }
                q.push(make_pair(g[src.first][i],min(src.second,cap[src.first][g[src.first][i]])));
            }
        }
    }
    return -1;
}
int main(){
    int tt;
    scanf("%d",&tt);
    for(int z=1;z<=tt;z++){
        for(int i=0;i<=n;i++){
            g[i].clear();
        }
        memset(cap,-1,sizeof(cap));
        scanf("%d%d%d%d",&n,&s,&t,&c);
        for(int i=0;i<c;i++){
            scanf("%d%d%d",&u,&v,&w);
            if(cap[u][v]==-1){
                g[u].push_back(v);
                g[v].push_back(u);
                cap[u][v]=w;
                cap[v][u]=w;
            }else {
                cap[u][v]+=w;
                cap[v][u]+=w;
            }
        }
        int ans=0;
        while(true){
            int m=bfs();
            if(m==-1)break;
            ans+=m;
            int x=t;
            while(pr[x]!=-1){
                cap[x][pr[x]]+=m;
                cap[pr[x]][x]-=m;
                x=pr[x];
            }
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

