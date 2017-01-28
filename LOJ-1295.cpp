#include<bits/stdc++.h>
using namespace std;
struct data{
    int v,k,c,l;
    data():v(0),k(0),c(0),l(0){}
    data(int _v,int _k,int _c,int _l):v(_v),k(_k),c(_c),l(_l){}
    bool operator<(const data&p)const{return v<p.v;}
}a[1003];
int n,dp[1003][11];
int rec(int ii,int cc){
    if(ii<0)return 0;
    if(dp[ii][cc]!=-1)return dp[ii][cc];
    return dp[ii][cc]=min(rec(ii-1,cc)+a[ii].l*cc,rec(ii-1,min(cc,a[ii].c))+a[ii].k+a[ii].l*a[ii].c);
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d",&a[i].v,&a[i].k,&a[i].c,&a[i].l);
        }
        sort(a,a+n);
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<z<<": "<<rec(n-2,a[n-1].c)+a[n-1].k+a[n-1].c*a[n-1].l<<"\n";
    }
    return 0;
}
