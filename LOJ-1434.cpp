#include<bits/stdc++.h>
using namespace std;
int r,c,n,l;
int dirr[]= {-1,-1,0,1,1,1,0,-1,0};
int dirc[]= {0,1,1,1,0,-1,-1,-1,0};
string dir[]= {"U","UR","R","DR","D","DL","L","UL","*"};
char s[32][32],_s[20];
vector<string>ans;
bool vis[17][32][32];
bool dfs(int ii,int xx,int yy) {
    if(ii==l)return true;
    if(vis[ii][xx][yy])return false;
    for(int i=0; i<9; i++) {
        int _x=xx+dirr[i],_y=yy+dirc[i];
        if(_x<0 || _y<0 || _x>=r || _y>=c)continue;
        if(s[_x][_y]==_s[ii]) {
            if(dfs(ii+1,_x,_y)) {
                ans.push_back(dir[i]);
                vis[ii][xx][yy]=1;
                return true;
            }
        }
    }
    vis[ii][xx][yy]=1;
    return false;
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        scanf("%d%d",&r,&c);
        for(int i=0; i<r; i++) {
            scanf(" %s",&s[i]);
        }
        scanf("%d",&n);
        cout<<"Case "<<z<<":\n";
        while(n--) {
            scanf(" %s",_s);
            cout<<_s<<" ";
            l=strlen(_s);
            bool f=0;
            for(int i=0; i<r && !f; i++) {
                for(int j=0; j<c && !f; j++) {
                    if(_s[0]==s[i][j]) {
                        memset(vis,0,sizeof(vis));
                        ans.clear();
                        if(dfs(1,i,j)) {
                            cout<<"found: "<<"("<<i+1<<","<<j+1<<")";
                            for(int k=ans.size()-1; k>=0; k--) {
                                cout<<", "<<ans[k];
                            }
                            f=1;
                            break;
                        }
                    }
                }
            }
            if(!f)cout<<"not found";
            puts("");
        }
    }
    return 0;
}

