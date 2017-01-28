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
struct point{
    long long x,y1,y2,type;
    point(){}
    point(long long _x,long long _y1,long long _y2,long long _type){x=_x,y1=_y1,y2=_y2,type=_type;}
    bool operator<(const point&p)const{return (x<p.x || (x==p.x && type>p.type));}
}v[60004];
long long y[60004];
struct node{
    long long isFull,sum;
    node(){isFull=sum=0;}
    node(long long _isFull,long long _sum){isFull=_isFull,sum=_sum;}
    void _merge(node&q,node&w,int bb,int ee){
        if(isFull>0){
            sum=y[ee]-y[bb];
        }else sum=q.sum+w.sum;
        return;
    }
}tree[2*240005];
void update(int nd,int bb,int ee,int ii,int jj,int vv){
    if(jj<y[bb] || ii>y[ee])return;
    int ll=nd<<1,rr=ll|1,mm=(bb+ee)>>1;
    if(y[bb]>=ii && y[ee]<=jj){
        tree[nd].isFull+=vv;
        tree[nd]._merge(tree[ll],tree[rr],bb,ee);
        return;
    }
    if(bb+1==ee)return;
    update(ll,bb,mm,ii,jj,vv);
    update(rr,mm,ee,ii,jj,vv);
    tree[nd]._merge(tree[ll],tree[rr],bb,ee);
    return;
}
int main(){
    int t;
    t=RI();//scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n,x1,x2,y1,y2,ii=0,jj=0;
        n=RI();//scanf("%lld",&n);
        memset(tree,0,sizeof(tree));
        for(int i=0;i<n;i++){
            x1=RI(),y1=RI(),x2=RI(),y2=RI();//scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
            v[ii]=point(x1,y1,y2,1);ii++;
            v[ii]=point(x2,y1,y2,-1);ii++;
            y[jj]=y1;jj++;
            y[jj]=y2;jj++;
        }
        sort(y,y+jj);
        jj=unique(y,y+jj)-y;
        //y.resize(unique(y.begin(),y.end())-y.begin());
        sort(v,v+ii);
        long long ans=0;
		update(1,0,jj-1,v[0].y1,v[0].y2,v[0].type);
		for(int i=1;i<ii;i++){
			ans+=(v[i].x-v[i-1].x)*tree[1].sum;
			update(1,0,jj-1,v[i].y1,v[i].y2,v[i].type);
		}
		cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}
