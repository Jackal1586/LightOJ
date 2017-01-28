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
int n,m,vis[10004],low[10004],_time,u,v;
bool isAP[10004];
map<int,bool>mp;
vector<int>g[10004];
void dfs(int s,int pr) {
    int ch=0;
    vis[s]=low[s]=_time;
    _time++;
    for(int i=0; i<(int)g[s].size(); i++) {
        if(g[s][i]==pr)continue;
        if(vis[g[s][i]]==-1) {
            ch++;
            dfs(g[s][i],s);
            low[s]=min(low[s],low[g[s][i]]);
            if(low[g[s][i]]>=vis[s])isAP[s]=1;
        } else low[s]=min(low[s],vis[g[s][i]]);
    }
    if(pr==-1)isAP[s]=(ch>1);
    return;
}
int dfsB(int s) {
    if(isAP[s])mp[s]=1;
    if(vis[s]!=-1 || isAP[s])return 0;
    vis[s]=1;
    int ret=1;
    for(int i=0; i<(int)g[s].size(); i++) {
        ret+=dfsB(g[s][i]);
    }
    return ret;
}
int main() {
    int t=RI();
    for(int z=1; z<=t; z++) {
        for(int i=0; i<n; i++) {
            g[i].clear();
        }
        memset(vis,-1,sizeof(vis));
        memset(isAP,0,sizeof(isAP));
        n=RI(),m=RI();
        for(int i=0; i<m; i++) {
            u=RI(),v=RI();
            g[u].push_back(v);
            g[v].push_back(u);
        }
        _time=0;
        dfs(0,-1);
        memset(vis,-1,sizeof(vis));
        unsigned long long ans1=0,ans2=1,x;
        for(int i=0; i<n; i++) {
            if(!isAP[i] && vis[i]==-1) {
                mp.clear();
                x=dfsB(i);
                if(mp.size()>1)continue;
                if(mp.size()>0) {
                    ans1++;
                    ans2*=x;
                }else{
                    ans1+=2;
                    ans2*=((x*(x-1))/2);
                }
            }
        }
        cout<<"Case "<<z<<": "<<ans1<<" "<<ans2<<"\n";
    }
    return 0;
}

