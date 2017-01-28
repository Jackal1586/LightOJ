#include<bits/stdc++.h>
using namespace std;
int n,a[102],sum,x;
long long dp[50004];
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d",&n);
        sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        x=sum;
        sum>>=1;
        sum++;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=sum;j>=a[i];j--){
                dp[j]|=(dp[j-a[i]]<<1LL);
            }
        }
        for(int i=sum-1;i>=0;i--){
            if((dp[i]&(1LL<<(n/2))) || (dp[i]&(1LL<<((n+1)/2)))){
                cout<<"Case "<<z<<": "<<i<<" "<<x-i<<"\n";
                break;
            }
        }
    }
    return 0;
}

