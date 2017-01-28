#include<bits/stdc++.h>
using namespace std;
char s[61],l;
long long dp[61][61];
long long int rec(char ii,char jj){
	if(ii>jj)return 0;
	long long int&ret=dp[ii][jj];
	if(ret!=-1)return ret;
	ret=0;
	if(s[ii]==s[jj])ret+=(1+rec(ii+1,jj-1));
	ret+=(rec(ii+1,jj)+rec(ii,jj-1)-rec(ii+1,jj-1));
	return ret;
}
int main() {
    int t;
    scanf("%d",&t);
    getchar();
    for(int z=1; z<=t; z++) {
	gets(s);
	l=strlen(s);
	memset(dp,-1,sizeof(dp));
	cout<<"Case "<<z<<": "<<rec(0,l-1)<<"\n";
    }
    return 0;
}
