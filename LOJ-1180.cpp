#include<bits/stdc++.h>
using namespace std;
int n,m,vis[101][101][101],x,y,a,b;
bool dp[101][101][101];
pair<int,int>p[101];
bool rec(int ii,int jj,int kk){
    if(ii==n)return (jj==0 && kk==0);
    if(vis[ii][jj][kk]==x)return dp[ii][jj][kk];
    vis[ii][jj][kk]=x;
    bool&ret=dp[ii][jj][kk];
    for(int i=0;i*p[ii].first<=y;i++){
        a=min(jj,i);
        b=(y-(a*p[ii].first))/p[ii].second;
        b=min(b,kk);
        ret=rec(ii+1,jj-a,kk-b);
        if(ret)return ret;
    }
    return ret;
}
bool ok(int mid){
    x++;
    y=mid;
    if(rec(0,m,m))return true;
    return false;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d%d",&p[i].first,&p[i].second);
        }
        sort(p,p+n);
        int low=1,high=50000,mid;
        while((high-low)>=4){
            mid=(low+high)>>1;
            if(ok(mid))high=mid;
            else low=mid;
        }
        for(;low<=high;low++){
            if(ok(low))break;
        }
        cout<<"Case "<<z<<": "<<low<<"\n";
    }
    return 0;
}

