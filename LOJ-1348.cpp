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
int n,u,v,a[30004],child[30004],tree[30004],level[30004],pr[30004],head[30004],cnext[30004],chainid[30004],chainpos[30004],pos,nchain;
vector<int>g[30004];
void update(int ii,int vv) {
    while(ii<=n) {
        tree[ii]+=vv;
        ii+=((ii)&(-ii));
    }
    return;
}
int read(int ii) {
    int ret=0;
    while(ii>0) {
        ret+=tree[ii];
        ii-=((ii)&(-ii));
    }
    return ret;
}
void dfs(int s,int p) {
//    cout<<"dfs "<<s<<" "<<p<<endl;
    child[s]=1;
    for(int i=0; i<(int)g[s].size(); i++) {
//        cout<<g[s][i]<<endl;
        if(g[s][i]!=p) {
            level[g[s][i]]=level[s]+1;
            pr[g[s][i]]=s;
            dfs(g[s][i],s);
            child[s]+=child[g[s][i]];
        }
    }
    return;
}
void hld(int s,int p) {
//    cout<<s<<" "<<p<<endl;
    if(head[nchain]==-1) {
        head[nchain]=s;
    }
    chainid[s]=nchain;
    chainpos[s]=pos;
    pos++;
    update(chainpos[s],a[s]);
    int heavyid,mx=-1;
    for(int i=0; i<(int)g[s].size(); i++) {
        if(g[s][i]!=p) {
            if(mx<child[g[s][i]]) {
                mx=child[g[s][i]];
                heavyid=g[s][i];
            }
        }
    }
    if(mx!=-1) {
        hld(heavyid,s);
    }
    for(int i=0; i<(int)g[s].size(); i++) {
        if(g[s][i]!=p && g[s][i]!=heavyid) {
            nchain++;
            hld(g[s][i],s);
        }
    }
    return;
}
inline int lca(int x,int y) {
//    cout<<x<<" "<<y<<endl;
    while(true) {
        int xst=head[chainid[x]],yst=head[chainid[y]];
        if(chainid[x]==chainid[y])return (level[x]<level[y])?x:y;
        if(level[xst]<level[yst])y=pr[yst];
        else x=pr[xst];
    }
    return 0;
}
int hldquery(int x,int y) {
    int ret=0;
    while(true) {
        if(chainid[x]==chainid[y]) {
            ret+=(read(chainpos[x])-read(chainpos[y]-1));
            break;
        }
        ret+=read(chainpos[x])-read(chainpos[head[chainid[x]]]-1);
        x=pr[head[chainid[x]]];
    }
    return ret;
}
int main() {
    int t=RI();
    for(int z=1; z<=t; z++) {
        for(int i=0; i<n; i++) {
            g[i].clear();
        }
        memset(head,-1,sizeof(head));
        memset(pr,-1,sizeof(pr));
        memset(tree,0,sizeof(tree));
        nchain=1;
        pos=1;
        n=RI();
        for(int i=0; i<n; i++) {
            a[i]=RI();
        }
        for(int i=1; i<n; i++) {
            u=RI(),v=RI();
            g[u].push_back(v);
            g[v].push_back(u);
        }
        level[0]=0;
        pr[0]=-1;
        dfs(0,-1);
        hld(0,-1);
//        for(int i=0;i<n;i++){
//            cout<<chainid[i]<<" ";
//        }cout<<endl;
        int q=RI(),tt,x,y;
        cout<<"Case "<<z<<":\n";
        while(q--) {
            tt=RI(),x=RI(),y=RI();
            if(tt==0) {
                int _lca=lca(x,y);
//                cout<<_lca<<" ok\n";
                cout<<hldquery(x,_lca)+hldquery(y,_lca)-a[_lca]<<"\n";
            }else{
                update(chainpos[x],-a[x]);
                update(chainpos[x],y);
                a[x]=y;
            }
        }
    }
    return 0;
}

