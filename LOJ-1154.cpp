#include<bits/stdc++.h>
using namespace std;
int n,p,d,pr[250],cap[250][250],cost[250][250];
bool vis[250];
double x,y,D;
vector<int>g[250];
struct node{
    double x,y;
    node(){}
    node(double _x,double _y){
        x=_x;
        y=_y;
    }
    double dist(node p){
        return hypot(x-p.x,y-p.y);
    }
};
inline int ns(int a){return (a+102);}
int bfs(int dest){
    memset(vis,0,sizeof(vis));
    memset(pr,-1,sizeof(pr));
    vis[0]=1;
    queue<pair<int,int> >q;
    q.push(make_pair(0,1<<28));
    while(!q.empty()){
        pair<int,int>src=q.front();
        q.pop();
        for(int i=0;i<g[src.first].size();i++){
            if(!vis[g[src.first][i]] && cap[src.first][g[src.first][i]]>0){
                vis[g[src.first][i]]=1;
                pr[g[src.first][i]]=src.first;
                if(g[src.first][i]==dest){
                    return min(src.second,cap[src.first][g[src.first][i]]);
                }
                q.push(make_pair(g[src.first][i],min(src.second,cap[src.first][g[src.first][i]])));
            }
        }
    }
    return -1;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        memset(cost,0,sizeof(cost));
        for(int i=0;i<250;i++){
            g[i].clear();
        }
        scanf("%d%lf",&n,&D);
        node arr[n+1];
        int sum=0;
        for(int i=1;i<=n;i++){
            scanf("%lf%lf%d%d",&x,&y,&p,&d);
            arr[i]=node(x,y);
            g[i].push_back(ns(i));
            g[ns(i)].push_back(i);
            g[0].push_back(i);
            cost[0][i]=p;
            cost[i][ns(i)]=cost[ns(i)][i]=d;
            sum+=p;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                if(arr[i].dist(arr[j])<=D){
                    g[ns(i)].push_back(j);
                    g[j].push_back(ns(i));
                    cost[ns(i)][j]=1<<28;
                }
            }
        }
        cout<<"Case "<<z<<":";
        bool f=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<240;j++){
                for(int k=0;k<240;k++){
                    cap[j][k]=cost[j][k];
                }
            }
            int ans=0;
            while(true){
                int x=bfs(i);
                if(x==-1)break;
                ans+=x;
                int y=i;
                while(pr[y]!=-1){
                    cap[pr[y]][y]-=x;
                    cap[y][pr[y]]+=x;
                    y=pr[y];
                }
            }
            //cout<<ans<<" "<<sum<<endl;
            if(ans==sum){
                f=0;
                cout<<" "<<i-1;
            }
        }
        if(f)cout<<" -1";
        cout<<"\n";
    }
    return 0;
}

