#include<bits/stdc++.h>
using namespace std;
struct point{
	int bb,ee;
	point(){};
	point(int _bb,int _ee){bb=_bb;ee=_ee;}
	bool operator<(const point&p)const{return (ee>p.ee);}
}arr[50003];
bool comp(point a,point b){
	return (a.bb<b.bb || (a.bb==b.bb && a.ee<b.ee));
}
int main(){
	int t,n,cnt,mx,x,y;
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&arr[i].bb,&arr[i].ee);
		}
		sort(arr,arr+n,comp);
		priority_queue<point>q;
		q.push(arr[0]);
		mx=-1;
		for(int i=1;i<n;i++){
			if(q.top().ee<arr[i].bb){
				q.pop();
			}
			q.push(arr[i]);
		}
		cout<<"Case "<<z<<": "<<q.size()<<"\n";
	}
	return 0;
}
