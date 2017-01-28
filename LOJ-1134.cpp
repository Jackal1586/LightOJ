#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
	int n,m;
	scanf("%d%d",&n,&m);
	int a,b=0,arr[m];
	long long ans=0;
	memset(arr,0,sizeof(arr));
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		arr[(a+b)%m]++;
		b=(a+b)%m;
		if(b==0)ans++;
	}
	for(int i=0;i<m;i++){
		if(arr[i])ans+=((((long long)(arr[i]-1))*((long long)(arr[i])))/2);
	}
	cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}
