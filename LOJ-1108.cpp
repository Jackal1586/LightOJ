#include<bits/stdc++.h>
using namespace std;
int n,m,sii,scc[1003],vis[1003];
bool negCycle[1003],svis[1003],mark[1003],dp[1003];
stack<int>st;
vector<pair<int,int> >g[1003],gr[1003];
void dfs(int src){
    vis[src]=1;
    for(int i=0;i<(int)g[src].size();i++){
        if(vis[g[src][i].first]==-1){
            dfs(g[src][i].first);
        }
    }
    st.push(src);
    return;
}
void rdfs(int src){
    vis[src]=1<<28;
    for(int i=0;i<(int)gr[src].size();i++){
        if(vis[gr[src][i].first]==1){
            rdfs(gr[src][i].first);
        }
    }
    scc[src]=sii;
    return;
}
void dfsU(int src){
    negCycle[src]=1;
    for(int i=0;i<(int)g[src].size();i++){
        if(scc[g[src][i].first]==scc[src] && negCycle[g[src][i].first]==0){
            dfsU(g[src][i].first);
        }
    }
    return;
}
void bellmanFord(int s){
    for(int i=0;i<n;i++)vis[i]=1<<28;
    vector<int>x;
    for(int i=0;i<n;i++){
        if(scc[i]==scc[s]){
            x.push_back(i);
        }
    }
    bool done=0;
    vis[s]=0;
    for(int i=0;i<=(int)x.size();i++){
        done=true;
        for(int j=0;j<(int)x.size();j++){
            for(int k=0;k<(int)g[x[j]].size();k++){
                if(scc[g[x[j]][k].first]==scc[s] && vis[g[x[j]][k].first]>vis[x[j]]+g[x[j]][k].second){
                    vis[g[x[j]][k].first]=vis[x[j]]+g[x[j]][k].second;
                    done=false;
                }
            }
        }
    }
    if(!done){
        dfsU(s);
    }
    return;
}
void dfsS(int src){
    mark[src]=dp[src]=1;
    for(int i=0;i<(int)gr[src].size();i++){
        if(!mark[gr[src][i].first])dfsS(gr[src][i].first);
    }
    return;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=0;i<1003;i++){
            g[i].clear();
            gr[i].clear();
        }
        scanf("%d%d",&n,&m);
        int a,b,c;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            g[a].push_back(make_pair(b,c));
            gr[b].push_back(make_pair(a,c));
        }
        memset(vis,-1,sizeof(vis));
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                dfs(i);
            }
        }
        sii=0;
        memset(negCycle,0,sizeof(negCycle));
        memset(svis,0,sizeof(svis));
        while(!st.empty()){
            if(vis[st.top()]==1){
                rdfs(st.top());
                sii++;
            }
            st.pop();
        }
        for(int i=0;i<n;i++){
            if(!svis[scc[i]]){
                svis[scc[i]]=1;
                bellmanFord(i);
            }
        }
        memset(mark,0,sizeof(mark));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            if(negCycle[i] && !mark[i]){
                dfsS(i);
            }
        }
        bool f=1;
        cout<<"Case "<<z<<":";
        for(int i=0;i<n;i++){
            if(dp[i]){
                cout<<" "<<i;
                f=0;
            }
        }
        if(f)cout<<" impossible";
        puts("");
    }
    return 0;
}

