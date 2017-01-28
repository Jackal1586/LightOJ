#include<bits/stdc++.h>
using namespace std;
struct edge {
    int ww,ii;
    edge() {}
    edge(int _ii,int _ww) {
        ii=_ii;
        ww=_ww;
    }
};
int n,r,u,v,w;
vector<edge>g[5002];
pair<int,int>cost[5002];
int bfs() {
    cost[1].first=0;
    queue<edge>q;
    q.push(edge(1, 0));
    while(!q.empty()) {
        edge src= q.front();
        q.pop();
        for(int i=0; i<g[src.ii].size(); i++) {
            edge dest=g[src.ii][i];
            if(cost[dest.ii].second>(src.ww+dest.ww)) {
                if(cost[dest.ii].first>(src.ww+dest.ww)) {
                    cost[dest.ii].second = cost[dest.ii].first;
                    cost[dest.ii].first = src.ww+dest.ww;
                    q.push(edge(dest.ii,dest.ww+src.ww));
                } else if(cost[dest.ii].first!=(src.ww+dest.ww)) {
                    cost[dest.ii].second = src.ww+dest.ww;
                    q.push(edge(dest.ii,dest.ww+src.ww));
                }
            }
        }
    }
    return cost[n].second;
}
int main() {
    int t;
    scanf("%d", &t);
    for(int z=1;z<=t;z++){
        scanf("%d%d", &n, &r);
        for(int i=0; i<=n; i++) {
            cost[i].first=1<<28;
            cost[i].second=1<<28;
            g[i].clear();
        }
        for(int i=0; i<r; i++) {
            scanf("%d%d%d", &u, &v, &w);
            g[u].push_back(edge(v, w));
            g[v].push_back(edge(u, w));
        }
        cout<<"Case "<<z<<": "<<bfs()<<"\n";
    }
    return 0;
}
