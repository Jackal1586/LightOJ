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
int n,a[10004],d,u,v;
bool isRoot[10004];
vector<int>g[10004];
int ans;
int dfs(int s,int pr){
    int ret=a[s]-1;
    for(int i=0;i<(int)g[s].size();i++){
        if(g[s][i]==pr)continue;
        ret+=dfs(g[s][i],s);
    }
    ans+=abs(ret);
    return ret;
}
int main(){
    int t;
    t=RI();//scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=0;i<10004;i++){
            g[i].clear();
        }
        n=RI();//scanf("%d",&n);
        memset(isRoot,false,sizeof(isRoot));
        for(int i=0;i<n;i++){
            v=RI(),u=RI(),d=RI();//scanf("%d%d%d",&v,&u,&d);
            a[v]=u;
            for(int j=0;j<d;j++){
                u=RI();//scanf("%d",&u);
                isRoot[u]=1;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        ans=0;
        for(int i=1;i<=n;i++){
            if(isRoot[i]==0){
                dfs(i,-1);
                break;
            }
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

