#include<bits/stdc++.h>
using namespace std;
int n,m,cost[210][210],jx,jy;
char s[210][210];
bool vis[210][210];
int dirr[]={-1,0,1,0};
int dirc[]={0,1,0,-1};
void bfs(){
    queue<pair<int,int> >q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='F'){
                q.push(make_pair(i,j));
                cost[i][j]=1;
            }
        }
    }while(!q.empty()){
        pair<int,int>src=q.front();q.pop();
        for(int i=0;i<4;i++){
            pair<int,int>dest=make_pair(src.first+dirr[i],src.second+dirc[i]);
            if(dest.first<0 || dest.first>=n || dest.second<0 || dest.second>=m)continue;
            if(s[dest.first][dest.second]=='#')continue;
            if(cost[dest.first][dest.second]>(cost[src.first][src.second]+1)){
                cost[dest.first][dest.second]=cost[src.first][src.second]+1;
                q.push(dest);
            }
        }
    }
}
int bfs1(){
    queue<pair<pair<int,int>,int> >q;
    q.push(make_pair(make_pair(jx,jy),1));
    if(jx==0 || jx==(n-1) || jy==0 || jy==(m-1))return 1;
    vis[jx][jy]=1;
    int mn=numeric_limits<int>::max();
    while(!q.empty()){
        pair<pair<int,int>,int>src=q.front();q.pop();
        for(int i=0;i<4;i++){
            pair<pair<int,int>,int>dest=make_pair(make_pair(src.first.first+dirr[i],src.first.second+dirc[i]),src.second+1);
            if(dest.first.first<0 || dest.first.first>=n || dest.first.second<0 || dest.first.second>=m)continue;
            if(!vis[dest.first.first][dest.first.second] && dest.second<cost[dest.first.first][dest.first.second]){
                vis[dest.first.first][dest.first.second]=1;
                q.push(dest);
                if(dest.first.first==0 || dest.first.first==(n-1) || dest.first.second==0 || dest.first.second==(m-1)){
                    mn=min(mn,dest.second);
                }
            }
        }
    }return mn;
}
int main(){
int t;
//freopen("input.txt","r",stdin);
scanf("%d",&t);
//cout<<t<<endl;
for(int z=1;z<=t;z++){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        getchar();
        for(int j=0;j<m;j++){
            scanf("%c",&s[i][j]);
            if(s[i][j]=='J')jx=i,jy=j;
            else if(s[i][j]=='#')cost[i][j]=-1;
            else cost[i][j]=numeric_limits<int>::max();
            vis[i][j]=0;
        }
    }bfs();int a=bfs1();
    if(a<numeric_limits<int>::max())cout<<"Case "<<z<<": "<<a<<"\n";
    else cout<<"Case "<<z<<": IMPOSSIBLE\n";
}
return 0;
}

