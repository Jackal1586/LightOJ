#include<bits/stdc++.h>
using namespace std;
char s[102];
int l,dp[102][102];
int rec(int ii,int jj){
    if(ii>=jj)return 0;
    if(dp[ii][jj]!=-1)return dp[ii][jj];
    if(s[ii]==s[jj])return dp[ii][jj]=rec(ii+1,jj-1);
    return dp[ii][jj]=min(1+rec(ii+1,jj),1+rec(ii,jj-1));
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    getchar();
    for(int z=1;z<=t;z++){
        gets(s);
        l=strlen(s);
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<z<<": "<<rec(0,l-1)<<"\n";
    }
    return 0;
}
