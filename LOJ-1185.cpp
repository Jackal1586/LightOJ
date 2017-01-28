#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>g[102];
bool vis[102][2];
void bfs(){
    //vis[1][1]=true;
    queue<pair<int,bool> >q;
    q.push(make_pair(1,1));
    while(!q.empty()){
        pair<int,bool>src=q.front();
        q.pop();
        for(int i=0;i<g[src.first].size();i++){
            if(!vis[g[src.first][i]][!src.second]){
                vis[g[src.first][i]][!src.second]=true;
                q.push(make_pair(g[src.first][i],!src.second));
            }
        }
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d%d",&n,&m);
        /*if(m==0){
            cout<<"Case "<<z<<": 0\n";
            continue;
        }*/
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        memset(vis,0,sizeof(vis));
        bfs();
        int ans=0;
        for(int i=1;i<=n;i++){
            if(vis[i][1])ans++;
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
        for(int i=1;i<=n;i++)g[i].clear();
    }
    return 0;
}

