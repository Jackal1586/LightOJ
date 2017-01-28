#include<bits/stdc++.h>
using namespace std;
bool vis[100010];
const long long int M=10000019;
long long int prime[40000];
int sz;
void sieve(){
    vis[0]=vis[1]=true;
    prime[sz++]=2;
    for(int i=4;i<=100000;i+=2)vis[i]=true;
    for(long long int i=3;i<=100000;i+=2){
        if(vis[i]==false){
            prime[sz++]=i;
            for(long long int j=i*i;j<=100000;j+=(i<<1)){
                vis[j]=true;
            }
        }
    }
}
long long int BM(long long B,long long P)
{
	long long R=1;
	while(P>0)
	{
		if(P%2==1)
		{
			R=(R*B)%M;
		}
		P/=2;
		B=(B*B)%M;
	}
	return R;
}
int main(){
sieve();
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    long long int n,f;
    scanf("%lld%lld",&n,&f);
    long long int ans=1;
    for(int i=0;prime[i]<=n && i<sz;i++){
        long long int m=n;
        long long int cnt=0;
        while(m){
            cnt+=(m/prime[i]);
            m/=prime[i];
        }if(cnt>=f){
            ans*=(BM(prime[i],cnt/f)%M);
            ans%=M;
        }
    }if(ans==1)printf("Case %d: -1\n",z);
    else printf("Case %d: %lld\n",z,ans%M);
}
return 0;
}
