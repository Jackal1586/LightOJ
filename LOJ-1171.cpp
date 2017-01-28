#include<bits/stdc++.h>
using namespace std;
int n,m,k,mark[202][202],x,vis[202*202],start[202*202],_left[202*202],_right[202*202],ee,a,b;
int dirr[]={-2,-2,-1,1,2,2,1,-1};
int dirc[]={-1,1,2,2,1,-1,-2,-2};
struct edge{
    int v,_next;
    edge(){}
    edge(int _v,int __next){v=_v,_next=__next;}
}edgeList[202*202*8];
void init(){
    ee=0;
    memset(start,-1,sizeof(start));
    return;
}
void addEdge(int u,int v){
    edgeList[ee]=edge(v,start[u]);start[u]=ee;ee++;
    return;
}
bool dfs(int src){
    if(vis[src]==x)return false;
    vis[src]=x;
    for(int i=start[src];i!=-1;i=edgeList[i]._next){
        if(_right[edgeList[i].v]==-1){
            _right[edgeList[i].v]=src;
            _left[src]=edgeList[i].v;
            return true;
        }
    }
    for(int i=start[src];i!=-1;i=edgeList[i]._next){
        if(dfs(_right[edgeList[i].v])){
            _right[edgeList[i].v]=src;
            _left[src]=edgeList[i].v;
            return true;
        }
    }
    return false;
}
int BPM(){
    memset(_left,-1,sizeof(_left));
    memset(_right,-1,sizeof(_right));
    bool done=false;
    while(!done){
        x++;
        done=true;
        for(int i=1;i<=n*m;i++){
            if(_left[i]==-1 && dfs(i)){
                done=false;
            }
        }
    }
    int ret=0;
    for(int i=1;i<=n*m;i++)ret+=(_left[i]!=-1);
    return ret>>1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;//scanf("%d",&t);
    for(int z=1;z<=t;z++){
        cin>>n>>m>>k;//scanf("%d%d%d",&n,&m,&k);
        x++;
        for(int i=0;i<k;i++){
            cin>>a>>b;//scanf("%d%d",&a,&b);
            mark[a][b]=z;
        }
        init();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int ii=(i-1)*m+j;
                if(mark[i][j]==z)continue;
                for(int k=0;k<8;k++){
                    int xx=i+dirr[k],yy=j+dirc[k];
                    if(xx<1 || xx>n || yy<1 || yy>m || mark[xx][yy]==z)continue;
                    addEdge(ii,(xx-1)*m+yy);
                }
            }
        }
        cout<<"Case "<<z<<": "<<n*m-BPM()-k<<"\n";
    }
    return 0;
}

