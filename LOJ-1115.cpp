#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;
struct point{
    int x,y;
    point(){}
    point(int _x,int _y){x=_x,y=_y;}
};
int dirr[]={0,-1,0,1};
int dirc[]={-1,0,1,0};
int m,n;
char s[52][52];
bool chk[100],vis[52][52];
inline void bfs(int sx,int sy){
    memset(vis,0,sizeof(vis));
    queue<point>q;
    for(int i=0;i<m;i++){
        if(s[i][0]!=s[sx][sy]){
            vis[i][0]=1;
            q.push(point(i,0));
        }
        if(s[i][n-1]!=s[sx][sy]){
            vis[i][n-1]=1;
            q.push(point(i,n-1));
        }
    }
    for(int i=0;i<n;i++){
        if(s[0][i]!=s[sx][sy]){
            vis[0][i]=1;
            q.push(point(0,i));
        }
        if(s[m-1][i]!=s[sx][sy]){
            vis[m-1][i]=1;
            q.push(point(m-1,i));
        }
    }
    while(!q.empty()){
        point src=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int xx=src.x+dirr[i],yy=src.y+dirc[i];
            if(xx<0 || xx>=m || yy<0 || yy>=n)continue;
            if(!vis[xx][yy] && s[xx][yy]!=s[sx][sy]){
                vis[xx][yy]=1;
                q.push(point(xx,yy));
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j]){
                s[i][j]=s[sx][sy];
            }
        }
    }
    return;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d%d",&m,&n);
        memset(chk,0,sizeof(chk));
        for(int i=0;i<m;i++)scanf(" %s",&s[i]);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isalpha(s[i][j]) && !chk[s[i][j]]){
                    chk[s[i][j]]=1;
                    bfs(i,j);
                }
            }
        }
        cout<<"Case "<<z<<":\n";
        for(int i=0;i<m;i++)puts(s[i]);
    }
    return 0;
}

