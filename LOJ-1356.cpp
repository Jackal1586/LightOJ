#include<bits/stdc++.h>
using namespace std;
int n,_left[40004],_right[40004],vis[40004],x,arr[40004],mark[500005],level[40004],lim;
vector<int>g[40004];
vector<int>prime;
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
inline void sieve() {
    for(int i=4; i<=500000; i+=2)mark[i]=1;
    prime.push_back(2);
    for(long long i=3; i<=500000; i+=2) {
        if(mark[i]==0) {
            prime.push_back(i);
            for(long long j=i*i; j<=500000; j+=(i<<1)) {
                mark[j]=1;
            }
        }
    }
    return;
}
inline bool dfs(int src) {
    if(vis[src]==x)return false;
    vis[src]=x;
    for(int i=0; i<(int)g[src].size(); i++) {
        if(_right[g[src][i]]==-1) {
            _right[g[src][i]]=src;
            _left[src]=g[src][i];
            return true;
        }
    }
    for(int i=0; i<(int)g[src].size(); i++) {
        if(dfs(_right[g[src][i]])) {
            _right[g[src][i]]=src;
            _left[src]=g[src][i];
            return true;
        }
    }
    return false;
}
inline int BPM() {
    memset(_left,-1,sizeof(_left));
    memset(_right,-1,sizeof(_right));
    bool done=false;
    while(!done) {
        x++;
        done=true;
        for(int i=0; i<n; i++) {
            if(_left[i]==-1 && dfs(i)) {
                done=false;
            }
        }
    }
    int ret=0;
    for(int i=0; i<n; i++)ret+=(_left[i]!=-1);
    return ret>>1;
}
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    t=RI();//cin>>t;
    sieve();
    for(int z=1; z<=t; z++) {
        memset(mark,-1,sizeof(mark));
        n=RI();//cin>>n;
        lim=-1;
        for(int i=0; i<n; i++) {
            arr[i]=RI();//cin>>arr[i];
            mark[arr[i]]=i;
            lim=max(lim,arr[i]);
            g[i].clear();
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<(int)prime.size() && arr[i]*prime[j]<=lim; j++) {
                if(mark[arr[i]*prime[j]]!=-1 && mark[arr[i]*prime[j]]!=i) {
                    g[i].push_back(mark[arr[i]*prime[j]]);
                    g[mark[arr[i]*prime[j]]].push_back(i);
                }
            }
        }
        cout<<"Case "<<z<<": "<<n-BPM()<<"\n";
    }
    return 0;
}

