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
int n,m,u,v,scc[1003],sccii,_left[1003],_right[1003],x;
int vis[1003],mark[1003][1003];
vector<int>g[1003],rg[1003],fg[1003];
stack<int>st;
void dfs(int src){
    vis[src]=x;
    for(int i=0;i<(int)g[src].size();i++){
        if(vis[g[src][i]]!=x){
            dfs(g[src][i]);
        }
    }
    st.push(src);
    return;
}
void rdfs(int src){
    vis[src]=x;
    for(int i=0;i<(int)rg[src].size();i++){
        if(vis[rg[src][i]]!=x){
            rdfs(rg[src][i]);
        }
    }
    scc[src]=sccii;
    return;
}
void bdfs(int src,int pr){
    if(vis[src]==x)return;
    vis[src]=x;
    for(int i=0;i<(int)rg[src].size();i++){
        fg[pr].push_back(rg[src][i]);
        bdfs(rg[src][i],pr);
    }
    return;
}
bool fdfs(int src){
    if(vis[src]==x)return 0;
    vis[src]=x;
    for(int i=0;i<(int)fg[src].size();i++){
        if(_right[fg[src][i]]==-1){
            _right[fg[src][i]]=src;
            _left[src]=fg[src][i];
            return 1;
        }
    }
    for(int i=0;i<(int)fg[src].size();i++){
        if(fdfs(_right[fg[src][i]])){
            _right[fg[src][i]]=src;
            _left[src]=fg[src][i];
            return 1;
        }
    }
    return 0;
}
int BPM(){
    memset(_left,-1,sizeof(_left));
    memset(_right,-1,sizeof(_right));
    bool done=0;
    while(!done){
        done=1;
        x++;
        //memset(vis,0,sizeof(vis));
        for(int i=1;i<=sccii;i++){
            if(_left[i]==-1 && fdfs(i)){
                done=0;
            }
        }
    }
    int ret=0;
    for(int i=1;i<=sccii;i++)ret+=(_left[i]!=-1);
    return ret;
}
int main(){
    int t;
    t=RI();//scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=0;i<1003;i++){
            g[i].clear();
            rg[i].clear();
            fg[i].clear();
        }
        n=RI(),m=RI();//scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            u=RI(),v=RI();//scanf("%d%d",&u,&v);
            g[u].push_back(v);
            rg[v].push_back(u);
        }
        x++;
        //memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            if(vis[i]!=x){
                dfs(i);
            }
        }
        sccii=0;
        x++;
        //memset(vis,0,sizeof(vis));
        while(!st.empty()){
            if(vis[st.top()]!=x){
                sccii++;
                rdfs(st.top());
            }
            st.pop();
        }
        //cout<<sccii<<endl;
        if(sccii==1){
            cout<<"Case "<<z<<": 1\n";
            continue;
        }
        x++;
        //memset(mark,0,sizeof(mark));
        for(int i=0;i<1003;i++){
            rg[i].clear();
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<(int)g[i].size();j++){
                if(scc[i]!=scc[g[i][j]] && mark[scc[i]][scc[g[i][j]]]!=x){
                    rg[scc[i]].push_back(scc[g[i][j]]);
                    mark[scc[i]][scc[g[i][j]]]=x;
                }
            }
        }
        for(int i=1;i<=sccii;i++){
            x++;
            //memset(vis,0,sizeof(vis));
            bdfs(i,i);
        }
        cout<<"Case "<<z<<": "<<sccii-BPM()<<"\n";
    }
    return 0;
}

