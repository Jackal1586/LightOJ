#include<bits/stdc++.h>
using namespace std;
inline int RI() {
    int  ret = 0, flag = 1,ip = getchar_unlocked();
    for(; ip < 48 || ip > 57; ip = getchar_unlocked()) {
        if(ip == 45) {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}
struct edge{
    int v,ri,ii;
    long long ch,cl;
    edge(){}
    edge(int _v,long long _ch,long long _cl,int _ri,int _ii){v=_v,ch=_ch,cl=_cl,ri=_ri,ii=_ii;}
};
vector<edge>g[210];
int source,sink,/*specialSource,*/level[210],cnt[210],n,m,u,v,l,c/*specialSink*/;
inline void addEdge(int u,int v,long long ch,long long cl,int ii){
    g[u].push_back(edge(v,ch,cl,g[v].size(),ii));
    g[v].push_back(edge(u,0,0,g[u].size()-1,-1));
    return;
}
inline bool bfs(){
    memset(level,-1,sizeof(level));
    level[source]=0;
    queue<int>q;
    q.push(source);
    while(!q.empty()){
        int s=q.front();
        q.pop();
        for(int i=0;i<(int)g[s].size();i++){
            if(level[g[s][i].v]==-1 && g[s][i].ch>0){
                level[g[s][i].v]=level[s]+1;
                q.push(g[s][i].v);
            }
        }
    }
    return (level[sink]!=-1);
}
inline long long dfs(int src,long long minCap){
    if(src==sink)return minCap;
    long long x=0,y;
    for(int i=0;i<(int)g[src].size();i++){
        if(g[src][i].ch<=0 || level[g[src][i].v]!=level[src]+1)continue;
        y=dfs(g[src][i].v,min(minCap-x,g[src][i].ch));
        x+=y;
        g[src][i].ch-=y;
        g[g[src][i].v][g[src][i].ri].ch+=y;
        if(x==minCap)break;
    }
    if(x==0)level[src]=0;
    return x;
}
int main(){
    int t;
    t=RI();//scanf("%d",&t);
    for(int z=1;z<=t;z++){
        n=RI(),m=RI();//scanf("%d%d",&n,&m);
        for(int i=0;i<210;i++){
            g[i].clear();
        }
        memset(cnt,0,sizeof(cnt));
        source=0,sink=n+1;//,specialSource=n+2,specialSink=n+3;
        for(int i=0;i<m;i++){
            u=RI(),v=RI(),l=RI(),c=RI();//scanf("%d%d%d%d",&u,&v,&l,&c);
            addEdge(u,v,c-l,l,i);
            cnt[u]-=l;
            cnt[v]+=l;
        }
        long long sum=0;
        //addEdge(source,1,INT_MAX,0,-1);
        //addEdge(n,sink,INT_MAX,0,-1);
        for(int i=1;i<=n;i++){
            //cout<<"m at i = "<<i<<" is "<<cnt[i]<<"\n";
            if(cnt[i]>0){
                sum+=cnt[i];
                addEdge(source,i,cnt[i],0,-1);
            }else addEdge(i,sink,-cnt[i],0,-1);
        }
        //addEdge(source,specialSource,sum,0,-1);
        //addEdge(specialSink,sink,sum,0,-1);
        addEdge(n,1,INT_MAX,0,-1);
        long long flow=0;
        while(bfs()){
            flow+=dfs(source,INT_MAX);
        }
        //cout<<flow<<"\n";
        //cout<<g[source].size()<<" -- "<<g[sink].size()<<endl;
        if(flow!=sum){
            cout<<"Case "<<z<<": no\n";
            continue;
        }
        cout<<"Case "<<z<<": yes\n";
        vector<long long>ans(m);
        for(int i=1;i<=n;i++){
            for(int j=0;j<(int)g[i].size();j++){
                if(g[i][j].ii>=0){
                    ans[g[i][j].ii]=g[i][j].cl+g[g[i][j].v][g[i][j].ri].ch;
                }
            }
        }
        for(int i=0;i<m;i++){
            cout<<ans[i]<<"\n";
        }
    }
    return 0;
}
/**
1
5 5
1 4 5 5
4 2 3 5
2 3 3 5
3 5 0 10
1 5 0 10
*/

