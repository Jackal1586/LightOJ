#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int n,ch[1001];
long long dp[1001],ncr[1001][1001];
bool mark[1001];
vector<int>g[1001];
int dfs(int src){
	int ret=1;
	for(int i=0;i<g[src].size();i++){
		ret+=dfs(g[src][i]);
	}
	return ch[src]=ret;
}
long long rec(int ii){
	long long&ret=dp[ii],tt=ch[ii]-1;
	if(ret!=-1)return ret;
	ret=1;
	for(int i=0;i<g[ii].size();i++){
		int dest=g[ii][i];
		ret*=(ncr[tt][ch[dest]]);
		ret%=mod;
		ret*=rec(g[ii][i]);
		ret%=mod;
		tt-=ch[dest];
	}
	return ret;
}
int main(){
	int t;
	for(int i=1;i<=1000;i++){
		ncr[i][0]=1;
		ncr[i][1]=i;
		for(int j=2;j<=i;j++){
			ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
		}
	}
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		scanf("%d",&n);
		int u,v;
		memset(mark,0,sizeof(mark));
		memset(ch,0,sizeof(ch));
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			mark[v]=1;
		}
		long long ans;
		for(int i=1;i<=n;i++){
			if(!mark[i]){
				dfs(i);
				ans=rec(i);
				break;
			}
		}
		for(int i=1;i<=n;i++)g[i].clear();
		cout<<"Case "<<z<<": "<<ans<<"\n";
	}
	return 0;
}
