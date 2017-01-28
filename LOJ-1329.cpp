#include<bits/stdc++.h>
using namespace std;
unsigned long long dp[5][14][14][14][14];
bool vis[5][14][14][14][14];
unsigned long long rec(int ff,int ii,int jj,int kk,int ll){
    if(ii==0 && jj==0 && kk==0 && ll==0)return 1;
    if(vis[ff][ii][jj][kk][ll])return dp[ff][ii][jj][kk][ll];
    vis[ff][ii][jj][kk][ll]=1;
    unsigned long long ret=0;
    if(ii>0){
        if(ff==2)ret+=((unsigned long long)(ii-1))*rec(1,ii-1,jj,kk,ll);
        else ret+=ii*rec(1,ii-1,jj,kk,ll);
    }
    if(jj>0){
        if(ff==3)ret+=((unsigned long long)2*(jj-1))*rec(2,ii+1,jj-1,kk,ll);
        else ret+=((unsigned long long)2*(jj))*rec(2,ii+1,jj-1,kk,ll);
    }
    if(kk>0){
        if(ff==4)ret+=((unsigned long long)3*(kk-1))*rec(3,ii,jj+1,kk-1,ll);
        else ret+=((unsigned long long)3*(kk))*rec(3,ii,jj+1,kk-1,ll);
    }
    if(ll>0){
        ret+=((unsigned long long)4*(ll))*rec(4,ii,jj,kk+1,ll-1);
    }
    return dp[ff][ii][jj][kk][ll]=ret;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n;
        scanf("%d",&n);
        char s[5];
        int a[5],b[14];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++){
            scanf(" %s",s);
            int x;
            if(s[0]<='9')x=s[0]-48;
            else if(s[0]=='A')x=1;
            else if(s[0]=='T')x=10;
            else if(s[0]=='J')x=11;
            else if(s[0]=='Q')x=12;
            else if(s[0]=='K')x=13;
            b[x]++;
        }
        for(int i=1;i<=13;i++){
            a[b[i]]++;
        }
        cout<<"Case "<<z<<": "<<rec(0,a[1],a[2],a[3],a[4])<<"\n";
    }
    return 0;
}

