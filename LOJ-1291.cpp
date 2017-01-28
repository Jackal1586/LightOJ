#include<bits/stdc++.h>
using namespace std;
#define what_is(x) cerr<<#x<<" is "<<x<<endl;
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
int n,m,u,v,_time,sid,scc[10003],deg[10003],vis[10003];
vector<int>g[10003];
stack<int>st;
int dfs(int src,int pr) {
    _time++;
    vis[src]=_time;
    int mn=_time;
    st.push(src);
    for(int i=0; i<g[src].size(); i++) {
        if(vis[g[src][i]]==0) {
            mn=min(mn,dfs(g[src][i],src));
        } else if(g[src][i]!=pr)mn=min(mn,vis[g[src][i]]);
    }
    if(vis[src]==mn) {
        int x;
        sid++;
        while(true) {
            x=st.top();
            st.pop();
            scc[x]=sid;
            if(x==src)break;
        }
    }
    return mn;
}
int main() {
    int t;
    t=RI();//scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        for(int i=0; i<n; i++)g[i].clear();
        memset(vis,0,sizeof(vis));
        memset(deg,0,sizeof(deg));
        memset(scc,0,sizeof(scc));
        while(!st.empty())st.pop();
        n=RI(),m=RI();//scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++) {
            u=RI(),v=RI();//scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        //cout<<g[2].size()<<endl;
        _time=0,sid=0;
        //for(int i=0;i<n;i++){
        //if(vis[i]==0){
        dfs(0,-1);
        // }
        //}
        for(int i=0; i<n; i++) {
            for(int j=0; j<g[i].size(); j++) {
                //what_is(i) what_is(g[i][j])
                // what_is(scc[i]) what_is(scc[g[i][j]])
                if(scc[i]!=scc[g[i][j]]) {
                    //what_is(i) what_is(g[i][j])
                    deg[scc[g[i][j]]]++;
                }
            }
        }
        /*for(int i=0;i<n;i++){
            what_is(i) what_is(scc[i]);
        }
        what_is(sid)*/
        int cnt=0;
        for(int i=1; i<=sid; i++) {
            cnt+=(deg[i]==1);
            //what_is(i) what_is(deg[i])
        }
        cnt=(cnt+1)/2;
        cout<<"Case "<<z<<": "<<cnt<<"\n";
    }
    return 0;
}

