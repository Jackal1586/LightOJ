#include<bits/stdc++.h>
using namespace std;
int n,x,y,z,dp[1001][2],vis[1001][2],cnt;
int rec(int ii,bool we){
    if(ii<=1){
        if(we)return -(x/2);
        return 0;
    }
    if(vis[ii][we]==cnt)return dp[ii][we];
    vis[ii][we]=cnt;
    int ret=123456789;
    for(int i=1;i<ii;i++){
        ret=min(ret,max(rec(i,0),rec(ii-i,1)));
    }
    return dp[ii][we]=ret+((we)?z:(x+y));
}
int main(){
    int t;
    scanf("%d",&t);
    for(int zz=1;zz<=t;zz++){
        scanf("%d%d%d%d",&n,&x,&y,&z);
        cnt++;
        cout<<"Case "<<zz<<": "<<rec(n,0)<<"\n";
    }
    return 0;
}
