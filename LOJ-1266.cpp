#include<bits/stdc++.h>
using namespace std;
int tree[1005][1005];
char vis[1005][1005];
inline int RI() {
    int  ret = 0, flag = 1,ip = getchar_unlocked();
    for(; ip < 48 || ip > 57; ip = getchar_unlocked()) {
        if(ip == 45) {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}
void update(int xx,int y,int vv) {
    while(xx<=1003) {
        int yy=y;
        while(yy<=1003) {
            tree[xx][yy]+=vv;
            yy+=((yy)&(-yy));
        }
        xx+=((xx)&(-xx));
    }
}
int read(int xx,int y) {
    int ret=0;
    while(xx>0) {
        int yy=y;
        while(yy>0) {
            ret+=tree[xx][yy];
            yy-=((yy)&(-yy));
        }
        xx-=((xx)&(-xx));
    }
    return ret;
}
int main() {
    int t,q,a,x1,y1,x2,y2,ans;
    t=RI();
    //scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        q=RI();
        //scanf("%d",&q);
        memset(tree,0,sizeof(tree));
        cout<<"Case "<<z<<":\n";
        while(q--) {
            a=RI();x1=RI();y1=RI();
            //scanf("%d%d%d",&a,&x1,&y1);
            x1++;
            y1++;
            if(a==0) {
                if(vis[x1][y1]!=z){
					update(x1,y1,1);
                    vis[x1][y1]=z;
                }
            } else {
                x2=RI();y2=RI();
                //scanf("%d%d",&x2,&y2);
                x2++;
                y2++;
                x1--;
                y1--;
                ans=0;
                ans+=read(x2,y2);
                ans+=read(x1,y1);
                ans-=read(x2,y1);
                ans-=read(x1,y2);
                cout<<ans<<"\n";
            }
        }
    }
    return 0;
}
