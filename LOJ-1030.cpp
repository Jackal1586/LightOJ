#include<bits/stdc++.h>
using namespace std;
int n;
double arr[103],dp[103];
double rec(int ii){
    if(ii==n)return 0;
    if(fabs(dp[ii]+1.0)>(1e-9))return dp[ii];
    double ret=arr[ii];
    int lim=min(6,n-ii-1);
    for(int i=1;i<=lim;i++){
        ret+=((1.0/(double(lim)))*rec(ii+i));
    }
    return dp[ii]=ret;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lf",&arr[i]);
            dp[i]=-1.0;
        }
        printf("Case %d: %.10lf\n",z,rec(0));
        //cout<<"Case "<<z<<": "<<rec(0)<<"\n";
    }
    return 0;
}

