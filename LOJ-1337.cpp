#include<bits/stdc++.h>
using namespace std;
char s[510][510];
int dirr[]={-1,0,1,0};
int n,m,dirc[]={0,-1,0,1};
int cost[510][510];
bool vis[510][510];
bool visited[510][510];
int bfs(pair<int,int>src){
    queue<pair<int,int> >q;
    q.push(src);
    //cost[src.first][src.second]=x;
    vis[src.first][src.second]=true;
    int cnt=0;
    if(s[src.first][src.second]=='C')cnt++;
    while(!q.empty()){
        src=q.front();q.pop();
        for(int i=0;i<4;i++){
            pair<int,int>dest=make_pair(src.first+dirr[i],src.second+dirc[i]);
            if(dest.first<0 || dest.first>=n || dest.second<0 || dest.second>=m)continue;
            if(s[dest.first][dest.second]=='#')continue;
            if(vis[dest.first][dest.second]==false){
                vis[dest.first][dest.second]=true;
                q.push(dest);
                if(s[dest.first][dest.second]=='C')cnt++;
            }
        }
    }return cnt;
}
void bfs1(pair<int,int>src,int x){
    queue<pair<int,int> >q;
    q.push(src);
    //visited[src.first][src.second]=true;
    cost[src.first][src.second]=x;
    while(!q.empty()){
        src=q.front();q.pop();
        for(int i=0;i<4;i++){
            pair<int,int>dest=make_pair(src.first+dirr[i],src.second+dirc[i]);
            if(dest.first<0 || dest.first>=n || dest.second<0 || dest.second>=m)continue;
            if(s[dest.first][dest.second]=='#')continue;
            if(cost[dest.first][dest.second]!=x){
                //visited[dest.first][dest.second]=true;
                cost[dest.first][dest.second]=x;
                q.push(dest);
            }
        }
    }
}
int main(){
int t;
//freopen("input.txt","r",stdin);
scanf("%d",&t);
for(int z=1;z<=t;z++){
    int q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cost[i][j]=vis[i][j]=0;
    //memset(visited,0,sizeof(visited));
    for(int i=0;i<n;i++){
        getchar();
        for(int j=0;j<m;j++){
            scanf("%c",&s[i][j]);
        }
    }for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]!='#' && !vis[i][j]){
      //              cout<<i<<" "<<j<<endl;
                int a=bfs(make_pair(i,j));
                bfs1(make_pair(i,j),a);
            }
        }
    }/*
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<cost[i][j]<<" ";
        }cout<<endl;
    }*/
    cout<<"Case "<<z<<":\n";
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        cout<<cost[a-1][b-1]<<"\n";
    }
}
return 0;
}

