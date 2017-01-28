#include<bits/stdc++.h>
using namespace std;
int n,m,p,s,d;
vector<pair<int,long long> >g[10002],gr[10002];
vector<pair<int,pair<int,long long> > >vv;
long long cost[10002],rcost[10002];
void bfs1(){
    queue<int>q;
    q.push(s);
    cost[s]=0;
    while(!q.empty()){
        int src=q.front();
        q.pop();
        for(int i=0;i<g[src].size();i++){
            pair<int,long long>dest=g[src][i];
            if(cost[dest.first]>(cost[src]+dest.second)){
                cost[dest.first]=cost[src]+dest.second;
                q.push(dest.first);
            }
        }
    }
    return;
}
void bfs2(){
    queue<int>q;
    q.push(d);
    rcost[d]=0;
    while(!q.empty()){
        int src=q.front();
        q.pop();
        for(int i=0;i<gr[src].size();i++){
            pair<int,long long>dest=gr[src][i];
            if(rcost[dest.first]>(rcost[src]+dest.second)){
                rcost[dest.first]=rcost[src]+dest.second;
                q.push(dest.first);
            }
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
    for(int z=1;z<=t;z++){
        scanf("%d%d%d%d%d",&n,&m,&s,&d,&p);
        int u,v;
        long long w;
        for(int i=1;i<=n;i++){
            g[i].clear();
            gr[i].clear();
            cost[i]=(1LL<<50);
            rcost[i]=(1LL<<50);
        }
        vv.clear();
        for(int i=0;i<m;i++){
            scanf("%d%d%lld",&u,&v,&w);
            g[u].push_back(make_pair(v,w));
            gr[v].push_back(make_pair(u,w));
            vv.push_back(make_pair(u,make_pair(v,w)));
        }
        bfs1();
        bfs2();
        long long mx=-1;
        for(int i=0;i<m;i++){
            u=vv[i].first;
            v=vv[i].second.first;
            w=vv[i].second.second;
            if((cost[u]+rcost[v]+w)<=p){
                mx=max(mx,w);
            }
        }
        cout<<"Case "<<z<<": "<<mx<<"\n";
    }
    return 0;
}

