#include<bits/stdc++.h>
using namespace std;
const long long int mod=100000007;
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
	int n,k,s;
	scanf("%d%d%d",&n,&k,&s);
	register int dp[2][s+1],i,j;
	register bool pr=0,ps=1;
	memset(dp,0,sizeof(dp));
	dp[ps][0]=1;
	for(i=0;i<n;i++){
		for( j=0;j<=s;j++){
			if(j==0)dp[pr][j]=0;
			else if(j<=k)dp[pr][j]=(dp[ps][j-1]+dp[pr][j-1])%mod;
			else dp[pr][j]=(((dp[pr][j-1]+dp[ps][j-1]-dp[ps][j-k-1])%mod)+mod)%mod;
		}
		swap(pr,ps);
	}
	cout<<"Case "<<z<<": "<<dp[ps][s]<<"\n";
    }
    return 0;
}
