#include<bits/stdc++.h>
using namespace std;
vector<int>g[150];
int source=125,sink=126,pr[150],cap[150][150];
inline int cn(int a){return (a+52);}
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
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n,m;
        scanf("%d%d",&m,&n);
        int ma[m],mh[m],md[m],wa[n],wh[n],wd[n];
        for(int i=0;i<m;i++)scanf("%d%d%d",&mh[i],&ma[i],&md[i]);
        for(int i=0;i<n;i++)scanf("%d%d%d",&wh[i],&wa[i],&wd[i]);
        memset(cap,0,sizeof(cap));
        for(int i=0;i<150;i++)g[i].clear();
        bool f=1;
        for(int i=0;i<m;i++){
            g[source].push_back(i);
            g[i].push_back(source);
            cap[source][i]=1;
            for(int j=0;j<n;j++){
                if(f){
                    g[cn(j)].push_back(sink);
                    g[sink].push_back(cn(j));
                    cap[cn(j)][sink]=1;
                }
                if(abs(mh[i]-wh[j])<=12 && abs(ma[i]-wa[j])<=5 && md[i]==wd[j]){
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

