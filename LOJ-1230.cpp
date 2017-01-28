#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>g[1000];
pair<int,int>dp[1000][2];
bool vis[1000];
pair<int,int> rec(int node,int pr,bool st) {
    pair<int,int>&ret=dp[node][st];
    if(ret.first!=-1)return ret;
    ret=make_pair(0,0);
    //ret=0;
    vis[node]=true;
    for(int i=0; i<g[node].size(); i++) {
        if(g[node][i]!=pr) {
            if(st==0) {
                pair<int,int>a=rec(g[node][i],node,1);
                ret.first+=(a.first+1);
                ret.second+=a.second;
                //ret+=(1+rec(g[node][i],node,1));
            } else {
                pair<int,int>a=rec(g[node][i],node,0);
                pair<int,int>b=rec(g[node][i],node,1);
                if(a.first<(b.first+1) || (a.first==(b.first+1) && (a.second>(1+b.second)))) {
                    ret.first+=a.first;
                    ret.second+=a.second;
                } else {
                    ret.first+=(1+b.first);
                    ret.second+=(1+b.second);
                }
                //ret+=min(rec(g[node][i],node,0),1+rec(g[node][i],node,1));
            }
        }
    }
    return ret;
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d%d",&n,&m);
        int a,b;
//	for(int i=0;i<n;i++){
//		dp[i][0]=dp[i][1]=make_pair(-1,0);
//	}
        for(int i=0; i<m; i++) {
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        memset(dp,-1,sizeof(dp));
        memset(vis,0,sizeof(vis));
        pair<int,int>ans=make_pair(0,0);
        //int ans=min(rec(0,-1,0),1+rec(0,-1,1));
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                pair<int,int>ans1=rec(i,-1,0);
                pair<int,int>ans2=rec(i,-1,1);
                //cout<<ans1.first<<" <> "<<ans2.first<<endl;
                ans2.first++;
                //ans2.second++;
                if(ans1.first<ans2.first || (ans1.first==ans2.first && ans1.second>ans2.second)) {
                    ans.first+=ans1.first;
                    ans.second+=ans1.second;
                    //cout<<"Case "<<z<<": "<<ans1.first<<" "<<ans1.second<<" "<<m-ans1.second<<"\n";
                } else {
		ans.first+=ans2.first;
		ans.second+=ans2.second;
		//cout<<"Case "<<z<<": "<<ans2.first<<" "<<ans2.second<<" "<<m-ans2.second<<"\n";
                }
            }
        }
        cout<<"Case "<<z<<": "<<ans.first<<" "<<ans.second<<" "<<m-ans.second<<"\n";
        for(int i=0; i<n; i++)g[i].clear();
    }
    return 0;
}
