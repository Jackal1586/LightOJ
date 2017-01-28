#include<bits/stdc++.h>
using namespace std;
int n;
int s1,s2;
vector<pair<int,int> >g[105];
bool vis[105];
inline int bfs(int src){
    queue<int>q;
    q.push(src);
    vis[1]=vis[src]=true;
    int sum=0;
    while(!q.empty()){
        src=q.front();q.pop();
        for(int i=0;i<g[src].size();i++){
            pair<int,int>dest=g[src][i];
            if(!vis[dest.first]){
                vis[dest.first]=true;
                sum+=dest.second;
                q.push(dest.first);
            }
        }
    }return sum;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back(make_pair(v,0));
            g[v].push_back(make_pair(u,w));
            vis[i]=vis[i+1]=false;
        }
        s1=g[1][0].first;
        s2=g[1][1].first;
        int ans1=g[1][0].second;
        ans1+=bfs(s1);
        if(g[s2][0].first==1){
            ans1+=g[s2][0].second;
        }else ans1+=g[s2][1].second;
        memset(vis,0,sizeof(vis));
        int ans2=g[1][1].second;
        ans2+=bfs(s2);
        if(g[s1][0].first==1){
            ans2+=g[s1][0].second;
        }else ans2+=g[s1][1].second;
        cout<<"Case "<<z<<": "<<min(ans1,ans2)<<"\n";
        for(int i=1;i<=n;i++)g[i].clear();
    }
    return 0;
}

