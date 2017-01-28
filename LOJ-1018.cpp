#include<bits/stdc++.h>
using namespace std;
struct point{
    int x,y;
    int cross(point a,point b){
        return ((a.x-x)*(b.y-y)-(b.x-x)*(a.y-y));
    }
}arr[17];
int n,save[17][17],dp[(1<<16)+2];
int rec(int mask){
    if(mask==((1<<n)-1))return 0;
    if(dp[mask]!=-1)return dp[mask];
    int ret=(1<<28);
    for(int i=0;i<n;i++){
        if(!(mask&(1<<i))){
            for(int j=i+1;j<n;j++){
                ret=min(ret,1+rec(mask|(save[i][j])));
            }
            return dp[mask]=ret;
        }
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&arr[i].x,&arr[i].y);
        }
        if(n<3){
            cout<<"Case "<<z<<": 1\n";
            continue;
        }
        memset(save,0,sizeof(save));
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                save[i][j]|=(1<<i);
                save[i][j]|=(1<<j);
                for(int k=j+1;k<n;k++){
                    if(arr[i].cross(arr[j],arr[k])==0){
                        save[i][j]|=(1<<k);
                    }
                }
                //save[j][i]=save[i][j];
            }
        }
        cout<<"Case "<<z<<": "<<rec(0)<<"\n";
    }
    return 0;
}

