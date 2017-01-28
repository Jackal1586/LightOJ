#include<bits/stdc++.h>
using namespace std;
int n,u,v,w;
vector<pair<int,int> >g[1003];
int dfs(int s,int pr){
    int ret=0;
    for(int i=0;i<(int)g[s].size();i++){
        if(g[s][i].first==pr)continue;
        if(g[s][i].second&1){
            if(g[s][i].second==1)ret^=(dfs(g[s][i].first,s)+1);
            else ret^=(dfs(g[s][i].first,s)^1);
        }else ret^=(dfs(g[s][i].first,s));
    }
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=0;i<n;i++){
            g[i].clear();
        }
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back(make_pair(v,w));
            g[v].push_back(make_pair(u,w));
        }
        cout<<"Case "<<z<<": ";
        if(dfs(0,-1))cout<<"Emily\n";
        else cout<<"Jolly\n";
    }
    return 0;
}
