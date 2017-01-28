#include<bits/stdc++.h>
using namespace std;
int arr[101],dp[101][101];
int rec(int ii,int jj){
    if(ii>=jj)return 0;
    if(dp[ii][jj]!=-1)return dp[ii][jj];
    int ret=rec(ii+1,jj)+1;
    for(int i=ii+1;i<=jj;i++){
        if(arr[i]==arr[ii]){
            ret=min(ret,1+rec(ii+1,i-1)+rec(i,jj));
        }
    }
    return dp[ii][jj]=ret;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n,ii=1;
        scanf("%d%d",&n,&arr[0]);
        for(int i=1;i<n;i++){
            scanf("%d",&arr[ii]);
            if(arr[ii]!=arr[ii-1])ii++;
        }
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<z<<": "<<rec(0,ii-1)+1<<"\n";
    }
    return 0;
}

