#include<bits/stdc++.h>
using namespace std;
int n,m;
int u[503][503],ra[503][503];
int dp[503][503];
int rec(int ii,int jj){
    if(ii>n || jj>m)return 0;
    if(dp[ii][jj]!=-1)return dp[ii][jj];
    //long long mx=-1;
    for(int i=jj;i<=m;i++){
        dp[ii][jj]=max(rec(ii+1,i)+u[ii][i]+ra[ii][i+1],dp[ii][jj]);
    }
    return dp[ii][jj];
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d%d",&n,&m);
        memset(dp,-1,sizeof(dp));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                scanf("%d",&u[i][j]);
            }
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                u[i][j]+=u[i][j-1];
            }
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                scanf("%d",&ra[i][j]);
            }
        }
        for(int i=0;i<=n;i++){
            ra[i][m+1]=0;
        }
        for(int i=1; i<=n; i++) {
            for(int j=m-1; j>0; j--) {
                ra[i][j]+=ra[i][j+1];
            }
        }
        cout<<"Case "<<z<<": "<<rec(1,0)<<"\n";
    }
    return 0;
}

