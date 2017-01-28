#include<bits/stdc++.h>
using namespace std;
const int inf=1<<30;
int pr[230],cap[230][230],cost[230][230],jmp[230][230],source=221,sink=222;
inline int ns(int a){return (a+101);}
vector<int>g[230];
int bfs(int lim){
    memset(pr,-1,sizeof(pr));
    pr[source]=-2;
    queue<pair<int,int> >q;
    q.push(make_pair(source,inf));
    while(!q.empty()){
        pair<int,int>src=q.front();
        q.pop();
        for(int i=0;i<g[src.first].size();i++){
            if(pr[g[src.first][i]]==-1 && cap[src.first][g[src.first][i]]>0 && jmp[src.first][g[src.first][i]]<=lim){
                pr[g[src.first][i]]=src.first;
                if(g[src.first][i]==sink){
                    return min(src.second,cap[src.first][g[src.first][i]]);
                }
                q.push(make_pair(g[src.first][i],min(src.second,cap[src.first][g[src.first][i]])));
            }
        }
    }
    return -1;
}
bool ok(int lim){
    for(int i=0;i<230;i++)for(int j=0;j<230;j++)cap[i][j]=cost[i][j];
    int ret=0;
    while(true){
        int x=bfs(lim);
        if(x==-1)break;
        ret+=x;
        if(ret>=2)break;
        int y=sink;
        while(pr[y]!=-2){
            cap[pr[y]][y]-=x;
            cap[y][pr[y]]+=x;
            y=pr[y];
        }
    }
    return (ret>=2);
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n,d;
        char c;
        scanf("%d%d",&n,&d);
        int w[n];
        for(int i=0;i<230;i++)g[i].clear();
        g[source].push_back(sink);
        g[sink].push_back(source);
        jmp[sink][source]=jmp[source][sink]=d;
        cost[source][sink]=inf;
        cost[sink][source]=0;
        for(int i=0;i<n;i++){
            scanf(" %c-%d",&c,&w[i]);
            g[source].push_back(i);
            g[i].push_back(source);
            cost[source][i]=inf;
            cost[i][source]=0;
            jmp[source][i]=w[i];
            jmp[i][source]=w[i];
            g[i].push_back(ns(i));
            g[ns(i)].push_back(i);
            if(c=='B'){
                cost[i][ns(i)]=inf;
                cost[ns(i)][i]=0;
            }else {
                cost[i][ns(i)]=1;
                cost[ns(i)][i]=0;
            }
            g[ns(i)].push_back(sink);
            g[sink].push_back(ns(i));
            jmp[ns(i)][sink]=d-w[i];
            jmp[sink][ns(i)]=d-w[i];
            cost[ns(i)][sink]=inf;
            cost[sink][ns(i)]=0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                g[ns(i)].push_back(j);
                g[j].push_back(ns(i));
                cost[ns(i)][j]=inf;
                cost[j][ns(i)]=0;
                jmp[ns(i)][j]=abs(w[i]-w[j]);
                jmp[j][ns(i)]=abs(w[i]-w[j]);
            }
        }
        int low=0,high=d,mid;
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


