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
int n,u,v;
long long ch[100003],ans;
vector<int>g[100003];
long long dfs(int src){
    for(int i=0;i<g[src].size();i++)ch[src]+=dfs(g[src][i]);
    long long x=ch[src];
    for(int i=0;i<g[src].size();i++){
        x-=ch[g[src][i]];
        ans+=(x*ch[g[src][i]]);
    }
    ch[src]++;
    return ch[src];
}
int main(){
    int t;
    t=RI();
    //scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=1;i<=n;i++)g[i].clear();
        n=RI();
        //scanf("%d",&n);
        memset(ch,0,sizeof(ch));
        for(int i=1;i<n;i++){
            u=RI(),v=RI();
            //scanf("%d%d",&u,&v);
            g[u].push_back(v);
        }
        ans=0;
        dfs(1);
        cout<<"Case "<<z<<": "<<n-1<<" "<<ans<<"\n";
    }
    return 0;
}

