#include<bits/stdc++.h>
using namespace std;
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
int main() {
    int t;
    t=RI();
    //scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        int n,q;
        n=RI();
        q=RI();
        //scanf("%d%d",&n,&q);
        int st[n][n][17];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                st[i][j][0]=RI();
                //scanf("%d",&st[i][j][0]);
            }
        }
        for(int k=1; (1<<k)<=n; k++) {
            for(int i=0; (i+(1<<k)-1)<n; i++) {
                for(int j=0; (j+(1<<k)-1)<n; j++) {
                    st[i][j][k]=max(st[i][j][k-1],max(st[i][j+(1<<(k-1))][k-1],max(st[i+(1<<(k-1))][j][k-1],st[i+(1<<(k-1))][j+(1<<(k-1))][k-1])));
                }
            }
        }
        cout<<"Case "<<z<<":\n";
        while(q--) {
            int ii,jj,ss,aa,dif=-1;
            ii=RI();
            jj=RI();
            ss=RI();
            //scanf("%d%d%d",&ii,&jj,&ss);
            aa=ss;
            ii--;
            jj--;
            while(aa) {
                aa>>=1;
                dif++;
            }
            cout<<max(st[ii][jj][dif],max(st[ii][jj+ss-(1<<dif)][dif],max(st[ii+ss-(1<<dif)][jj][dif],st[ii+ss-(1<<dif)][jj+ss-(1<<dif)][dif])))<<"\n";
        }
    }
    return 0;
}
