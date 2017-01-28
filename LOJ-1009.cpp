#include<bits/stdc++.h>
using namespace std;
vector<int>g[100000+10];
map<int,bool>vis;
int bfs(int src){
    queue<pair<int,bool> >q;
    q.push(make_pair(src,0));
    vis[src]=0;
    int sum1=0,sum2=0;
    while(!q.empty()){
        pair<int,bool>sr=q.front();
        q.pop();if(sr.second)sum1++;
        else sum2++;
        for(int i=0;i<g[sr.first].size();i++){
            if(vis[g[sr.first][i]]){
                vis[g[sr.first][i]]=0;
                q.push(make_pair(g[sr.first][i],!sr.second));
            }
        }
    }return max(sum1,sum2);
}
int main(){
int t;
//freopen("input.txt","r",stdin);
scanf("%d",&t);
//cout<<t<<endl;
for(int z=1;z<=t;z++){
    int n;
    scanf("%d",&n);
    //cout<<n<<endl;
    int u,v,mx=0,m=-1;
    for(int i=0;i<n;i++){
        scanf("%d%d",&u,&v);
        //cout<<u<<" "<<v<<endl;
        g[u].push_back(v);
        g[v].push_back(u);
        m=max(u,max(v,m));
        vis[u]=vis[v]=1;
    }
    for(map<int,bool>::iterator i=vis.begin();i!=vis.end();i++){
        //cout<<i<<endl;
        if(i->second==1){
            //mx=max(int(g[i].size()),mx);
            mx+=bfs(i->first);
        }
    }cout<<"Case "<<z<<": "<<mx<<"\n";
    for(int i=0;i<=m;i++)g[i].clear();
    vis.clear();
}
return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
int t;

return 0;
}
