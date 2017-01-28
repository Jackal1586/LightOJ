#include<bits/stdc++.h>
using namespace std;
int n,m;
unsigned long long int dp[52][52][2];
unsigned long long rec(char bb,char ss,bool sg) {
    if(bb==0 && ss==0)return 1;
    if(bb<0 || ss<0)return 0;
    unsigned long long&ret=dp[bb][ss][sg];
    if(ret!=-1)return ret;
    ret=0;
    if(sg) {
        for(char i=1; i<=bb; i++) {
            ret+=rec(bb-i,ss+i-1,0);
        }
        return ret;
    }
    for(char i=1; i<=ss; i++)ret+=rec(bb+i-1,ss-i,1);
    return ret;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d%d",&n,&m);
        unsigned long long ans;
        memset(dp,-1,sizeof(dp));
        if(n>2) {
            if(m>1)ans=rec(n-m,m-1,0);
            else ans=rec(n-3,0,1);
        }else ans=1;
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

