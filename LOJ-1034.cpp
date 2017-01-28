#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>g[10002];
bool vis[10002];
int top[10002],idx;
void dfs(int ii,bool s){
    vis[ii]=true;
    for(int i=0;i<g[ii].size();i++){
        if(!vis[g[ii][i]])dfs(g[ii][i],s);
    }
    if(s)top[idx++]=ii;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
        }
        memset(vis,0,sizeof(vis));
        idx=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,1);
            }
        }
        int ans=0;
        memset(vis,0,sizeof(vis));
        for(int i=idx-1;i>=0;i--){
            if(!vis[top[i]]){
                dfs(top[i],0);
                ans++;
            }
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
        for(int i=1;i<=n;i++)g[i].clear();
    }
    return 0;
}

