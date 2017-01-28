#include<bits/stdc++.h>
using namespace std;
int n,cap[110][110],vis[110],cost[110][110],source=105,sink=106,pr[110],a,x;
vector<int>g[110];
bool BF(){
    memset(pr,-1,sizeof(pr));
    for(int i=0;i<110;i++)vis[i]=-(1<<26);
    pr[source]=-2;
    vis[source]=0;
    for(int k=1;k<(2*n+3);k++){
        bool f=1;
        for(int i=0;i<2*n+3;i++){
            for(int j=0;j<(int)g[i].size();j++){
                if(vis[g[i][j]]<vis[i]+cost[i][g[i][j]] && cap[i][g[i][j]]>0){
                    f=0;
                    vis[g[i][j]]=vis[i]+cost[i][g[i][j]];
                    pr[g[i][j]]=i;
                }
            }
        }
        if(f)break;
    }
    return vis[sink]>(-(1<<26));
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=0;i<110;i++)g[i].clear();
        scanf("%d",&n);
        source=2*n+1,sink=source+1;
        for(int i=0;i<n;i++){
            g[source].push_back(i);
            g[i].push_back(source);
            cap[source][i]=1;
            cap[i][source]=0;
            g[i+n+1].push_back(sink);
            g[sink].push_back(i+n+1);
            cap[i+n+1][sink]=1;
            cap[sink][i+n+1]=0;
            cost[source][i]=cost[i][source]=cost[i+n+1][sink]=cost[sink][i+n+1]=0;
            for(int j=0;j<n;j++){
                scanf("%d",&a);
                cost[i][j+n+1]=a;
                cost[j+n+1][i]=-a;
                g[i].push_back(j+n+1);
                g[j+n+1].push_back(i);
                cap[i][j+n+1]=1;
                cap[j+n+1][i]=0;
            }
        }
        int ans=0;
        while(BF()){
            int y=sink;
            while(pr[y]!=-2){
                cap[pr[y]][y]--;
                cap[y][pr[y]]++;
                ans+=cost[pr[y]][y];
                y=pr[y];
            }
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

