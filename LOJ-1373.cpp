#include<bits/stdc++.h>
using namespace std;
int n,m,_left[52],_right[52],u,v,x,vis[52];
bool markL[52],markR[52];
char s[52][52];
vector<int>g[52],cation[52],anion[52];
bool dfs(int src){
    if(vis[src]==x)return false;
    vis[src]=x;
    for(int i=0;i<(int)g[src].size();i++){
        if(markR[g[src][i]] && _right[g[src][i]]==-1){
            _right[g[src][i]]=src;
            _left[src]=g[src][i];
            return true;
        }
    }
    for(int i=0;i<(int)g[src].size();i++){
        if(markR[g[src][i]] && dfs(_right[g[src][i]])){
            _right[g[src][i]]=src;
            _left[src]=g[src][i];
            return true;
        }
    }
    return false;
}
int BPM(){
    memset(_left,-1,sizeof(_left));
    memset(_right,-1,sizeof(_right));
    bool done=false;
    while(!done){
        done=true;
        x++;
        for(int i=0;i<n;i++){
            if(_left[i]==-1 && markL[i] && dfs(i)){
                done=false;
            }
        }
    }
    int ret=0;
    for(int i=0;i<n;i++)ret+=(_left[i]!=-1);
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=0;i<52;i++){
            g[i].clear();
            cation[i].clear();
            anion[i].clear();
        }
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf(" %s",&s[i]);
            for(int j=0;j<m;j++){
                if(s[i][j]=='1'){
                    cation[i].push_back(j);
                    anion[j].push_back(i);
                }else g[i].push_back(j);
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            memset(markR,0,sizeof(markR));
            for(int j=0;j<(int)cation[i].size();j++){
                markR[cation[i][j]]=1;
            }
            for(int j=0;j<(int)cation[i].size();j++){
                memset(markL,0,sizeof(markL));
                for(int k=0;k<(int)anion[cation[i][j]].size();k++){
                    markL[anion[cation[i][j]][k]]=1;
                }
                mx=max(mx,int(cation[i].size()+anion[cation[i][j]].size()-BPM()));
                if(mx==n+m)break;
            }
        }
        cout<<"Case "<<z<<": "<<mx<<"\n";
    }
    return 0;
}

