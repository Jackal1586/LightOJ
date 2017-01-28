#include<stdio.h>
#include<iostream>
using namespace std;
#define mn(a,b) ((a<=b)?a:b)
int n;
int arr[22][3];
int dp[22][3];
long long rec(int idx,int col){
if(idx==n)return 0;
if(dp[idx][col]!=-1)return dp[idx][col];
if(col==0){
    return dp[idx][col]=(mn(rec(idx+1,col+1),rec(idx+1,col+2))+arr[idx][col]);
}if(col==1){
    return dp[idx][col]=(mn(rec(idx+1,col-1),rec(idx+1,col+1))+arr[idx][col]);
}return dp[idx][col]=(mn(rec(idx+1,col-1),rec(idx+1,col-2))+arr[idx][col]);
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&arr[i][j]);
            dp[i][j]=-1;
        }
    }cout<<"Case "<<z<<": "<<mn(rec(0,0),mn(rec(0,1),rec(0,2)))<<"\n";
}
return 0;
}

