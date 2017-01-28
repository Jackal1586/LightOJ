#include<bits/stdc++.h>
using namespace std;
int source,sink,pr[120],cap[120][120];
vector<int>g[120];
inline int ns(int a){if(a==1 || a==sink)return a;return (a+52);}
int bfs(){
    memset(pr,-1,sizeof(pr));
    pr[source]=-2;
    queue<pair<int,int> >q;
    q.push(make_pair(source,1<<28));
    while(!q.empty()){
        pair<int,int>src=q.front();
        q.pop();
        for(int i=0;i<g[src.first].size();i++){
            if(pr[g[src.first][i]]==-1 && cap[src.first][g[src.first][i]]>0){
                pr[g[src.first][i]]=src.first;
                if(g[src.first][i]==sink){
                    return min(cap[src.first][g[src.first][i]],src.second);
                }
                q.push(make_pair(g[src.first][i],min(cap[src.first][g[src.first][i]],src.second)));
            }
        }
    }
    return -1;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        memset(cap,0,sizeof(cap));
        for(int i=0;i<120;i++)g[i].clear();
        int m,w,a,b,c;
        scanf("%d%d",&m,&w);
        source=1;
        sink=m;
        for(int i=2;i<m;i++){
            scanf("%d",&a);
            g[i].push_back(ns(i));
            g[ns(i)].push_back(i);
            cap[i][ns(i)]=a;
            cap[ns(i)][i]=a;
        }
        for(int i=0;i<w;i++){
            scanf("%d%d%d",&a,&b,&c);
            g[ns(a)].push_back(b);
            g[b].push_back(ns(a));
            cap[ns(a)][b]=c;
            g[ns(b)].push_back(a);
            g[a].push_back(ns(b));
            cap[ns(b)][a]=c;
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
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

