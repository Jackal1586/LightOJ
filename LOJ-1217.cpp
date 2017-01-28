#include<bits/stdc++.h>
using namespace std;
int  n;
long long arr[1005];
long long dp[1005][2];
long long rec(int idx,bool st){
if(idx==n)return 0;
if(dp[idx][st]!=-1)return dp[idx][st];
if(idx==(n-1)){
    if(st)return 0;
    else return arr[n-1];
}
return dp[idx][st]=max(rec(idx+2,st)+arr[idx],rec(idx+1,st));
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
ios_base::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
for(int z=1;z<=t;z++){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[i][0]=dp[i][1]=-1;
    }cout<<"Case "<<z<<": "<<(max(rec(2,1)+arr[0],rec(1,0)))<<"\n";
}
return 0;
}

