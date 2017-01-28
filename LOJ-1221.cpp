#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >g[101];
int cost[101];
int n,r,p;
bool BF(){
    bool ok=0;
    cost[0]=0;
    for(int i=0;i<=n;i++){
        bool f=1;
        for(int j=0;j<n;j++){
            for(int k=0;k<g[j].size();k++){
                if(cost[j]+g[j][k].second<cost[g[j][k].first]){
                    if(i==(n))return 1;
                    f=0;
                    cost[g[j][k].first]=cost[j]+g[j][k].second;
                }
            }
        }
        if(f)break;
    }
    return 0;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d%d%d",&n,&r,&p);
        int qq,ww,u,v;
        for(int i=0;i<=100;i++){
            g[i].clear();
            cost[i]=1<<30;
        }
        for(int i=0;i<r;i++){
            scanf("%d%d%d%d",&u,&v,&qq,&ww);
            g[u].push_back({v,p*ww-qq});
        }
        if(BF()){
            cout<<"Case "<<z<<": YES\n";
        }else cout<<"Case "<<z<<": NO\n";
    }
    return 0;
}

