#include<bits/stdc++.h>
using namespace std;
int n,arr[101],k,w,dp[101][101];
int rec(int ii,int left){
    if(ii==n)return 0;
    if(left<=0)return 0;
    if(dp[ii][left]!=-1)return dp[ii][left];
    int ret=-1;
    ret=max(ret,rec(ii+1,left));
    int cnt=1;
    for(int i=ii+1;i<n && arr[i]<=(arr[ii]+w);i++){
        cnt++;
    }
    ret=max(ret,cnt+rec(ii+cnt,left-1));
    return dp[ii][left]=ret;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d%d%d",&n,&w,&k);
        int a;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)scanf("%d%d",&a,&arr[i]);
        sort(arr,arr+n);
        cout<<"Case "<<z<<": "<<rec(0,k)<<"\n";
    }
    return 0;
}

