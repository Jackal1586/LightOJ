#include<bits/stdc++.h>
using namespace std;
const int inf=99;
int source=211,sink=212,pr[220],cap[220][220];
vector<int>g[220];
inline int cn(int a){return (a+103);}
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
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=0;i<220;i++)g[i].clear();
        int n,m,a;
        scanf("%d%d",&n,&m);
        //memset(cap,0,sizeof(cap));
        for(int i=1;i<n+m;i++){
            scanf("%d",&a);
            //a--;
            g[source].push_back(i);
            g[i].push_back(source);
            cap[source][i]=a;
            cap[i][source]=0;
        }
        for(int i=1;i<n+m;i++){
            scanf("%d",&a);
            //a--;
            g[cn(i)].push_back(sink);
            g[sink].push_back(cn(i));
            cap[cn(i)][sink]=a;
            cap[sink][cn(i)]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int u=i+j-1,v=i+(m-j);
            //cout<<i<<" "<<j<<" "<<u<<" "<<v<<endl;
                g[u].push_back(cn(v));
                g[cn(v)].push_back(u);
                cap[u][cn(v)]=99;
                cap[cn(v)][u]=0;
                cap[source][u]--;
                cap[cn(v)][sink]--;
            }
        }
        /*cout<<"graph\n\n";
        for(int i=1;i<n+m;i++){
            //cout<<i<<" : ";
            cout<<cap[source][i]<<" ";
            for(int j=0;j<g[i].size();j++){
                cout<<cap[i][g[i][j]]<<" ";
            }cout<<cap[cn(i)][sink]<<endl;
        }
        cout<<"graph end\n\n";*/
        while(true){
            int x=bfs();
            if(x==-1)break;
            int y=sink;
            //cout<<x<<endl;
            while(pr[y]!=-2){
                cap[pr[y]][y]-=x;
                cap[y][pr[y]]+=x;
                y=pr[y];
            }
            /*cout<<endl;
            for(int i=1;i<n+m;i++){
                for(int j=1;j<n+m;j++){
                    cout<<cap[cn(j)][i]<<" ";
                }cout<<"\n";
            }
            cout<<endl;*/
        }
        cout<<"Case "<<z<<":\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int u=i+j-1,v=i+(m-j);
                cout<<((j==1)?"":" ")<<cap[cn(v)][u]+1;
            }
            cout<<"\n";
        }
    }
    return 0;
}

