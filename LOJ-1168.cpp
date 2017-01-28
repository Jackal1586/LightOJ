#include<bits/stdc++.h>
using namespace std;
int t,n,k,u,v,inDegree[1003],outDegree[1003],scc[1003],sccii;
bool vis[1003],check[1003];
stack<int>st;
vector<int>g[1003],rg[1003];
void dfs(int src){
    vis[src]=1;
    for(int i=0;i<(int)g[src].size();i++){
        if(!vis[g[src][i]]){
            dfs(g[src][i]);
        }
    }
    st.push(src);
    return;
}
void rdfs(int src){
    vis[src]=1;
    for(int i=0;i<(int)rg[src].size();i++){
        if(!vis[rg[src][i]]){
            rdfs(rg[src][i]);
        }
    }
    scc[src]=sccii;
    return;
}
int main(){
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=0;i<1003;i++){
            g[i].clear();
            rg[i].clear();
        }
        memset(vis,0,sizeof(vis));
        memset(check,0,sizeof(check));
        memset(inDegree,0,sizeof(inDegree));
        memset(outDegree,0,sizeof(outDegree));
        sccii=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&k);
            for(int j=0;j<k;j++){
                scanf("%d%d",&u,&v);
                g[u].push_back(v);
                rg[v].push_back(u);
                check[u]=check[v]=1;
            }
        }
        if(!check[0]){
            cout<<"Case "<<z<<": NO\n";
            continue;
        }
        for(int i=0;i<1000;i++){
            if(!check[i] || vis[i])continue;
            dfs(i);
        }
        memset(vis,0,sizeof(vis));
        while(!st.empty()){
            if(!vis[st.top()]){
                rdfs(st.top());
                sccii++;
            }
            st.pop();
        }
        bool f=1;
        for(int i=0;f && i<1000;i++){
            if(!check[i])continue;
            for(int j=0;j<(int)g[i].size();j++){
                if(scc[i]!=scc[g[i][j]]){
                    inDegree[scc[g[i][j]]]++;
                    outDegree[scc[i]]++;
                    if(inDegree[scc[i]]>1 || outDegree[scc[i]]>1){
                        f=0;
                        break;
                    }
                    if(inDegree[scc[g[i][j]]]>1 || outDegree[scc[g[i][j]]]>1){
                        f=0;
                        break;
                    }
                }
            }
        }
        int zeroOut=0,zeroIn=0;
        for(int i=0;i<sccii;i++){
            zeroIn+=(inDegree[i]==0);
            zeroOut+=(outDegree[i]==0);
        }
        if(zeroIn==1 && zeroOut==1 && f && inDegree[scc[0]]==0 && (outDegree[scc[0]]==1 || sccii<=1)){
            cout<<"Case "<<z<<": YES\n";
        }else cout<<"Case "<<z<<": NO\n";
    }
    return 0;
}

