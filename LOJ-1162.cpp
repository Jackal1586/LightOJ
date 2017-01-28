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
int n,st[17][100005],mx[17][100005],mn[17][100005],u,v,w,level[100005],q;
vector<pair<int,int> >g[100005];
void dfs(int s,int p){
    for(int i=0;i<(int)g[s].size();i++){
        if(g[s][i].first!=p){
            st[0][g[s][i].first]=s;
            mx[0][g[s][i].first]=mn[0][g[s][i].first]=g[s][i].second;
            level[g[s][i].first]=level[s]+1;
            dfs(g[s][i].first,s);
        }
    }
    return;
}
int main(){
    int t;
    t=RI();//scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=0;i<=n;i++){
            g[i].clear();
        }
        n=RI();//scanf("%d",&n);
        memset(st,-1,sizeof(st));
        for(int i=1;i<n;i++){
            u=RI(),v=RI(),w=RI();//cin>>u>>v>>w;
            g[u].push_back(make_pair(v,w));
            g[v].push_back(make_pair(u,w));
        }
        level[1]=0;
        dfs(1,-1);
        for(int i=1;(1<<i)<n;i++){
            for(int j=1;j<=n;j++){
                if(st[i-1][j]!=-1){
                    st[i][j]=st[i-1][st[i-1][j]];
                    mx[i][j]=max(mx[i-1][j],mx[i-1][st[i-1][j]]);
                    mn[i][j]=min(mn[i-1][j],mn[i-1][st[i-1][j]]);
                }
            }
        }
        cout<<"Case "<<z<<":\n";
        q=RI();//scanf("%d",&q);
        while(q--){
            u=RI(),v=RI();//scanf("%d%d",&u,&v);
            if(level[u]<level[v])swap(u,v);
//            cout<<level[u]<<" - "<<level[v]<<endl;
            int _mx=0,_mn=INT_MAX;
            for(int i=16;i>=0;i--){
                if((level[u]-(1<<i))>=level[v]){
                    _mx=max(_mx,mx[i][u]);
                    _mn=min(_mn,mn[i][u]);
                    u=st[i][u];
                }
            }
//            cout<<u<<" "<<v<<" "<<_mx<<" "<<_mn<<"\n";
            for(int i=16;i>=0;i--){
                if(st[i][u]!=-1 && st[i][u]!=st[i][v]){
                    _mx=max(_mx,mx[i][u]);
                    _mx=max(_mx,mx[i][v]);
                    _mn=min(_mn,mn[i][v]);
                    _mn=min(_mn,mn[i][u]);
                    u=st[i][u];
                    v=st[i][v];
                }
            }
            if(u!=v){
                _mx=max(_mx,mx[0][u]);
                _mx=max(_mx,mx[0][v]);
                _mn=min(_mn,mn[0][v]);
                _mn=min(_mn,mn[0][u]);
            }
            if(_mn==INT_MAX)_mn=0;
            cout<<_mn<<" "<<_mx<<"\n";
        }
    }
    return 0;
}

