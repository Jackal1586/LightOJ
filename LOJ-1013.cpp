#include<bits/stdc++.h>
using namespace std;
int lcs[31][31],l1,l2;
char s1[31],s2[31];
long long dp[31][31][61];
long long rec(int ii,int jj,int kk,int ll){
	if(kk==ll){
		if(l1==ii && jj==l2)return 1;
		return 0;
	}
	if(ii==l1)return dp[ii][jj][kk]=rec(ii,jj+1,kk+1,ll);
	if(jj==l2)return dp[ii][jj][kk]=rec(ii+1,jj,kk+1,ll);
	if(dp[ii][jj][kk]!=-1)return dp[ii][jj][kk];
	if(s1[ii]==s2[jj])return dp[ii][jj][kk]=rec(ii+1,jj+1,kk+1,ll);
	return dp[ii][jj][kk]=rec(ii+1,jj,kk+1,ll)+rec(ii,jj+1,kk+1,ll);
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf(" %s",s1);
        scanf(" %s",s2);
        l1=strlen(s1);
        l2=strlen(s2);
        memset(lcs,0,sizeof(lcs));
        for(int i=1; i<=l1; i++) {
            for(int j=1; j<=l2; j++) {
                if(s1[i-1]==s2[j-1])lcs[i][j]=lcs[i-1][j-1]+1;
                else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<z<<": "<<(l1+l2-lcs[l1][l2])<<" "<<rec(0,0,0,l1+l2-lcs[l1][l2])<<"\n";
    }
    return 0;
}

