#include<bits/stdc++.h>
using namespace std;
char s[15][15];
int n,arr[15],dp[1<<15];
int rec(int mask){
    if(mask==((1<<n)-1))return 0;
    if(dp[mask]!=-1)return dp[mask];
    dp[mask]=(1<<30);
    for(int i=0;i<n;i++){
        if(!(mask&(1<<i))){
            int p=1;
            for(int j=0;j<n;j++){
                if(mask&(1<<j)){
                    p=max(p,s[j][i]-48);
                }
            }
            dp[mask]=min(dp[mask],((arr[i]+p-1)/p)+rec(mask|(1<<i)));
        }
    }return dp[mask];
}
int main(){
        #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        #endif // ONLINE_JUDGE
        int t;
        scanf("%d",&t);
        for(int z=1;z<=t;z++){
                scanf("%d",&n);
                for(int i=0;i<n;i++){
                    scanf("%d",&arr[i]);
                }getchar();
                for(int i=0;i<n;i++){
                    gets(s[i]);
                }memset(dp,-1,sizeof(dp));
                cout<<"Case "<<z<<": "<<rec(0)<<"\n";
        }
        return 0;
}

