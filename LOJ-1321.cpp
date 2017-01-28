#include<bits/stdc++.h>
using namespace std;
const double eps=1e-9;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        int n,m,s,k;
        scanf("%d%d%d%d",&n,&m,&s,&k);
        vector<pair<int,double> >g[n];
        double cost[n];
        memset(cost,0,sizeof(cost));
        for(int i=0;i<m;i++){
            int u,v;
            double w;
            scanf("%d%d%lf",&u,&v,&w);
            g[u].push_back(make_pair(v,w/100.0));
            g[v].push_back(make_pair(u,w/100.0));
        }
        queue<int>q;
        q.push(0);
        cost[0]=1.0;
        while(!q.empty()){
            int src=q.front();
            q.pop();
            for(int i=0;i<g[src].size();i++){
                if((cost[src]*g[src][i].second)>(cost[g[src][i].first]+eps)){
                    cost[g[src][i].first]=cost[src]*g[src][i].second;
                    q.push(g[src][i].first);
                }
            }
        }
        double p=cost[n-1];
        double ans=double(s);
        ans*=2.0;
        ans/=(p);
        //ans*=p;
        ans*=k;
        printf("Case %d: %.9lf\n",z,ans);
    }
    return 0;
}

