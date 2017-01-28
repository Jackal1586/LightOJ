#include<bits/stdc++.h>
using namespace std;
struct edge {
    int v,w,c,ri;
    edge() {}
    edge(int _v,int _w,int _c,int _ri) {
        v=_v,w=_w,c=_c,ri=_ri;
    }
};
vector<edge>g[52];
int pr[52],source,sink,vis[52],n,m,p,_index[52];
void add(int u,int v,int w,int c) {
    g[u].push_back(edge(v,w,c,g[v].size()));
    g[v].push_back(edge(u,-w,0,g[u].size()-1));
    return;
}
bool BF() {
    memset(pr,-1,sizeof(pr));
    for(int i=0; i<=sink; i++)vis[i]=(1<<28);
    pr[source]=-2;
    vis[source]=0;
    for(int k=0; k<=sink; k++) {
        bool f=1;
        for(int i=0; i<=sink; i++) {
            if(vis[i]>=(1<<28))continue;
            for(int j=0; j<(int)g[i].size(); j++) {
                if(vis[g[i][j].v]>vis[i]+g[i][j].w && g[i][j].c>0) {
                    f=0;
                    vis[g[i][j].v]=vis[i]+g[i][j].w;
                    pr[g[i][j].v]=i;
                    _index[g[i][j].v]=j;
                }
            }
        }
        if(f)break;
    }
    return (vis[sink]<(1<<28));
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        for(int i=1; i<=sink; i++)g[i].clear();
        scanf("%d%d%d",&n,&m,&p);
        int u,v,w,c;
        source=0,sink=n+1;
        add(source,1,0,p);
        add(n,sink,0,p);
        for(int i=0; i<m; i++) {
            scanf("%d%d%d%d",&u,&v,&c,&w);
            add(u,v,w,c);
            add(v,u,w,c);
        }
        int flow=0,ans=0;
        while(BF()) {
            int minFlow=INT_MAX;
            int y=sink;
            while(pr[y]>0) {
                minFlow=min(minFlow,g[pr[y]][_index[y]].c);
                y=pr[y];
            }
            y=sink;
            flow+=minFlow;
            while(pr[y]>0) {
                int revii=g[pr[y]][_index[y]].ri;
                g[pr[y]][_index[y]].c-=minFlow;
                g[y][revii].c+=minFlow;
                ans+=minFlow*g[pr[y]][_index[y]].w;
                y=pr[y];
            }
            if(flow==p)break;
        }
        if(flow==p)cout<<"Case "<<z<<": "<<ans<<"\n";
        else cout<<"Case "<<z<<": impossible\n";
    }
    return 0;
}
/**
1 7 8 6 6 4 7 1
**/

