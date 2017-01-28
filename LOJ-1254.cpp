#include<bits/stdc++.h>
using namespace std;
int t,n,m,u,v,w,c,source,sink,cost[101],vis[101][101],qq;
struct node {
    int v,w,c;
    node() {}
    node(int _v,int _w,int _c) {
        v=_v,w=_w,c=_c;
    }
    bool operator<(const node&p)const {
        return w>p.w;
    }
};
vector<node>g[101];
inline int dijkstra() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<=c; j++) {
            vis[i][j]=(1<<28);
        }
    }
    priority_queue<node>q;
    q.push(node(source,0,0));
    vis[source][0]=0;
    while(!q.empty()) {
        node src=q.top();
        q.pop();
        if(src.v==sink)return src.w;
        for(int i=0; i<g[src.v].size(); i++) {
            node dest=g[src.v][i];
            if(src.c>=dest.w) {
                if(vis[dest.v][src.c-dest.w]>vis[src.v][src.c]) {
                    vis[dest.v][src.c-dest.w]=vis[src.v][src.c];
                    q.push(node(dest.v,vis[src.v][src.c],src.c-dest.w));
                }
            }
        }
        if(src.c<c && vis[src.v][src.c+1]>(vis[src.v][src.c]+cost[src.v])) {
            vis[src.v][src.c+1]=vis[src.v][src.c]+cost[src.v];
            q.push(node(src.v,vis[src.v][src.c+1],src.c+1));
        }
    }
    return -1;
}
int main() {
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        for(int i=0; i<n; i++)g[i].clear();
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)scanf("%d",&cost[i]);
        for(int i=0; i<m; i++) {
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back(node(v,w,0));
            g[v].push_back(node(u,w,0));
        }
        scanf("%d",&qq);
        cout<<"Case "<<z<<":\n";
        while(qq--) {
            scanf("%d%d%d",&c,&source,&sink);
            int ans=dijkstra();
            if(ans==-1)cout<<"impossible\n";
            else cout<<ans<<"\n";
        }
    }
    return 0;
}

