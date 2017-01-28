#include<bits/stdc++.h>
using namespace std;
const int inf=numeric_limits<int>::max();
vector<pair<int,int> >g[110];
int visited[110];
bool comp(int a,int b){return a<b;}
void dijkstra(){
        //priority_queue<int,vector<int>,less<int> >q;
        queue<int>q;
        q.push(1);
        visited[1]=0;
        while(!q.empty()){
                //int temp=q.top();
                int temp=q.front();
                int a=g[temp].size();
                for(int i=0;i<a;i++){
                        pair<int,int>b=g[temp][i];
                        if(visited[b.first]>(visited[temp]+b.second)){
                                visited[b.first]=(visited[temp]+b.second);
                                q.push(b.first);
                        }
                }
                q.pop();
        }
        return;
}
int main() {
    int t,n,m;
    scanf("%d",&t);
    for(int l=1; l<=t; l++) {
        scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back(make_pair(v,w));
            g[v].push_back(make_pair(u,w));
        }
        for(int i=0;i<110;i++)visited[i]=inf;
        dijkstra();
        if(visited[n]==inf)printf("Case %d: Impossible\n",l);
        else printf("Case %d: %d\n",l,visited[n]);
        for(int i=0;i<110;i++)g[i].clear();
    }
    return 0;
}
