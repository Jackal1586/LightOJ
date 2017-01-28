#include<bits/stdc++.h>
using namespace std;
int t,n,dp[2][2][61][61][61],x;
char s1[61],s2[61];
unsigned char vis[2][2][61][61][61];
int rec(bool fa,bool fd,int ii,int jj,int kk){
    if(ii>jj)return 0;
    if(kk>=n)return 0;
    if(vis[fa][fd][ii][jj][kk]==x)return dp[fa][fd][ii][jj][kk];
    int ret=12345678;
    vis[fa][fd][ii][jj][kk]=x;
    if(fa)ret=min(ret,1+rec(0,!fd,ii,jj,kk));
    if(fd){
        if(s1[ii]==s2[kk+jj-ii])ret=min(ret,rec(1,1,ii+1,jj,kk));
        if(s1[jj]==s2[kk])ret=min(ret,rec(1,1,ii,jj-1,kk+1));
    }else{
        if(s1[ii]==s2[kk])ret=min(ret,rec(1,0,ii+1,jj,kk+1));
        if(s1[jj]==s2[kk+jj-ii])ret=min(ret,rec(1,0,ii,jj-1,kk));
    }
    return dp[fa][fd][ii][jj][kk]=ret;
}
int main(){
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf(" %s %s",s1,s2);
        n=strlen(s1);
        x=z;
        //memset(dp,-1,sizeof(dp));
        int ans=rec(1,0,0,n-1,0);
        if(ans>=12345678)cout<<"Case "<<z<<": impossible\n";
        else cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

