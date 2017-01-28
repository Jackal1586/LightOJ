#include<bits/stdc++.h>
using namespace std;
int m,n,row[102][102],col[102][102],rii,cii,_left[10004],_right[10004];
bool vis[10004];
char s[102][102];
vector<int>g[10004];
bool dfs(int src){
    if(vis[src])return false;
    vis[src]=true;
    for(int i=0;i<(int)g[src].size();i++){
        if(_right[g[src][i]]==-1){
            _right[g[src][i]]=src;
            _left[src]=g[src][i];
            return true;
        }
    }
    for(int i=0;i<(int)g[src].size();i++){
        if(dfs(_right[g[src][i]])){
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
        memset(vis,0,sizeof(vis));
        for(int i=0;i<rii;i++){
            if(_left[i]==-1 && dfs(i)){
                done=false;
            }
        }
    }
    int ret=0;
    for(int i=0;i<rii;i++)ret+=(_left[i]!=-1);
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        for(int i=0;i<10004;i++){
            g[i].clear();
        }
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;i++){
            scanf(" %s",s[i]);
        }
        rii=cii=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s[i][j]=='W')rii++;
                else if(s[i][j]=='.'){
                    row[i][j]=rii;
                }
            }
            rii++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[j][i]=='W')cii++;
                else if(s[j][i]=='.'){
                    col[j][i]=cii;
                }
            }
            cii++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s[i][j]=='.'){
                    g[row[i][j]].push_back(col[i][j]);
                }
            }
        }
        int ans=BPM();
        cout<<"Case "<<z<<": "<<ans<<"\n";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s[i][j]=='.'){
                    if(_left[row[i][j]]==col[i][j]){
                        putchar_unlocked('T');
                    }else putchar_unlocked('.');
                }else putchar_unlocked(s[i][j]);
            }
            puts("");
        }
    }
    return 0;
}

