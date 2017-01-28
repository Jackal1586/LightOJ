#include<bits/stdc++.h>
using namespace std;
long long int BM(long long B,long long P,long long M) {
    long long R=1;
    while(P>0) {
        if(P%2==1) {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}
bool comp(pair<int,int>a,pair<int,int>b){
	return (a.second<b.second || (a.second==b.second && a.first<b.first));
}
int main() {
    int t;
    const long long mod=1000000000;
    vector<int>v;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
		long long m,n,k,b;
		scanf("%lld%lld%lld%lld",&m,&n,&k,&b);
		pair<int,int>arr[b];
		for(int i=0;i<b;i++){
			scanf("%d %d",&arr[i].first,&arr[i].second);
		}
		sort(arr,arr+b,comp);
		long long ans=1,x=0,y,a;
		for(int i=0,j,l;i<b;i++){
			x++;
			v.push_back(0);
			v.push_back(arr[i].first);
			for(j=i+1;j<b && arr[j].second==arr[i].second;j++){
				v.push_back(arr[j].first);
			}
			v.push_back(m+1);
			l=j;
			int lim=v.size();
			for(j=1;j<lim;j++){
				if(v[j]==(v[j-1]+1) || v[j]==v[j-1])continue;
				else{
					ans*=k;
					ans%=mod;
					ans*=BM(k-1,v[j]-v[j-1]-2,mod);
					ans%=mod;
				}
			}
			i=l-1;
			v.clear();
		}
		n-=x;
		ans*=BM(k,n,mod);
		ans%=mod;
		ans*=BM(k-1,(m-1)*n,mod);
		ans%=mod;
		cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}
