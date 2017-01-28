#include<bits/stdc++.h>
using namespace std;
int n,m,a,source=108,sink=109,pr[110],cap[110][110];
vector<int>g[110];
inline int cn(int a) {
    return (a+52);
}
bool bfs() {
    /**cout<<endl<<endl<<"Capacity print\n\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<cap[i][cn(j)]<<" ";
        }
        cout<<endl;
    }cout<<"\n\ncapacity end\n\n";**/
    memset(pr,-1,sizeof(pr));
    pr[source]=-2;
    queue<int>q;
    q.push(source);
    while(!q.empty()) {
        int src=q.front();
        q.pop();
        for(int i=0; i<g[src].size(); i++) {
            if(pr[g[src][i]]==-1 && cap[src][g[src][i]]>0) {
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
        for(int i=0; i<110; i++)g[i].clear();
        scanf("%d%d",&m,&n);
        int rsum=0,csum=0;
        for(int i=0; i<m; i++) {
            scanf("%d",&a);
            g[source].push_back(i);
            g[i].push_back(source);
            cap[source][i]=a;
            cap[i][source]=0;
            rsum+=a;
        }
        for(int i=0; i<n; i++) {
            scanf("%d",&a);
            csum+=a;
            g[cn(i)].push_back(sink);
            g[sink].push_back(cn(i));
            cap[cn(i)][sink]=a;
            cap[sink][cn(i)]=0;
            for(int j=0; j<m; j++) {
                g[j].push_back(cn(i));
                g[cn(i)].push_back(j);
                cap[j][cn(i)]=1;
                cap[cn(i)][j]=0;
            }
        }
        if(rsum!=csum) {
            cout<<"Case "<<z<<": impossible\n";
            continue;
        }
        int flow=0;
        while(bfs()) {
            flow++;
            int y=sink;
            while(pr[y]!=-2) {
                cap[pr[y]][y]--;
                cap[y][pr[y]]++;
                y=pr[y];
            }
        }
        if(flow<rsum) {
            cout<<"Case "<<z<<": impossible\n";
            continue;
        }
        cout<<"Case "<<z<<":\n";
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(cap[i][cn(j)]==1)cout<<"0";
                else {
                    cap[source][i]++;
                    cap[cn(j)][sink]++;
                    if(bfs()) {
                        cout<<"0";
                        int y=sink;
                        while(pr[y]!=-2) {
                            cap[pr[y]][y]--;
                            cap[y][pr[y]]++;
                            y=pr[y];
                        }
                    } else {
                        cout<<"1";
                        cap[source][i]--;
                        cap[cn(j)][sink]--;
                    }
                }
                cap[i][cn(j)]=cap[cn(j)][i]=0;
            }
            cout<<"\n";
        }
    }
    return 0;
}

