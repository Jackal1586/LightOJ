#include<bits/stdc++.h>
using namespace std;
vector<int>g[250];
int cap[250][250],source=230,sink=231,pr[250];
inline int cn(int a) {
    return (a+102);
}
bool bfs(){
    memset(pr,-1,sizeof(pr));
    pr[source]=-2;
    queue<int>q;
    q.push(source);
    while(!q.empty()){
        int src=q.front();
        q.pop();
        for(int i=0;i<g[src].size();i++){
            if(pr[g[src][i]]==-1 && cap[src][g[src][i]]>0){
                pr[g[src][i]]=src;
                if(g[src][i]==sink)return 1;
                q.push(g[src][i]);
            }
        }
    }
    return 0;
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        for(int i=0; i<250; i++)g[i].clear();
        memset(cap,0,sizeof(cap));
        int n,m;
        scanf("%d",&n);
        int a[n];
        for(int i=0; i<n; i++)scanf("%d",&a[i]);
        scanf("%d",&m);
        int b[m];
        for(int i=0; i<m; i++)scanf("%d",&b[i]);
        bool f=1;
        for(int i=0; i<n; i++) {
            g[source].push_back(i);
            g[i].push_back(source);
            cap[source][i]=1;
            for(int j=0; j<m; j++) {
                if(f) {
                    g[cn(j)].push_back(sink);
                    g[sink].push_back(cn(j));
                    cap[cn(j)][sink]=1;
                }
                if(b[j]%a[i]==0) {
                    //cout<<"OK "<<i<<" "<<j<<"\n";
                    g[i].push_back(cn(j));
                    g[cn(j)].push_back(i);
                    cap[i][cn(j)]=1;
                }
            }
            f=0;
        }
        int ans=0;
        while(bfs()){
            ans++;
            int y=sink;
            while(pr[y]!=-2){
                cap[pr[y]][y]--;
                cap[y][pr[y]]++;
                y=pr[y];
            }
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

