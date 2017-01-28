#include<bits/stdc++.h>
using namespace std;
vector<int>g[70];
int n,m;
int cap[70][70],pr[70];
bool vis[70];
int bfs(){
    memset(vis,0,sizeof(vis));
    memset(pr,-1,sizeof(pr));
    queue<int>q;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        int src=q.front();
        q.pop();
        for(int i=0;i<g[src].size();i++){
            if(!vis[g[src][i]] && cap[src][g[src][i]]>0){
                vis[g[src][i]]=1;
                pr[g[src][i]]=src;
                if(g[src][i]==m+7){
                    return 1;
                }
                q.push(g[src][i]);
            }
        }
    }
    return -1;
}
int main(){
    int t;
    scanf("%d",&t);
    map<string,int>mp;
    mp["XXL"]=1;
    mp["XL"]=2;
    mp["L"]=3;
    mp["M"]=4;
    mp["S"]=5;
    mp["XS"]=6;
    string s1,s2;
    for(int z=1;z<=t;z++){
        scanf("%d%d",&n,&m);
        for(int i=0;i<=68;i++){
            g[i].clear();
        }
        memset(cap,0,sizeof(cap));
        for(int i=1;i<=6;i++){
            g[0].push_back(i);
            g[i].push_back(0);
            cap[0][i]=n;
        }
        for(int i=0;i<m;i++){
            cin>>s1>>s2;
            cap[mp[s1]][i+7]=1;
            cap[mp[s2]][i+7]=1;
            g[mp[s1]].push_back(i+7);
            g[mp[s2]].push_back(i+7);
            g[i+7].push_back(mp[s1]);
            g[i+7].push_back(mp[s2]);
        }
        for(int i=0;i<m;i++){
            g[i+7].push_back(m+7);
            g[m+7].push_back(i+7);
            cap[i+7][m+7]=1;
        }
        int ans=0;
        while(true){
            if(bfs()==-1)break;
            int x=m+7;
            ans++;
            while(pr[x]!=-1){
                cap[pr[x]][x]--;
                cap[x][pr[x]]++;
                x=pr[x];
            }
        }
        if(ans==m){
            cout<<"Case "<<z<<": YES\n";
        }else cout<<"Case "<<z<<": NO\n";
    }
    return 0;
}

