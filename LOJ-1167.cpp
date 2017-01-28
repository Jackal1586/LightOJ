#include<bits/stdc++.h>
using namespace std;
int n,t,k,source=0,sink,pr[210],cap[210][210],danger[210][210],p,q,d,cost[210][210];
vector<int>g[210];
inline int ns(int a){if(a==0 || a==n+1)return a;return (a+103);}
bool bfs(int lim){
    memset(pr,-1,sizeof(pr));
    pr[source]=-2;
    queue<int>q;
    q.push(source);
    while(!q.empty()){
        int src=q.front();
        q.pop();
        for(int i=0;i<g[src].size();i++){
            if(pr[g[src][i]]==-1 && cap[src][g[src][i]]>0 && danger[src][g[src][i]]<=lim){
                pr[g[src][i]]=src;
                if(g[src][i]==sink)return 1;
                q.push(g[src][i]);
            }
        }
    }
    return 0;
}
bool ok(int lim){
    int ret=0;
    while(bfs(lim)){
        ret++;
        int y=sink;
        while(pr[y]!=-2){
            cap[pr[y]][y]--;
            cap[y][pr[y]]++;
            y=pr[y];
        }
        if(ret>=k)break;
    }
    return (ret>=k);
}
void reset(){
    for(int i=0;i<210;i++)for(int j=0;j<210;j++)cap[i][j]=cost[i][j];
    return;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int z=1;z<=T;z++){
        for(int i=0;i<210;i++)g[i].clear();
        scanf("%d%d",&n,&t);
        sink=n+1;
        for(int i=1;i<=n;i++){
            g[i].push_back(ns(i));
            g[ns(i)].push_back(i);
            cost[i][ns(i)]=1;
            cost[ns(i)][i]=0;
            danger[i][ns(i)]=danger[ns(i)][i]=0;
        }
        for(int i=0;i<t;i++){
            scanf("%d%d%d",&p,&q,&d);
            if(p>q)swap(p,q);
            g[ns(p)].push_back(q);
            g[q].push_back(ns(p));
            cost[ns(p)][q]=1;
            cost[q][ns(p)]=0;
            danger[ns(p)][q]=danger[q][ns(p)]=d;
        }
        scanf("%d",&k);
        int low=0,high=1<<21,mid;
        while((high-low)>=4){
            //cout<<low<<" "<<high<<endl;
            mid=(low+high)>>1;
            reset();
            if(ok(mid))high=mid;
            else low=mid;
        }
        for(;low<=high;low++){
            reset();
            if(ok(low))break;
        }
        reset();
        //cout<<ok(12)<<endl;
        if(low>=(1<<20))cout<<"Case "<<z<<": no solution\n";
        else cout<<"Case "<<z<<": "<<low<<"\n";
    }
    return 0;
}

