#include<bits/stdc++.h>
using namespace std;
int n,h,f[27],d[27],ti[27],dp[27][195];
int rec(int ii,int tl) {
    if(tl<=0)return 0;
    if(ii>=n)return 0;
    if(dp[ii][tl]!=-1)return dp[ii][tl];
    int ret=0,x=0;
    for(int i=0; i<=tl; i++) {
        ret=max(ret,x+rec(ii+1,tl-i-ti[ii]));
        if(f[ii]>=i*d[ii])x+=(f[ii]-i*d[ii]);
    }
    return dp[ii][tl]=ret;
}

/*void path( int nas , int n ){
    for( int i = n-1 ; i >=0 ; i-- ){
        if( dp[])
    }
}
*/
void path(int ii,int lf,int tl) {
    if(ii>=n)return ;
    if(lf==0){
        if(ii>0)cout<<", ";
        cout<<"0";
        path(ii+1,0,0);
        return;
    }
    for(int i=tl; i>=0; i--) {
        int x=0;
        for(int j=0; j<i; j++) {
            if(f[ii]>=j*d[ii]) {
                x+=(f[ii]-j*d[ii]);
            }
        }
        int y=rec(ii+1,tl-i-ti[ii]);
        //cout<<" x y == "<<x<<" "<<y<<" |-| ";
        if((x+y)==lf) {
            if(ii>0)cout<<", ";
            cout<<i*5;
            path(ii+1,lf-x,tl-i-ti[ii]);
            return;
        }
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d%d",&n,&h);
        h*=12;
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<n; i++)scanf("%d",&f[i]);
        for(int i=0; i<n; i++)scanf("%d",&d[i]);
        for(int i=0; i<(n-1); i++)scanf("%d",&ti[i]);
        ti[n-1]=0;
        int ans=rec(0,h);
        cout<<"Case "<<z<<":\n";
        path(0,ans,h);
        cout<<"\nNumber of fish expected: "<<ans<<"\n";
        //path(ans,n) ;
        /*for(int i=0; i<n; i++) {
            for(int j=0; j<=h; j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        //path(0,ans);
    }
    return 0;
}

