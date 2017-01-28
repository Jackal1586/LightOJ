#include<bits/stdc++.h>
using namespace std;
char s1[1002],s2[1002];
int lcs[1002][1002],l1,l2,dp[1002][1002];
const int mod=1000007;
int rec(int ii,int jj){
	if(ii==0 || jj==0)return 1;
	int&ret=dp[ii][jj];
	if(ret!=-1)return ret;
	ret=0;
	if(s1[ii]==s2[jj])return ret=(((rec(ii-1,jj-1)%mod)+mod)%mod);
	if(lcs[ii][jj]==lcs[ii-1][jj-1])ret-=rec(ii-1,jj-1);
	if(lcs[ii][jj]==lcs[ii-1][jj])ret+=rec(ii-1,jj);
	if(lcs[ii][jj]==lcs[ii][jj-1])ret+=rec(ii,jj-1);
	return  ret=((ret%mod)+mod)%mod;
}
int main() {
    int t;
    scanf("%d",&t);
    getchar();
    for(int z=1; z<=t; z++) {
	gets(s1+1);
	gets(s2+1);
	l1=strlen(s1+1);
	l2=strlen(s2+1);
	memset(dp,-1,sizeof(dp));
	memset(lcs,0,sizeof(lcs));
	for(int i=1;i<=l1;i++){
		for(int j=1;j<=l2;j++){
			if(s1[i]==s2[j])lcs[i][j]=lcs[i-1][j-1]+1;
			else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
		}
	}
	cout<<"Case "<<z<<": "<<rec(l1,l2)<<"\n";
    }
    return 0;
}
