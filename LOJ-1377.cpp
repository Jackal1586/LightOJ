#include<bits/stdc++.h>
using namespace std;
int dirr[]={-1,0,1,0};
int dirc[]={0,-1,0,1};
int n,m,vis[203][203],stx,sty,etx,ety;
char s[203][203];
pair<int,int>bfs(int sx,int sy,bool f){
    memset(vis,-1,sizeof(vis));
    vis[sx][sy]=0;
    queue<int>q;
    q.push(sx);
    q.push(sy);
    int cnt=0,ret=1<<28;
    while(!q.empty()){
        sx=q.front();q.pop();
        sy=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx=sx+dirr[i],ny=sy+dirc[i];
            if(nx<0 || nx>=m || ny<0 || ny>=n || s[nx][ny]=='#')continue;
            if(f && s[nx][ny]=='*')continue;
            if(vis[nx][ny]==-1){
                vis[nx][ny]=vis[sx][sy]+1;
                q.push(nx);
                q.push(ny);
                if(s[nx][ny]=='*') {
                    cnt++;
                    if(cnt==1)ret=vis[nx][ny];
                    else{
                        if(ret==vis[nx][ny])return make_pair(vis[nx][ny],2);
                        else return make_pair(ret,1);
                    }
                    if(stx==-1) {
                        stx=nx;
                        sty=ny;
                    } else if(etx==-1){
                        etx=nx;
                        ety=ny;
                    }
                }
                if(f && s[nx][ny]=='D') {
                    return make_pair(vis[nx][ny],1);
                }
            }
        }
    }
    if(cnt>0)return make_pair(ret,1);
    return make_pair(-1,1);
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;i++){
            scanf(" %s",s[i]);
        }
        int px,py,dx,dy,cnt=0;
        stx=-1;
        etx=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s[i][j]=='P'){
                    px=i;
                    py=j;
                }else if(s[i][j]=='D'){
                    dx=i;
                    dy=j;
                }else if(s[i][j]=='*'){
                    cnt++;
                }
            }
        }
        int ans=bfs(px,py,1).first;
        if(ans<0)ans=1<<28;
        if(cnt>1){
            pair<int,int>x=bfs(px,py,0);
            etx=-1;
            pair<int,int>y=bfs(dx,dy,0);
            if(x.first<0)x.first=1<<28;
            if(y.first<0)y.first=1<<28;
            if(stx==etx && sty==ety && x.second==1 && y.second==1)ans=min(ans,x.first+y.first+2);
            else ans=min(ans,x.first+y.first+1);
        }
        if(ans>=(1<<28))cout<<"Case "<<z<<": impossible\n";
        else cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

