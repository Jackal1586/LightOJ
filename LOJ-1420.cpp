#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
char a[103],b[103],c[103];
int dp[102][102][102][3],al,bl,cl,x,vis[102][102][102][3];
bool f1,f2;
int rec(int ii,int jj,int kk,int ff){
    if(kk>=cl && ii<=al && jj<=bl)return 1;
    if(ii>=al && jj>=bl)return 0;
    if(vis[ii][jj][kk][ff]==x)return dp[ii][jj][kk][ff];
    vis[ii][jj][kk][ff]=x;
    int ret=0;
    if(ii<al && ff!=2){
        if(a[ii]==c[kk])ret=((long long)(ret)+(long long)rec(ii+1,jj,kk+1,0))%mod;
        ret=((long long)ret+(long long)rec(ii+1,jj,kk,1))%mod;
    }
    if(jj<bl && ff!=1){
        if(b[jj]==c[kk])ret=((long long)ret+(long long)rec(ii,jj+1,kk+1,0))%mod;
        ret=((long long)ret+(long long)rec(ii,jj+1,kk,2))%mod;
    }
    return dp[ii][jj][kk][ff]=ret;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        //memset(dp,-1,sizeof(dp));
        scanf(" %s %s %s",a,b,c);
        al=strlen(a);
        bl=strlen(b);
        cl=strlen(c);
        f1=0,f2=0;
        x++;
        cout<<"Case "<<z<<": "<<rec(0,0,0,0)<<"\n";
    }
    return 0;
}

