#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,dp[51][51][51];
long long int rec(int ii,int jj,int kk){
    if(ii==0){
        if(jj==0)return 1;
        return 0;
    }
    if(jj==0)return 0;
    long long int&ret=dp[ii][jj][kk];
    if(ret!=-1)return ret;
    ret=0;
    for(int i=1;i<=kk;i++){
        if(ii<i)break;
        ret+=rec(ii-i,jj-1,kk);
    }
    return ret;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    for(int z=1; z<=t; z++) {
        scanf("%d%d%d",&n,&k,&m);
        cout<<"Case "<<z<<": "<<rec(n,k,m)<<"\n";
    }
    return 0;
}

