#include<bits/stdc++.h>
using namespace std;
int n,W,p[101],c,w[101];
int dp[101][10001];
//bool vis[102][10004];
int rec(register int ii,register int ww){
    if(ww==0)return 0;
    if(ww<0)return -12345678;
    if(ii==n)return 0;
    if(dp[ii][ww]>(-23456789))return dp[ii][ww];
    //vis[ii][ww]=1;
    return dp[ii][ww]=max(rec(ii,ww-w[ii])+p[ii],rec(ii+1,ww));
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d%d",&n,&W);
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&p[i],&c,&w[i]);
            W-=(c*w[i]);
        }
        for(register int i=0;i<n;i++)for(register int j=0;j<=W;j++)dp[i][j]=-23456789;
        //memset(vis,0,sizeof(vis));
        int ans=rec(0,W);
        if(ans>=0)cout<<"Case "<<z<<": "<<ans<<"\n";
        else cout<<"Case "<<z<<": Impossible\n";
    }
    return 0;
}
