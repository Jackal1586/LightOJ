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
struct node{
    int vv,ppg;
    node(){vv=0,ppg=-1;}
}tree[8*100000+5];
void propagate(int nd,int bb,int ee){
    int ll=nd<<1,rr=ll+1;
    tree[nd].vv=(ee-bb+1)*tree[nd].ppg;
    if(bb!=ee){
        tree[ll].ppg=tree[nd].ppg;
        tree[rr].ppg=tree[nd].ppg;
    }
    tree[nd].ppg=-1;
    return;
}
void init(int nd,int bb,int ee){
    int ll=nd<<1,rr=ll+1,mm=(bb+ee)>>1;
    if(bb==ee){
        tree[nd]=node();
        return;
    }
    init(ll,bb,mm);
    init(rr,mm+1,ee);
    tree[nd]=node();
    return;
}
void update(int nd,int ii,int jj,int bb,int ee,int vv){
    int ll=nd<<1,rr=ll+1,mm=(bb+ee)>>1;
    if(tree[nd].ppg!=-1)propagate(nd,bb,ee);
    if(ee<ii || bb>jj)return;
    if(bb>=ii && ee<=jj){
        tree[nd].ppg=vv;
        propagate(nd,bb,ee);
        return;
    }
    update(ll,ii,jj,bb,mm,vv);
    update(rr,ii,jj,mm+1,ee,vv);
    tree[nd].vv=tree[ll].vv+tree[rr].vv;
    return;
}
int query(int nd,int ii,int jj,int bb,int ee){
    int ll=nd<<1,rr=ll+1,mm=(bb+ee)>>1;
    if(tree[nd].ppg!=-1)propagate(nd,bb,ee);
    if(ee<ii || bb>jj)return 0;
    if(bb>=ii && ee<=jj)return tree[nd].vv;
    return query(ll,ii,jj,bb,mm)+query(rr,ii,jj,mm+1,ee);
}
int main(){
    int t;
    t=RI();//scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n,l,r,low=12345678,high=-1;
        n=RI();//scanf("%d",&n);
        init(1,1,2*n);
        for(int i=0;i<n;i++){
            l=RI(),r=RI();//scanf("%d%d",&l,&r);
            update(1,l,r,1,2*n,i+1);
            low=min(low,l);
            high=max(high,r);
        }
        set<int>s;
        for(int i=low;i<=high;i++){
            int x=query(1,i,i,1,2*n);
            if(x!=0)s.insert(x);
        }
        cout<<"Case "<<z<<": "<<s.size()<<"\n";
    }
    return 0;
}

