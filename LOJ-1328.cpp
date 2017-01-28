#include<bits/stdc++.h>
using namespace std;
const long long mod=1000007;
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        long long k,c,n,a0;
        scanf("%lld%lld%lld%lld",&k,&c,&n,&a0);
        long long arr[n],mul[n],ans=0;
        arr[0]=a0;
        mul[0]=-n+1;
        for(int i=1; i<n; i++) {
            arr[i]=(k*arr[i-1]+c)%mod;
            mul[i]=mul[i-1]+2;
        }
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
	ans+=(mul[i]*arr[i]);
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}
