#include<bits/stdc++.h>
using namespace std;
int n,u,v,w;
const double eps=1e-9;
double dp[15][1<<15];
vector<pair<int,int> >g[15];
double rec(int ii,int mask) {
    if(fabs(dp[ii][mask]+1)>eps)return dp[ii][mask];
    double cnt=0.0;
    double&ret=dp[ii][mask];
    ret=5.0;
    for(int i=0; i<g[ii].size(); i++) {
        if(!(mask&(1<<g[ii][i].first))) {
            double x=rec(g[ii][i].first,mask|(1<<g[ii][i].first));
            if((x)>(-2+eps)){
                ret+=((x+g[ii][i].second));
                cnt++;
            }
        }
    }
    if(cnt>eps)ret/=(cnt);
    else if(cnt<eps){
        if(mask==((1<<n)-1))return ret=0.0;
        return ret=-2.0;
    }
    return ret;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        int m;
        scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++) {
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back(make_pair(v,w));
            g[v].push_back(make_pair(u,w));
        }
        memset(dp,-1,sizeof(dp));
        double ans=rec(0,1);
        if(ans<eps)ans=0.0;
        printf("Case %d: %.9lf\n",z,ans+eps);
        //cout<<setprecision(10)<<"Case "<<z<<": "<<rec(0,1)<<"\n";
        for(int i=0; i<n; i++)g[i].clear();
    }
    return 0;
}

