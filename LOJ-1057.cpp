#include<bits/stdc++.h>
using namespace std;
pair<int,int>src,arr[16];
int n,m,lim,dp[1<<(15)+1][17];
int rec(int mask,int pr){
    if(mask==((1<<lim)-1))return max(abs(arr[pr].first-src.first),abs(arr[pr].second-src.second));
    if(dp[mask][pr+1]!=-1)return dp[mask][pr+1];
    int ret=(1<<28);
    for(int i=0;i<lim;i++){
        if(mask==0){
            ret=min(ret,max(abs(arr[i].first-src.first),abs(arr[i].second-src.second))+rec(mask|(1<<i),i));
        }else{
            if(!(mask&(1<<i))){
                ret=min(ret,max(abs(arr[i].first-arr[pr].first),abs(arr[i].second-arr[pr].second))+rec(mask|(1<<i),i));
            }
        }
    }
    return dp[mask][pr+1]=ret;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d%d",&n,&m);
        char c;
        lim=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            getchar();
            for(int j=0;j<m;j++){
                scanf("%c",&c);
                if(c=='x'){
                    src.first=i;
                    src.second=j;
                }else if(c=='g'){
                    arr[lim].first=i;
                    arr[lim++].second=j;
                }
            }
        }
        if(lim==0)cout<<"Case "<<z<<": 0\n";
        else cout<<"Case "<<z<<": "<<rec(0,-1)<<"\n";
    }
    return 0;
}

