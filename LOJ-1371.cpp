#include<bits/stdc++.h>
using namespace std;
int main(){
	const long long mod=1000000007;
	int t;
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		int n;
		scanf("%d",&n);
		long long a[n],b[n],ans=1;
		for(int i=0;i<n;i++)scanf("%lld",&a[i]);
		for(int i=0;i<n;i++)scanf("%lld",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		int ii=0;
		for(int i=0;i<n;i++){
			while(ii<n && a[ii]<=b[i])ii++;
			ans*=(ii-i);
			ans%=mod;
		}
		cout<<"Case "<<z<<": "<<ans<<"\n";
	}
	return 0;
}
