#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
vector<int>g[16040],rg[16040],dag[16040];
int n,m,scc[16040],sccii,vis[16040],a,b,_time;
stack<int>st;
inline int cn(int a){
    if(a<0)return (-a+m);
    return a;
}
inline void addEdge(int u,int v){
    g[u].push_back(v);
    rg[v].push_back(u);
    return;
}
void dfsT(int s){
    for(int i=0;i<(int)g[s].size();i++){
        if(vis[g[s][i]]==-1){
            vis[g[s][i]]=1;
            dfsT(g[s][i]);
        }
    }
    st.push(s);
    return;
}
void dfsS(int s){
    for(int i=0;i<(int)rg[s].size();i++){
        if(scc[rg[s][i]]==-1){
            scc[rg[s][i]]=sccii;
            dfsS(rg[s][i]);
        }
    }
    return;
}
void dfsTS(int s){
    for(int i=0;i<(int)dag[s].size();i++){
        if(vis[dag[s][i]]==-1){
            _time++;
            vis[dag[s][i]]=_time;
            dfsTS(dag[s][i]);
        }
    }
    _time++;
    vis[s]=_time;
    return;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=0;i<16040;i++){
            g[i].clear();
            rg[i].clear();
            dag[i].clear();
        }
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            cin>>a>>b;
            addEdge(cn(-a),cn(b));
            addEdge(cn(-b),cn(a));
        }
        memset(vis,-1,sizeof(vis));
        for(int i=1;i<=(2*m);i++){
            if(vis[i]==-1){
                vis[i]=1;
                dfsT(i);
            }
        }
        memset(scc,-1,sizeof(scc));
        sccii=0;
        while(!st.empty()){
            if(scc[st.top()]==-1){
                sccii++;
                scc[st.top()]=sccii;
                dfsS(st.top());
            }
            st.pop();
        }
        bool ok=1;
        for(int i=1;ok && i<=m;i++){
            if(scc[i]==scc[i+m])ok=0;
        }
        if(!ok)cout<<"Case "<<z<<": No\n";
        else{
            for(int i=1;i<=(m*2);i++){
                for(int j=0;j<(int)g[i].size();j++){
                    if(scc[i]!=scc[g[i][j]]){
                        dag[scc[i]].push_back(scc[g[i][j]]);
                    }
                }
            }
//            cout<<sccii<<endl;
            ans.clear();
            memset(vis,-1,sizeof(vis));
            for(int i=1;i<=sccii;i++){
                if(vis[i]==-1){
                    _time++;
                    vis[i]=_time;
                    dfsTS(i);
                }
            }
            for(int i=1;i<=m;i++){
                if(vis[scc[i]]<vis[scc[i+m]])ans.push_back(i);
            }
            cout<<"Case "<<z<<": Yes\n"<<ans.size();
            for(int i=0;i<(int)ans.size();i++)cout<<" "<<ans[i];
            cout<<"\n";
        }
    }
    return 0;
}

