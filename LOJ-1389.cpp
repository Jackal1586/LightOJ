#include<bits/stdc++.h>
using namespace std;
int n,dp[102];
char s[102];
int rec(int ii){
    if(ii>=n)return 0;
    if(dp[ii]!=-1)return dp[ii];
    if(s[ii]=='#')return dp[ii]=rec(ii+1);
    return dp[ii]=(min(rec(ii+3),rec(ii+2))+1);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d",&n);
        memset(dp,-1,sizeof(dp));
        getchar();
        gets(s);
        cout<<"Case "<<z<<": "<<rec(0)<<"\n";
    }
    return 0;
}

