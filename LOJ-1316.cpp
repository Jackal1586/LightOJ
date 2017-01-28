#include<bits/stdc++.h>
using namespace std;
int n,m,s,vis[20][20],cost[505];
deque<int>shop;
struct node {
    int v,w;
    node() {}
    node(int _v,int _w) {
        v=_v,w=_w;
    }
    bool operator<(const node&p) const{
        return w>p.w;
    }
};
vector<node>g[505];
void dijkstra(int source){
    for(int i=0;i<n;i++)cost[i]=1<<29;
    cost[source]=0;
    priority_queue<node>q;
    q.push(node(source,0));
    while(!q.empty()){
        node src=q.top();
        q.pop();
        for(int i=0;i<g[src.v].size();i++){
            if(cost[g[src.v][i].v]>cost[src.v]+g[src.v][i].w){
                cost[g[src.v][i].v]=cost[src.v]+g[src.v][i].w;
                q.push(node(g[src.v][i].v,cost[g[src.v][i].v]));
            }
        }
    }
    return;
}
pair<int,int>dp[18][(1<<17)+5];
pair<int,int>rec(int ii,int mask){
    if(ii==s-1 || mask==((1<<s)-1))return make_pair(0,0);
    if(dp[ii][mask].first!=-1)return dp[ii][mask];
    pair<int,int>ret=make_pair(-(1<<29),1<<29);
    for(int i=0;i<s;i++){
        if(!(mask&(1<<i)) && vis[ii][i]<(1<<29)){
            pair<int,int>a=rec(i,mask|(1<<i));
            a.first++;
            a.second+=vis[ii][i];
            if(a.first>ret.first){
                ret=a;
            }else if(a.first==ret.first && a.second<ret.second){
                ret=a;
            }
        }
    }
    return dp[ii][mask]=ret;
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        for(int i=0; i<n; i++)g[i].clear();
        shop.clear();
        int u,v,w;
        bool sourceShop=0,sinkShop=0;
        scanf("%d%d%d",&n,&m,&s);
        for(int i=0; i<s; i++) {
            scanf("%d",&u);
            shop.push_back(u);
            if(u==0)sourceShop=1;
            else if(u==n-1)sinkShop=1;
        }
        for(int i=0; i<m; i++) {
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back(node(v,w));
        }
        sort(shop.begin(),shop.end());
        if(!sourceShop)shop.push_front(0);
        if(!sinkShop)shop.push_back(n-1);
        s=shop.size();
        for(int i=0; i<s; i++) {
            dijkstra(shop[i]);
            for(int j=0;j<s;j++){
                vis[i][j]=cost[shop[j]];
            }
        }
        if(vis[0][s-1]>=1<<29){
            cout<<"Case "<<z<<": Impossible\n";
            continue;
        }
        if((s-(!sourceShop)-(!sinkShop))==0){
            cout<<"Case "<<z<<": 0 "<<vis[0][s-1]<<"\n";
            continue;
        }
        memset(dp,-1,sizeof(dp));
        pair<int,int>ans=rec(0,1);
        if(sourceShop)ans.first++;
        if(!sinkShop)ans.first--;
        cout<<"Case "<<z<<": "<<ans.first<<" "<<ans.second<<"\n";
    }
    return 0;
}

