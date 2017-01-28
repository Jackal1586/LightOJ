#include<bits/stdc++.h>
#define MAX 10004569
#define LMT 3163
#define LEN 664863
using namespace std;
unsigned base[MAX/64],prime[LEN],sz;
#define sq(x) ((x)*(x))
#define mset(x,v) memset(x,v,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))
void sieve()
{
    prime[sz++]=2;
    unsigned i,j,k;
    for(i=3;i<LMT;i+=2)if(!chkC(base,i))for(j=i*i, k=i<<1; j<MAX; j+=k)setC(base,j);
    for(i=3;i<MAX;i+=2)if(!chkC(base,i))prime[sz++]=i;
}
long long divisor(long long n){
    long long ret=1,cnt,lim=sqrt(n),sum=0;
    for(int i=0;i<sz && prime[i]<=lim;i++){
        if(n%prime[i]==0){
            cnt=0;
            while(n%prime[i]==0){
            n/=prime[i];
            cnt++;
        }ret*=(2*cnt+1);
        lim=sqrt(n);
        }
    }if(n>1)return ret*3;
    return ret;
}
int main(){
sieve();
//cout<<sz<<endl<<endl;
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    long long n;
    scanf("%lld",&n);
    long long ans=divisor(n);
    //cout<<ans.first<<" "<<ans.second<<endl;
    cout<<"Case "<<z<<": "<<(((ans-1LL)/2LL)+1LL)<<"\n";
}
return 0;
}
