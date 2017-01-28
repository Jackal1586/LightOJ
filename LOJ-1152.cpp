#include<bits/stdc++.h>
using namespace std;
int dirr[]={-1,0,1,0};
int dirc[]={0,-1,0,1};
int n,m,pr[400],id[20][20],gold;
bool vis[400];
char s[20][20];
vector<int>g[400];
bool dfs(int src){
    if(vis[src])return 0;
    vis[src]=1;
    for(int i=0;i<g[src].size();i++){
        if(pr[g[src][i]]==-1 || dfs(pr[g[src][i]])){
            pr[g[src][i]]=src;
            return 1;
        }
    }
    return 0;
}
int BPM(){
    int ret=0;
    memset(pr,-1,sizeof(pr));
    for(int i=0;i<gold;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i))ret++;
    }
    return ret/2;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d%d",&n,&m);
        for(int i=0;i<405;i++)g[i].clear();
        for(int i=0;i<n;i++)scanf(" %s",&s[i]);
        gold=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]=='*'){
                    id[i][j]=gold;
                    gold++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]=='*'){
                    //cout<<i<<" "<<j<<" --> ";
                    for(int k=0;k<4;k++){
                        int x=i+dirr[k],y=j+dirc[k];
                        if(x<0 || y<0 || x>=n || y>=m)continue;
                        if(s[x][y]=='o')continue;
                        //cout<<x<<" "<<y<<" -> ";
                        g[id[i][j]].push_back(id[x][y]);
                    }
                    //cout<<endl;
                }
            }
        }
        int ans=BPM();
        ans=gold-ans;
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

