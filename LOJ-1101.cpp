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
    int u,v,w;
    edge(){}
    edge(int _u,int _v,int _w){u=_u,v=_v,w=_w;}
    bool operator<(const edge&p)const{return (w<p.w);}
};
vector<edge>e;
vector<pair<int,int> >g[50004];
int n,m,x,y,d,st[16][50004],mx[16][50004],level[50004],pr[50004],qq;
int parent(int r){return (pr[r]==r)?r:(pr[r]=parent(pr[r]));}
void bfs(){
    level[1]=0;
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        x=q.front();q.pop();
        for(int i=0;i<(int)g[x].size();i++){
            if(st[0][x]!=g[x][i].first){
                level[g[x][i].first]=level[x]+1;
                st[0][g[x][i].first]=x;
                mx[0][g[x][i].first]=g[x][i].second;
                q.push(g[x][i].first);
            }
        }
    }
    return;
}
int main(){
    int t;
    t=RI();//scanf("%d",&t);
    for(int z=1;z<=t;z++){
        e.clear();
        for(int i=0;i<=n;i++){
            g[i].clear();
        }
        n=RI(),m=RI();//scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            x=RI(),y=RI(),d=RI();//scanf("%d%d%d",&x,&y,&d);
            e.push_back(edge(x,y,d));
        }
        sort(e.begin(),e.end());
        for(int i=1;i<=n;i++)pr[i]=i;
        for(int i=0,k=1;k<n && i<m;i++){
            x=parent(e[i].u),y=parent(e[i].v);
            if(x!=y){
                pr[x]=y;
                g[e[i].u].push_back(make_pair(e[i].v,e[i].w));
                g[e[i].v].push_back(make_pair(e[i].u,e[i].w));
                k++;
            }
        }
        memset(st,-1,sizeof(st));
        bfs();
        for(int i=1;(1<<i)<n;i++){
            for(int j=1;j<=n;j++){
                if(st[i-1][j]!=-1){
                    mx[i][j]=max(mx[i-1][j],mx[i-1][st[i-1][j]]);
                    st[i][j]=st[i-1][st[i-1][j]];
                }
            }
        }
        qq=RI();//scanf("%d",&qq);
        cout<<"Case "<<z<<":\n";
        while(qq--){
            x=RI(),y=RI();//scanf("%d%d",&x,&y);
            if(level[x]<level[y])swap(x,y);
            int _mx=0;
            for(int i=15;i>=0;i--){
                if((level[x]-(1<<i))>=level[y]){
                    _mx=max(_mx,mx[i][x]);
                    x=st[i][x];
                }
            }
            for(int i=15;i>=0;i--){
                if(st[i][x]!=-1 && st[i][x]!=st[i][y]){
                    _mx=max(_mx,mx[i][x]);
                    _mx=max(_mx,mx[i][y]);
                    x=st[i][x];
                    y=st[i][y];
                }
            }
            if(x!=y){
                _mx=max(_mx,mx[0][x]);
                _mx=max(_mx,mx[0][y]);
            }
            cout<<_mx<<"\n";
        }
    }
    return 0;
}

