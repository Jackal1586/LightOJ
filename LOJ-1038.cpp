#include<bits/stdc++.h>
using namespace std;
double dp[100002];
double rec(int ii) {
    if(ii==1)return 0;
    if(dp[ii]>(-1.0))return dp[ii];
    int lim=sqrt(ii)+1,cnt=2;
    double ret=2.0;
    for(int i=2;i<lim;i++){
        if(ii%i==0){
            if(i!=(ii/i)){
                ret+=(1+rec(ii/i));
                ret+=(1+rec(i));
                cnt+=2;
            }else{
                ret+=(1+rec(ii/i));
                cnt++;
            }
        }
    }
    ret/=(cnt-1);
    return dp[ii]=ret;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    for(int z=1; z<=t; z++) {
        int n;
        scanf("%d",&n);
        printf("Case %d: %.9lf\n",z,rec(n));
        //cout<<"Case "<<z<<": "<<rec(n)<<"\n";
    }
    return 0;
}

