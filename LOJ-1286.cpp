#include<bits/stdc++.h>
using namespace std;
const int inf=1<<29;
int source=211,sink=212,pr[220],cap[220][220];
vector<int>g[220];
inline int cn(int a){return (a+101);}
int bfs(){
    memset(pr,-1,sizeof(pr));
    queue<pair<int,int> >q;
    pr[source]=-2;
    q.push(make_pair(source,inf));
    while(!q.empty()){
        pair<int,int>src=q.front();
        q.pop();
        for(int i=0;i<g[src.first].size();i++){
            if(pr[g[src.first][i]]==-1 && cap[src.first][g[src.first][i]]>0){
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
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=0;i<220;i++)g[i].clear();
        int n,m;
        scanf("%d%d",&m,&n);
        int sum=0,w;
        for(int i=0;i<m;i++){
            scanf("%d",&w);
            g[source].push_back(i);
            g[i].push_back(source);
            cap[source][i]=w;
            cap[i][source]=0;
            sum+=w;
        }
        for(int i=0;i<n;i++){
            scanf("%d",&w);
            g[cn(i)].push_back(sink);
            g[sink].push_back(cn(i));
            cap[cn(i)][sink]=w;
            cap[sink][cn(i)]=0;
        }
        for(int i=0;i<m;i++){
            int lim;
            scanf("%d",&lim);
            while(lim--){
                scanf("%d",&w);
                w--;
                g[i].push_back(cn(w));
                g[cn(w)].push_back(i);
                cap[i][cn(w)]=inf;
                cap[cn(w)][i]=0;
            }
        }
        int ans=0;
        while(true){
            int x=bfs();
            if(x==-1)break;
            ans+=x;
            int y=sink;
            while(pr[y]!=-2){
                cap[pr[y]][y]-=x;
                cap[y][pr[y]]+=x;
                y=pr[y];
            }
        }
        ans=sum-ans;
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

