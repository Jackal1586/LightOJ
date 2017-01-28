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
int n,q,tree[200005],arr[200005];
inline void update(int ii,int vv){
	while(ii<=(n+q)){
		tree[ii]+=vv;
		ii+=((ii)&(-ii));
	}
	return;
}
inline int read(int ii){
	int ret=0;
	while(ii>0){
		ret+=tree[ii];
		ii-=((ii)&(-ii));
	}
	return ret;
}
int main() {
    int t;
    t=RI();
    //scanf("%d",&t);
    for(int z=1;z<=t;z++){
		n=RI();q=RI();
		//scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++){
			arr[i]=RI();
			//scanf("%d",&arr[i]);
		}
		memset(tree,0,sizeof(tree));
		for(int i=1;i<=n;i++)update(i,1);
		cout<<"Case "<<z<<":\n";
		int a=q,lim=n;
		while(a--){
			char c=0;
			int d;
//			for(int i=1;i<=(n+q);i++){
//				cout<<read(i)<<" ";
//			}cout<<endl;
			while(c!='a' && c!='c'){
        c=getchar_unlocked();
			}
			d=RI();
			//scanf(" %c %d",&c,&d);
			if(c=='a'){
				arr[n+1]=d;
				n++;
				lim++;
				update(n,1);
			}else{
				if(d>lim){
					cout<<"none\n";
					continue;
				}
				int low=1,high=n+q,mid;
				while((high-low)>4){
					mid=(low+high)>>1;
					if(read(mid)>=d)high=mid;
					else low=mid;
				}
				for(;low<=high;low++){
					if(read(low)==d)break;
				}
				if(low>n){
					cout<<"none\n";
					continue;
				}
				cout<<arr[low]<<"\n";
				update(low,-1);
				lim--;
			}
		}
    }
    return 0;
}
