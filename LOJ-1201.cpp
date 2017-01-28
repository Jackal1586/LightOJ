#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>g[1001];
bool vis[1001];
int dp[1001][2];
int rec(int idx,int st,int pr) {
    if(dp[idx][st]!=-1)return dp[idx][st];
    dp[idx][st]=0;
    vis[idx]=true;
    for(int i=0; i<g[idx].size(); i++) {
        if(pr==g[idx][i])continue;
        if(st) {
            dp[idx][st]+=rec(g[idx][i],0,idx);
        } else {
            dp[idx][st]+=max(rec(g[idx][i],0,idx),1+rec(g[idx][i],1,idx));
        }
    }
    return dp[idx][st];
}
int main() {
    int t;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            dp[i][0]=dp[i][1]=-1;
            vis[i]=false;
        }
        for(int i=0; i<m; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int ans=0;
        for(int i=1; i<=n; i++) {
            if(!vis[i]) {
                ans+=max(rec(i,0,-1),1+rec(i,1,-1));
            }
        }
        for(int i=0; i<=n; i++)g[i].clear();
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

