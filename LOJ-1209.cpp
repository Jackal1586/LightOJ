#include<bits/stdc++.h>
using namespace std;
int m,f,v,pr[503],x,y;
bool vis[503];
char s1,s2;
vector<pair<int,int> >male,female;
vector<int>g[503];
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
    int ret=v;
    memset(pr,-1,sizeof(pr));
    for(int i=0;i<male.size();i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i))ret--;
    }
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        male.clear();
        female.clear();
        for(int i=0;i<v;i++)g[i].clear();
        scanf("%d%d%d",&m,&f,&v);
        for(int i=0;i<v;i++){
            scanf(" %c%d %c%d",&s1,&x,&s2,&y);
            if(s1=='M'){
                male.push_back(make_pair(x,y));
            }else{
                female.push_back(make_pair(x,y));
            }
        }
        for(int i=0;i<male.size();i++){
            for(int j=0;j<female.size();j++){
                if(male[i].first==female[j].second || male[i].second==female[j].first){
                    g[i].push_back(j);
                }
            }
        }
        cout<<"Case "<<z<<": "<<BPM()<<"\n";
    }
    return 0;
}

