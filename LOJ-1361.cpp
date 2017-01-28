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
const int inf=1<<30;
int source=211,sink=212,pr[220],cap[220][220];
vector<int>g[220];
int bfs(){
    memset(pr,-1,sizeof(pr));
    pr[source]=-2;
    queue<pair<int,int> >q;
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
    t=RI();
    //scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n,m;
        for(int i=0;i<220;i++)g[i].clear();
        n=RI(),m=RI();
        //scanf("%d%d",&n,&m);
        int x[n+1],y[n+1],a,p,q,r;
        for(int i=1;i<=n;i++)x[i]=RI();//scanf("%d",&x[i]);
        for(int i=1;i<=n;i++)y[i]=RI();//scanf("%d",&y[i]);
        for(int i=1;i<=n;i++){
            a=RI();//scanf("%d",&a);
            g[source].push_back(i);
            g[i].push_back(source);
            g[i].push_back(sink);
            g[sink].push_back(i);
            cap[source][i]=x[i];
            cap[i][sink]=y[i];
            cap[i][source]=cap[sink][i]=0;
            if(a==-1){
                cap[source][i]=inf;
                cap[i][source]=0;
            }
            else if(a==1){
                cap[i][sink]=inf;
                cap[sink][i]=0;
            }
        }
        for(int i=0;i<m;i++){
            p=RI(),q=RI(),r=RI();//scanf("%d%d%d",&p,&q,&r);
            g[p].push_back(q);
            g[q].push_back(p);
            cap[p][q]=cap[q][p]=r;
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

