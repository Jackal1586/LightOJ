#include<bits/stdc++.h>
using namespace std;
int r,b;
double dp[501][501];
double rec(int rr,int bb) {
    if(rr==0 && bb>=0)return 1;
    if(bb<=0 && rr>0)return 0;
    if(dp[rr][bb] > -1 )return dp[rr][bb] ;
    return dp[rr][bb]=(double(rr)/double(rr+bb))*rec(rr-1,bb-1)+(double(bb)/double(rr+bb))*rec(rr,bb-2);
}
int main() {
    int t;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    for(int z=1; z<=t; z++) {
        scanf("%d%d",&r,&b);
        cout<<"Case "<<z<<": "<<rec(r,b)<<"\n";
    }
    return 0;
}
