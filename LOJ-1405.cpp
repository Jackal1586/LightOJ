#include<bits/stdc++.h>
using namespace std;
int n,m,source=0,sink=20050,pr[20100];
int dirr[]={-1,0,0,1};
int dirc[]={0,-1,1,0};
char s[105][105];
inline int ns(int a){return (a+10002);}
struct edge{
    int v,cap;
    edge(){}
    edge(int _v,int _cap){
        v=_v;
        cap=_cap;
    }
};
vector<edge>g[20100];
bool bfs(){
    memset(pr,-1,sizeof(pr));
    pr[source]=-2;
    queue<int>q;
    q.push(source);
    while(!q.empty()){
        int src=q.front();
        q.pop();
        for(int i=0;i<g[src].size();i++){
            if(pr[g[src][i].v]==-1 && g[src][i].cap>0){
                pr[g[src][i].v]=src;
                if(g[src][i].v==sink){
                    return 1;
                }
                q.push(g[src][i].v);
            }
        }
    }
    return 0;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int sum=0;
        scanf("%d%d",&m,&n);
        for(int i=0;i<20100;i++)g[i].clear();
        for(int i=0;i<m;i++){
            scanf(" %s",&s[i]);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int nd=i*n+j+1;
                if(s[i][j]=='*'){
                    sum++;
                    g[source].push_back(edge(nd,1));
                    g[ns(nd)].push_back(edge(source,0));
                }
                g[nd].push_back(edge(ns(nd),1));
                g[ns(nd)].push_back(edge(nd,0));
                for(int k=0;k<4;k++){
                    int x=i+dirr[k],y=j+dirc[k],snd=x*n+y+1;
                    if(x<0 || y<0 || x>=m || y>=n)continue;
                    g[ns(nd)].push_back(edge(snd,1));
                    g[snd].push_back(edge(ns(nd),0));
                }
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    g[ns(nd)].push_back(edge(sink,1));
                    g[sink].push_back(edge(ns(nd),0));
                }
            }
        }
        int ans=0;
        while(true){
            if(!bfs())break;
            ans++;
            int y=sink;
            stack<int>st;
            while(y!=-2){
                st.push(y);
                if(pr[y]!=-2){
                    for(int i=0;i<g[y].size();i++){
                        if(g[y][i].v==pr[y]){
                            g[y][i].cap++;
                            break;
                        }
                    }
                }
                y=pr[y];
            }
            y=st.top();
            st.pop();
            while(y!=sink){
                for(int i=0;i<g[y].size();i++){
                    if(g[y][i].v==st.top()){
                        g[y][i].cap--;
                        break;
                    }
                }
                y=st.top();
                st.pop();
            }
        }
        cout<<"Case "<<z;
        if(sum==ans)puts(": yes");
        else puts(": no");
    }
    return 0;
}

