#include<bits/stdc++.h>
using namespace std;
#define cn(a) (a+n+1)
#define sq(x) ((x)*(x))
int n,k,c,vis[110],cost[110][110],cap[110][110],pr[110],source=105,sink=106,start[50],finish[50],cap2[110][110];
vector<int>g[110];
bool BFMAX(){
    memset(pr,-1,sizeof(pr));
    for(int i=0;i<110;i++)vis[i]=-(1<<26);
    pr[source]=-2;
    vis[source]=0;
    for(int k=1;k<=sink;k++){
        bool f=1;
        for(int i=0;i<=sink;i++){
            for(int j=0;j<(int)g[i].size();j++){
                if(vis[g[i][j]]<vis[i]+cost[i][g[i][j]] && cap[i][g[i][j]]>0){
                    f=0;
                    vis[g[i][j]]=vis[i]+cost[i][g[i][j]];
                    pr[g[i][j]]=i;
                }
            }
        }
        if(f)break;
    }
    return vis[sink]>(-(1<<26));
}
bool BFMIN(){
    for(int i=0;i<110;i++)vis[i]=(1<<28);
    memset(pr,-1,sizeof(pr));
    vis[source]=0;
    pr[source]=-2;
    for(int q=0;q<=sink;q++){
        bool f=1;
        for(int i=0;i<=sink;i++){
            for(int j=0;j<(int)g[i].size();j++){
                if(vis[g[i][j]]>vis[i]+cost[i][g[i][j]] && cap2[i][g[i][j]]>0){
                    f=0;
                    vis[g[i][j]]=vis[i]+cost[i][g[i][j]];
                    pr[g[i][j]]=i;
                }
            }
        }
        if(f)break;
    }
    return vis[sink]<((1<<28));
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d%d%d",&n,&k,&c);
        for(int i=0;i<110;i++)g[i].clear();
        for(int i=0;i<n;i++){
            scanf("%d",&start[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&finish[i]);
        }
        source=2*n+1,sink=source+1;
        for(int i=0;i<n;i++){
            g[source].push_back(i);
            g[i].push_back(source);
            g[cn(i)].push_back(sink);
            g[sink].push_back(cn(i));
            cap[source][i]=cap[cn(i)][sink]=1;
            cap[i][source]=cap[sink][cn(i)]=0;
            cost[source][i]=cost[i][source]=cost[cn(i)][sink]=cost[sink][cn(i)]=0;
            for(int j=0;j<n;j++){
                if(finish[j]>start[i]){
                    g[i].push_back(cn(j));
                    g[cn(j)].push_back(i);
                    cap[i][cn(j)]=1;
                    cap[cn(j)][i]=0;
                    cost[i][cn(j)]=min(sq(finish[j]-start[i]-k),c);
                    cost[cn(j)][i]=-cost[i][cn(j)];
                }
            }
        }
        for(int i=0;i<110;i++)for(int j=0;j<110;j++)cap2[i][j]=cap[i][j];
        int mn=0,mx=0,flow=0;
        //cout<<source<<" "<<sink<<endl;
        while(BFMAX()){
            flow++;
            int y=sink;
            //for(int i=0;i<=sink;i++)cout<<pr[i]<<" "<<vis[i]<<endl;cout<<endl;
            while(pr[y]>=0){
                //cout<<y<<endl;
                //getchar();
                cap[pr[y]][y]--;
                cap[y][pr[y]]++;
                mx+=cost[pr[y]][y];
                //cout<<"ok\n";
                y=pr[y];
                //cout<<y<<endl;
            }
        }
        if(flow!=n){
            cout<<"Case "<<z<<": impossible\n";
            continue;
        }
        flow=0;
        while(BFMIN()){
            flow++;
            int y=sink;
            while(pr[y]>=0){
                cap2[pr[y]][y]--;
                cap2[y][pr[y]]++;
                mn+=cost[pr[y]][y];
                y=pr[y];
            }
        }
        if(flow!=n){
            cout<<"Case "<<z<<": impossible\n";
            continue;
        }
        cout<<"Case "<<z<<": "<<mn<<" "<<mx<<"\n";
    }
    return 0;
}


