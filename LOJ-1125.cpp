#include<bits/stdc++.h>
using namespace std;
int n,q,d,m;
int arr[202];
long long dp[201][11][21];
long long rec(int ii,int ll,int ss){
	if(ii<0){
		if(ll==0 && ss%d==0)return 1;
		return 0;
	}
	if(ll==0 && ss%d==0)return 1;
	if(ll<0)return 0;
	if(dp[ii][ll][ss]!=-1)return dp[ii][ll][ss];
	dp[ii][ll][ss]=(rec(ii-1,ll-1,(((ss+arr[ii])%d)+d)%d)+rec(ii-1,ll,ss));
	return dp[ii][ll][ss];
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)scanf("%d",&arr[i]);
	cout<<"Case "<<z<<":\n";
	while(q--){
		scanf("%d%d",&d,&m);
		memset(dp,-1,sizeof(dp));
		cout<<rec(n-1,m,0)<<"\n";
	}
    }
    return 0;
}
