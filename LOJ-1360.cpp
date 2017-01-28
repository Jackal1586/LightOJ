#include<bits/stdc++.h>
using namespace std;
int n,lim,st;
vector<pair<int,int> >g[200005];
int dp[200005];
int rec(int ii) {
    if(ii>=lim)return 0;
    if(dp[ii]!=-1)return dp[ii];
    if(g[ii].empty())return dp[ii]=rec(ii+1);
    //int mx=-1;
    for(int i=0; i<g[ii].size(); i++) {
        dp[ii]=max(dp[ii],max(rec(ii+g[ii][i].first)+g[ii][i].second,rec(ii+1)));
    }
    return dp[ii];
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d",&n);
        lim=-1;
        st=1<<28;
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<n; i++) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            g[a].push_back(make_pair(b,c));
            lim=max(lim,b+a);
            st=min(st,a);
        }
        cout<<"Case "<<z<<": "<<rec(st)<<"\n";
        for(int i=st;i<=lim;i++)g[i].clear();
    }
    return 0;
}

