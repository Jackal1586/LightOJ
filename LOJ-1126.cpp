#include<bits/stdc++.h>
using namespace std;
int n,a[51],dp[2][250003],lim,x,y,sum;
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d",&n);
        lim=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            lim+=a[i];
        }
        lim/=2;
        memset(dp,-1,sizeof(dp));
        bool pr=0,ps=1;
        dp[ps][0]=1;
        sum=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=sum;j++){
                if(dp[ps][j]==-1)continue;
                dp[pr][j]=max(dp[pr][j],dp[ps][j]);
                x=abs(j-a[i]),y=j+a[i];
                if(x<=lim)dp[pr][x]=max(dp[pr][x],dp[ps][j]+a[i]);
                if(y<=lim)dp[pr][y]=max(dp[pr][y],dp[ps][j]+a[i]);
            }
            sum+=a[i];
            sum=min(sum,lim);
            swap(pr,ps);
        }
        cout<<"Case "<<z<<": ";
        if(dp[ps][0]<=1)cout<<"impossible\n";
        else cout<<dp[ps][0]/2<<"\n";
    }
    return 0;
}

