#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >g[102];
int dp[102][102],n,k,u,v,w;
int rec(int ss,int ii,int pp,int cc){
    if(ii==(int)g[ss].size())return 0;
    if(g[ss][ii].first==pp)return rec(ss,ii+1,pp,cc);
    if(dp[g[ss][ii].first][cc]!=-1)return dp[g[ss][ii].first][cc];
    int ret=1+rec(g[ss][ii].first,0,ss,k)+rec(ss,ii+1,pp,cc);
    if(cc>=g[ss][ii].second){
        int tc=cc-g[ss][ii].second;
        for(int i=0;i<=tc;i++){
            ret=min(ret,rec(g[ss][ii].first,0,ss,i)+rec(ss,ii+1,pp,tc-i));
        }
    }
    return dp[g[ss][ii].first][cc]=ret;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=0;i<=n;i++)g[i].clear();
        scanf("%d%d",&n,&k);
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<n;i++){
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back(make_pair(v,w));
            g[v].push_back(make_pair(u,w));
        }
        int ans=1<<29;
        for(int i=0;i<=k;i++){
            ans=min(ans,1+rec(1,0,-1,i));
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}
