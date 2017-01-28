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
int n,pr[10003],low[10003],disc[10003],_time=0;
bool vis[10003];
vector<int>g[10003];
vector<pair<int,int> >ans;
void dfs(int src){
    vis[src]=1;
    _time++;
    disc[src]=low[src]=_time;
    for(int i=0;i<g[src].size();i++){
        if(!vis[g[src][i]]){
            pr[g[src][i]]=src;
            dfs(g[src][i]);
            low[src]=min(low[src],low[g[src][i]]);
            if(low[g[src][i]]>disc[src]){
                int x=src,y=g[src][i];
                if(x>y)swap(x,y);
                ans.push_back(make_pair(x,y));
            }
        }else if(g[src][i]!=pr[src]){
            low[src]=min(low[src],disc[g[src][i]]);
        }
    }
    return;
}
int main(){
    int t;
    t=RI();
    //scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=0;i<n;i++)g[i].clear();
        ans.clear();
        n=RI();//scanf("%d",&n);
        for(int i=0;i<n;i++){
            int u,k,v;
            u=RI(),k=RI();//scanf("%d (%d)",&u,&k);
            for(int j=0;j<k;j++){
                v=RI();//scanf("%d",&v);
                g[u].push_back(v);
            }
        }
        memset(pr,-1,sizeof(pr));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            if(!vis[i])dfs(i);
        }
        sort(ans.begin(),ans.end());
        int lim=ans.size();
        cout<<"Case "<<z<<":\n";
        cout<<lim<<" critical links\n";
        for(int i=0;i<lim;i++){
            int x=ans[i].first,y=ans[i].second;
            cout<<x<<" - "<<y<<"\n";
        }
    }
    return 0;
}

