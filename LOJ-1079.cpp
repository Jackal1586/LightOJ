#include<bits/stdc++.h>
using namespace std;
double lim,p[102],dp[101][10001];
int n,mm[102];
double rec(int ii,int mmr){
	if(mmr<=0)return 0;
	if(ii<0)return 1;
	double&ret=dp[ii][mmr];
	if(ret>(-1))return ret;
	ret=rec(ii-1,mmr);
	ret=min(ret,p[ii]+(1.0-p[ii])*rec(ii-1,mmr-mm[ii]));
	return ret;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		scanf("%lf %d",&lim,&n);
		int high=0,low=0,mid;
		for(int i=0;i<n;i++){
			scanf("%d %lf",&mm[i],&p[i]);
			high+=mm[i];
		}
		double x;
		memset(dp,-1,sizeof(dp));
		while((high-low)>=4){
			mid=(low+high)/2;
			x=rec(n-1,mid);
			if(lim>x)low=mid;
			else high=mid-1;
		}
		for(;low<=high;high--){
			x=rec(n-1,high);
			if(lim>x)break;
		}
		cout<<"Case "<<z<<": "<<high<<"\n";
	}
	return 0;
}
