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
int sts[100002][17],stl[100002][17],t,n,d;
int main() {
	t=RI();
	//scanf("%d",&t);
	for(int z=1;z<=t;z++){
		n=RI();d=RI();
		//scanf("%d%d",&n,&d);
		for(int i=0;i<n;i++){
			sts[i][0]=RI();
			//scanf("%d",&sts[i][0]);
			stl[i][0]=sts[i][0];
		}
		if(d==1){
			cout<<"Case "<<z<<": 0\n";
			continue;
		}
		for(int i=1;(1<<i)<=d;i++){
			for(int j=0;(j+(1<<i))<=n;j++){
				sts[j][i]=min(sts[j][i-1],sts[j+(1<<(i-1))][i-1]);
				stl[j][i]=max(stl[j][i-1],stl[j+(1<<(i-1))][i-1]);
			}
		}
		int mx=0;
		int x=d,p=-1;
		while(x){
			x>>=1;
			p++;
		}
		for(int i=0;(i+d)<=n;i++){
			mx=max(mx,max(stl[i][p],stl[i+d-(1<<p)][p])-min(sts[i][p],sts[i+d-(1<<p)][p]));
		}
		cout<<"Case "<<z<<": "<<mx<<"\n";
	}
    return 0;
}

