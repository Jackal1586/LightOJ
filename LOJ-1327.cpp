#include<bits/stdc++.h>
using namespace std;
int n,arr[15][15];
long long dp[15][1<<15][2][2];
long long rec(int ii,int mask,bool tt,bool oo){
    if(ii==n){
        //if(tt)return 1;
        if(tt || oo)return 1;
        return 0;
    }
    long long&ret=dp[ii][mask][tt][oo];
    if(ret!=-1)return ret;
    ret=0;
    for(int i=0;i<n;i++){
        if(!(mask&(1<<i))){
            bool too=0,ttt=0;
            if(arr[ii][i]==2 || tt)ttt=1;
            else if(oo==1 && arr[ii][i]==1)too=1;
            ret+=rec(ii+1,mask|(1<<i),ttt,too);
        }
    }
    return ret;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<z<<": "<<rec(0,0,0,1)<<"\n";
    }
    return 0;
}

