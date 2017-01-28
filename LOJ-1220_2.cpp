#include<bits/stdc++.h>
#define MAX 46656
#define LMT 216
#define LEN 4830
using namespace std;
unsigned base[MAX/64],sz,prime[LEN];
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))
void sieve() {
    unsigned i, j, k;
    for(i=3; i<LMT; i+=2)
        if(!chkC(base, i))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                setC(base, j);
    prime[0]=2;
    for(i=3, j=1; i<MAX; i+=2)
        if(!chkC(base, i))
            prime[j++] = i;
    sz=j;
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    sieve();
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        long long int n;
        bool sign=0;
        scanf("%lld",&n);
        if(n<0) {
            n*=-1;
            sign=1;
        }
        int ans=-1,cnt;
        for(int i=0;i<sz && prime[i]*prime[i]<=n;i++){
			cnt=0;
			if(n%prime[i]==0){
				while(n%prime[i]==0){
					n/=prime[i];
					cnt++;
				}
				if(ans==-1)ans=cnt;
				else ans=__gcd(ans,cnt);
			}
        }
        if(n>1){
			ans=1;
        }
        if(sign && !(ans&1)){
			while(!(ans&1)){
				ans>>=1;
			}
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
	}
    return 0;
}

