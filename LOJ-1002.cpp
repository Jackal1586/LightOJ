#include<bits/stdc++.h>
using namespace std;
int cost[510];
vector<pair<int,int> >g[510];
void bfs(int src){
    queue<int>q;
    q.push(src);
    cost[src]=0;
    while(!q.empty()){
        src=q.front();q.pop();
        for(int i=0;i<g[src].size();i++){
            pair<int,int>dest=g[src][i];
            if(max(cost[src],dest.second)<cost[dest.first]){
                cost[dest.first]=max(cost[src],dest.second);
                q.push(dest.first);
            }
        }
    }
}
int main(){
    int t;
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);for(int i=0;i<=501;i++)cost[i]=numeric_limits<int>::max();
    for(int z=1;z<=t;z++){
        int n,m;
        scanf("%d%d",&n,&m);
        int u,v,w;

        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back(make_pair(v,w));
            g[v].push_back(make_pair(u,w));
            //cost[u]=cost[v]=numeric_limits<int>::max();
        }int s;scanf("%d",&s);
        bfs(s);cout<<"Case "<<z<<":\n";
        for(int i=0;i<n;i++){
            if(cost[i]<1000000)cout<<cost[i]<<"\n";
            else cout<<"Impossible\n";
            g[i].clear();
            cost[i]=numeric_limits<int>::max();
        }
    }
    return 0;
}
