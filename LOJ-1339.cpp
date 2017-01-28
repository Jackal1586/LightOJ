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
int arr[100003],x,y;
struct node{
    int psum,ssum,lv,rv,msum;
    node(){psum=ssum=msum=0,lv=rv=0;}
    node(int _psum,int _ssum,int _msum,int _lv,int _rv){psum=_psum,ssum=_ssum,msum=_msum,lv=_lv,rv=_rv;}
    void _merge(node q,node w){
        lv=q.lv;
        rv=w.rv;
        if(q.lv==w.lv)psum=q.psum+w.psum;
        else psum=q.psum;
        if(q.rv==w.rv)ssum=q.ssum+w.ssum;
        else ssum=w.ssum;
        msum=max(q.msum,w.msum);
        if(lv==rv)msum=max(msum,q.psum+w.ssum);
        if(q.rv==w.lv)msum=max(msum,q.ssum+w.psum);
        return;
    }
}tree[400003];
void init(int nd,int bb,int ee){
    if(bb==ee){
        tree[nd]=node(1,1,1,arr[bb],arr[bb]);
        //cout<<tree[nd].lv<<" "<<tree[nd].rv<<" "<<tree[nd].psum<<" "<<tree[nd].ssum<<" "<<tree[nd].msum<<" "<<bb<<" "<<ee<<" xx\n";
        return;
    }
    int mm=(bb+ee)>>1,ll=nd<<1,rr=ll+1;
    init(ll,bb,mm);
    init(rr,mm+1,ee);
    tree[nd]._merge(tree[ll],tree[rr]);
    return;
}
node query(int nd,int bb,int ee,int ii,int jj){
    if(bb>jj || ee<ii)return node();
    if(bb>=ii && ee<=jj)return tree[nd];
    int mm=(bb+ee)>>1,ll=nd<<1,rr=ll+1;
    node q=query(ll,bb,mm,ii,jj);
    node w=query(rr,mm+1,ee,ii,jj);
    node ret;
    ret._merge(q,w);
    return ret;
}
int main(){
    int n,q,t;
    t=RI();//scanf("%d",&t);
    for(int z=1;z<=t;z++){
        n=RI(),q=RI(),q=RI();//scanf("%d%d%d",&n,&q,&q);
        for(int i=1;i<=n;i++){
            arr[i]=RI();//scanf("%d",&arr[i]);
        }
        init(1,1,n);
        //node qq=query(1,1,n,1,n);
        //cout<<qq.psum<<" "<<qq.ssum<<" "<<qq.msum<<" "<<qq.lv<<" "<<qq.rv<<endl;
        cout<<"Case "<<z<<":\n";
        while(q--){
            x=RI(),y=RI();//scanf("%d%d",&x,&y);
            node ans=query(1,1,n,x,y);
            cout<<ans.msum<<"\n";//<<" "<<ans.psum<<" "<<ans.ssum<<" "<<ans.lv<<" "<<ans.rv<<"\n";
        }
    }
    return 0;
}

