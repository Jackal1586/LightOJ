#include<bits/stdc++.h>
using namespace std;
int dirr[]= {-1,0,1,0};
int dirc[]= {0,-1,0,1};
struct point {
    int x,y;
    point() {}
    point(int _x,int _y) {
        x=_x,y=_y;
    }
    bool operator==(const point&p)const {
        return (x==p.x && y==p.y);
    }
    point operator+(const point&p) {
        return point(x+p.x,y+p.y);
    }
};
struct state {
    point a,b,c;
    int w;
    state() {
        w=0;
    }
    state(point _a,point _b,point _c,int _w) {
        a=_a,b=_b,c=_c,w=_w;
    }
};
int n;
char s[11][11];
bool vis[11][11][11][11][11][11];
inline bool visited(state src) {
    return vis[src.a.x][src.a.y][src.b.x][src.b.y][src.c.x][src.c.y];
}
inline void visit(state src) {
    vis[src.a.x][src.a.y][src.b.x][src.b.y][src.c.x][src.c.y]=1;
}
state ok(state dest,state src) {
    if(dest.a.x<0 || dest.a.y<0 || dest.a.x>=n || dest.a.y>=n)dest.a=src.a;
    if(dest.b.x<0 || dest.b.y<0 || dest.b.x>=n || dest.b.y>=n)dest.b=src.b;
    if(dest.c.x<0 || dest.c.y<0 || dest.c.x>=n || dest.c.y>=n)dest.c=src.c;
    if(s[dest.a.x][dest.a.y]=='#')dest.a=src.a;
    if(s[dest.b.x][dest.b.y]=='#')dest.b=src.b;
    if(s[dest.c.x][dest.c.y]=='#')dest.c=src.c;
    for(int i=0; i<3; i++) {
        if(dest.a==dest.b) {
            dest.a=src.a;
            dest.b=src.b;
        }
        if(dest.b==dest.c) {
            dest.b=src.b;
            dest.c=src.c;
        }
        if(dest.a==dest.c) {
            dest.a=src.a;
            dest.c=src.c;
        }
    }
    return dest;
}
inline bool done(state dest) {
    if(s[dest.a.x][dest.a.y]=='X' && s[dest.b.x][dest.b.y]=='X' && s[dest.c.x][dest.c.y]=='X')return 1;
    return 0;
}
int bfs(state src) {
    memset(vis,0,sizeof(vis));
    queue<state>q;
    q.push(src);
    visit(src);
    while(!q.empty()) {
        src=q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            point conv(dirr[i],dirc[i]);
            state dest(src.a+conv,src.b+conv,src.c+conv,src.w+1);
            dest=ok(dest,src);
            if(!visited(dest)) {
                visit(dest);
                if(done(dest))return dest.w;
                q.push(dest);
            }
        }
    }
    return -1;
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        point a,b,c;
        scanf("%d",&n);
        for(int i=0; i<n; i++) {
            scanf(" %s",&s[i]);
            for(int j=0; j<n; j++) {
                if(s[i][j]=='A')a=point(i,j);
                else if(s[i][j]=='B')b=point(i,j);
                else if(s[i][j]=='C')c=point(i,j);
            }
        }
        int ans=bfs(state(a,b,c,0));
        if(ans>-1)cout<<"Case "<<z<<": "<<ans<<"\n";
        else cout<<"Case "<<z<<": trapped\n";
    }
    return 0;
}

