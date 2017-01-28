#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
	int n,q;
	scanf("%d%d",&n,&q);
	long long arr[n],mul[n],x=n-1,ans=0;
	for(int i=0;i<n;i++,x-=2)mul[i]=x;
	for(int i=0;i<n;i++){
		scanf("%lld",&arr[i]);
		ans+=(mul[i]*arr[i]);
	}
	cout<<"Case "<<z<<":\n";
	while(q--){
		int a,b,c;
		scanf("%d",&a);
		if(a==1){
			cout<<ans<<"\n";
		}else{
			scanf("%d%d",&b,&c);
			ans-=(mul[b]*arr[b]);
			arr[b]=c;
			ans+=(mul[b]*arr[b]);
		}
	}
}
return 0;
}
