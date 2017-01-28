#include<bits/stdc++.h>
using namespace std;
int n,m,s[11];
int dp[11][11];
int rec(char ii,char dd){
	if(ii==n)return 1;
	int&ret=dp[ii][dd];
	if(ret!=-1)return ret;
	ret=0;
	for(char i=0;i<m;i++){
		if(abs(s[i]-dd)<=2)ret+=rec(ii+1,s[i]);
	}
	return ret;
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
	scanf("%d%d",&m,&n);
	for(char i=0;i<m;i++)scanf("%d",&s[i]);
	int ans=0;
	memset(dp,-1,sizeof(dp));
	for(char i=0;i<m;i++){
		ans+=rec(1,s[i]);
	}
	cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}
/*
3
3 2
1 3 6
3 2
1 2 3
3 3
1 4 6
*/
