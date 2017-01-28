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
	int o,t,z,ppg;
	node(){};
	node(int _z,int _o,int _t,int _ppg){o=_o,t=_t,z=_z,ppg=_ppg;}
	void rot(){
		int a=z;
		z=t;
		t=o;
		o=a;
	}
	void add(node a,node b){
		z=a.z+b.z;
		o=a.o+b.o;
		t=a.t+b.t;
	}
}tree[4*100000+2];
void init(int nd,int bb,int ee){
	if(bb==ee){
		tree[nd]=node(1,0,0,0);
		return;
	}
	int mid=((bb+ee)>>1),ll=(nd<<1),rr=((nd<<1)+1);
	init(ll,bb,mid);
	init(rr,mid+1,ee);
	tree[nd]=node(tree[ll].z+tree[rr].z,0,0,0);
}
void update(int nd,int bb,int ee,int ii,int jj){
	if(bb>=ii && ee<=jj){
		tree[nd].ppg++;
		tree[nd].rot();
		return;
	}
	if(bb>jj || ee<ii)return;
	int mid=((bb+ee)>>1),ll=(nd<<1),rr=((nd<<1)+1);
	update(ll,bb,mid,ii,jj);
	update(rr,mid+1,ee,ii,jj);
	tree[nd].add(tree[ll],tree[rr]);
	if(tree[nd].ppg%3==1){
		tree[nd].rot();
	}else if(tree[nd].ppg%3==2){
		tree[nd].rot();
		tree[nd].rot();
	}
	return;
}
int query(int nd,int bb,int ee,int ii,int jj,int cr){
	if(bb>=ii && ee<=jj){
		node a=tree[nd];
		if(cr%3==1){
			a.rot();
		}else if(cr%3==2){
			a.rot();
			a.rot();
		}
		return a.z;
	}
	if(bb>jj || ee<ii)return 0;
	int mid=((bb+ee)>>1),ll=(nd<<1),rr=((nd<<1)+1);
	return (query(ll,bb,mid,ii,jj,f fcr+tree[nd].ppg)+query(rr,mid+1,ee,ii,jj,cr+tree[nd].ppg));
}
int main(){
	int t;
	int n,q,x,xx,yy;
	t=RI();
	//scanf("%d",&t);
	for(int z=1;z<=t;z++){
		n=RI();q=RI();
		//scanf("%d%d",&n,&q);
		cout<<"Case "<<z<<":\n";
		init(1,1,n);
		while(q--){
			x=RI();xx=RI();yy=RI();
			//scanf("%d%d%d",&x,&xx,&yy);
			xx++;
			yy++;
			if(x==0){
				update(1,1,n,xx,yy);
			}else {
				cout<<query(1,1,n,xx,yy,0)<<"\n";
			}
		}
	}
	return 0;
}
