#include<bits/stdc++.h>
using namespace std;
#define cube(x) ((x)*(x)*(x))
int n,m;
int arr[202];
vector<pair<int,int> >g[202];
int cost[202];
bool vis[202];
void BF() {
    cost[1]=0;
    for(int k=0; k<n; k++) {
        bool f=1;
        for(int i=1; i<=n; i++) {
            for(int j=0; j<g[i].size(); j++) {
                pair<int,int>dest=g[i][j];
                if(dest.first==n && (f=0))cost[n]=0;
                if(cost[dest.first]>(cost[i]+dest.second)) {
                    cost[dest.first]=cost[i]+dest.second;
                    f=0;
                }
            }
        }
        if(f)return;
    }
    return;
}
void dfs(int src) {
    vis[src]=1;
    for(int i=0; i<g[src].size(); i++) {
        if(!vis[g[src][i].first]) {
            dfs(g[src][i].first);
        }
    }
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d",&n);
        for(int i=1; i<=n; i++) {
            scanf("%d",&arr[i]);
            cost[i]=1<<30;
        }
        scanf("%d",&m);
        for(int i=0; i<m; i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(make_pair(v,cube(arr[v]-arr[u])));
        }
        BF();
        memset(vis,0,sizeof(vis));
        dfs(1);
        int q;
        scanf("%d",&q);
        cout<<"Case "<<z<<":\n";
        while(q--) {
            int a;
            scanf("%d",&a);
            if(!vis[a] || cost[a]<3 || cost[a]>=(1<<30)) {
                cout<<"?\n";
            } else cout<<cost[a]<<"\n";
        }
        for(int i=0; i<=n; i++)g[i].clear();
    }
    return 0;
}

