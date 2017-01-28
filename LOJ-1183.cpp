#include<bits/stdc++.h>
using namespace std;
inline int RI()
{
    int ip = getchar_unlocked(), ret = 0, flag = 1;

    for(; ip < 48 || ip > 57; ip = getchar_unlocked())
    {
        if(ip == 45)
        {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }

    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}
struct node {
    long long vv,ppg;
    node() {
        vv=0;ppg=-1;
    }
} tree[4*100000+2];
void init(int nd,int bb,int ee) {
    if(bb==ee) {
        tree[nd]=node();
        return;
    }
    int ll=(nd<<1),mm=(bb+ee)>>1;
    init(ll,bb,mm);
    init(ll+1,mm+1,ee);
    tree[nd]=node();
    return;
}
void update(int nd,int bb,int ee,int ii,int jj,int vv) {
    int ll=(nd<<1),mm=(bb+ee)>>1;
    if(tree[nd].ppg!=-1) {
        tree[nd].vv=(ee-bb+1)*tree[nd].ppg;
        if(bb!=ee) {
            tree[ll].ppg=tree[nd].ppg;
            tree[ll+1].ppg=tree[nd].ppg;
        }
        tree[nd].ppg=-1;
    }
    if(bb>jj || ee<ii)return;
    if(bb>=ii && ee<=jj) {
        tree[nd].vv=(ee-bb+1)*vv;
        if(bb!=ee) {
            tree[ll].ppg=vv;
            tree[ll+1].ppg=vv;
        }
        return;
    }
    update(ll,bb,mm,ii,jj,vv);
    update(ll+1,mm+1,ee,ii,jj,vv);
    tree[nd].vv=tree[ll].vv+tree[ll+1].vv;
    return;
}
long long query(int nd,int bb,int ee,int ii,int jj) {
    int ll=(nd<<1),mm=(bb+ee)>>1;
    if(tree[nd].ppg!=-1) {
        tree[nd].vv=(ee-bb+1)*tree[nd].ppg;
        if(bb!=ee) {
            tree[ll].ppg=tree[nd].ppg;
            tree[ll+1].ppg=tree[nd].ppg;
        }
        tree[nd].ppg=-1;
    }
    if(bb>jj || ee<ii)return 0;
    if(bb>=ii && ee<=jj)return tree[nd].vv;
    return (query(ll,bb,mm,ii,jj)+query(ll+1,mm+1,ee,ii,jj));
}
int n,q,a,x,y,v;
int main() {
    int t;
    t=RI();
    //scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        n=RI();q=RI();
        //scanf("%d%d",&n,&q);
        init(1,1,n);
        cout<<"Case "<<z<<":\n";
        while(q--) {
            a=RI();
            //scanf("%d",&a);
            if(a==1) {
                x=RI();y=RI();v=RI();
                //scanf("%d%d%d",&x,&y,&v);
                update(1,1,n,x+1,y+1,v);
            } else {
                x=RI();y=RI();
                //scanf("%d%d",&x,&y);
                long long xx=query(1,1,n,x+1,y+1);
                long long yy=(y-x+1);
                long long dd=__gcd(xx,yy);
                xx/=dd;
                yy/=dd;
                if(yy==1) {
                    cout<<xx<<"\n";
                } else cout<<xx<<"/"<<yy<<"\n";
            }
        }
    }
    return 0;
}
