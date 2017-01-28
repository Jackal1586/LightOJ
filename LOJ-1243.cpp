#include<bits/stdc++.h>
using namespace std;
#define cn(a) (a+k+1)
int dirr[]={-1,0,1,0};
int dirc[]={0,-1,0,1};
int t,n,m,k,vis[130],pr[130],_index[130],source,sink,a;
struct edge{
    int v,w,c,ri;
    edge(){}
    edge(int _v,int _w,int _c,int _ri){v=_v,w=_w,c=_c,ri=_ri;}
};
vector<edge>g[130];
void add(int u,int v,int w,int c){
    g[u].push_back(edge(v,w,c,g[v].size()));
    g[v].push_back(edge(u,-w,0,g[u].size()-1));
    return;
}
vector<pair<int,int> >knight,mill;
char s[31][31];
void bfs(int sx,int sy){
    int _vis[n][n];
    memset(_vis,-1,sizeof(_vis));
    _vis[sx][sy]=0;
    queue<int>q;
    q.push(sx);
    q.push(sy);
    while(!q.empty()){
        sx=q.front();q.pop();
        sy=q.front();q.pop();
        for(int i=0;i<4;i++){
            int x=sx+dirr[i],y=dirc[i]+sy;
            if(x<0 || x>=n || y<0 || y>=n || s[x][y]=='#')continue;
            if(_vis[x][y]==-1){
                _vis[x][y]=_vis[sx][sy]+1;
                q.push(x);
                q.push(y);
            }
        }
    }
    for(int i=0;i<m;i++){
        vis[i]=_vis[mill[i].first][mill[i].second];
    }
    return;
}
bool BF(){
    memset(pr,-1,sizeof(pr));
    for(int i=0;i<=sink;i++)vis[i]=1<<28;
    vis[source]=0;
    for(int kk=0;kk<sink;kk++){
        bool f=1;
        for(int i=0;i<=sink;i++){
            if(vis[i]==(1<<28))continue;
            for(int j=0;j<(int)g[i].size();j++){
                if(vis[g[i][j].v]>vis[i]+g[i][j].w && g[i][j].c>0){
                    f=0;
                    vis[g[i][j].v]=vis[i]+g[i][j].w;
                    pr[g[i][j].v]=i;
                    _index[g[i][j].v]=j;
                }
            }
        }
        if(f)break;
    }
    return vis[sink]<(1<<28);
}
int main(){
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d%d%d",&n,&k,&m);
        for(int i=0;i<=129;i++)g[i].clear();
        knight.clear();
        mill.clear();
        knight=vector<pair<int,int> >(k);
        for(int i=0;i<n;i++){
            scanf(" %s",&s[i]);
            for(int j=0;j<n;j++){
                if(isupper(s[i][j])){
                    knight[s[i][j]-'A']=make_pair(i,j);
                }else if(s[i][j]=='m'){
                    mill.push_back(make_pair(i,j));
                }
            }
        }
        source=0,sink=k+m+1;
        for(int i=0;i<k;i++){
            scanf("%d",&a);
            bfs(knight[i].first,knight[i].second);
            add(source,i+1,0,a);
            for(int j=0;j<m;j++){
                if(vis[j]!=-1)add(i+1,cn(j),vis[j],1);
            }
        }
        for(int i=0;i<m;i++){
            add(cn(i),sink,0,1);
        }
        int ans=0;
        while(BF()){
            int minCap=INT_MAX;
            int y=sink;
            while(pr[y]>=0){
                minCap=min(minCap,g[pr[y]][_index[y]].c);
                y=pr[y];
            }
            y=sink;
            ans+=minCap*vis[sink];
            while(pr[y]>=0){
                g[pr[y]][_index[y]].c-=minCap;
                g[y][g[pr[y]][_index[y]].ri].c+=minCap;
                y=pr[y];
            }
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

