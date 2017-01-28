#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
inline long long BM(long long B,long long P,long long M) {
    long long R=1;
    while(P>0) {
        if(P&1) {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}
long long fact[1000005],inv[1000005];
int main() {
	int t;
	scanf("%d",&t);
	fact[0]=1;
	for(long long i=1;i<=1000000;i++){
		fact[i]=i*fact[i-1];
		fact[i]=(fact[i]>mod)?(fact[i]%mod):fact[i];
	}
	for(int z=1;z<=t;z++){
		int n;
		scanf("%d",&n);
		int arr[n],tt=0;
		for(int i=n-1;i>=0;i--){
			scanf("%d",&arr[i]);
			tt+=arr[i];
		}
		long long x,y,ans=1;
		for(int i=0;i<n;i++){
			x=tt-arr[i];
			if(inv[x]==0){
				inv[x]=BM(fact[x],mod-2,mod);
			}
			x=inv[x];
			y=arr[i]-1;
			if(inv[y]==0){
				inv[y]=BM(fact[y],mod-2,mod);
			}
			y=inv[y];
			ans*=fact[tt-1];
			ans=((ans>mod)?ans%mod:ans);
			ans*=x;
			ans=((ans>mod)?ans%mod:ans);
			ans*=y;
			ans=((ans>mod)?ans%mod:ans);
			tt-=arr[i];
		}
		cout<<"Case "<<z<<": "<<ans<<"\n";
	}
    return 0;
}
