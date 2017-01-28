#include<bits/stdc++.h>
using namespace std;
int n,d[15][15],calc[1<<15],dp[1<<15];
int vis[1<<15],x;
int rec(int mask){
    if(mask==0)return 0;
    if(vis[mask]==x)return dp[mask];
    vis[mask]=x;
    int ret=12345678,xx=mask;
    while(xx>0){
        ret=min(ret,rec(mask^xx)+calc[xx]);
        xx--;
        xx=xx&mask;
    }
    return dp[mask]=ret;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&d[i][j]);
            }
        }
        for(int i=1;i<(1<<n);i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    for(int k=j+1;k<n;k++){
                        if(i&(1<<k)){
                            sum+=d[j][k]+d[k][j];
                        }
                    }
                }
            }
            calc[i]=sum;
        }
        x++;
        cout<<"Case "<<z<<": "<<rec((1<<n)-1)<<"\n";
    }
    return 0;
}

