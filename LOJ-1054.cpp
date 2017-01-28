#include<bits/stdc++.h>
using namespace std;
bool vis[66010];
const long long int m=1000000007;
long long int prime[35000];
int sz;
void sieve(){
    vis[0]=vis[1]=true;
    prime[sz++]=2;
    for(int i=4;i<=66000;i+=2)vis[i]=true;
    for(long long int i=3;i<=66000;i+=2){
            if(!vis[i]){
                prime[sz++]=i;
                for(long long int j=i*i;j<=66000;j+=(i<<1))vis[j]=true;
            }
    }
}
long long int BM(long long int a,long long int p){
    long long R=1;
	while(p>0)
	{
		if(p%2==1)
		{
			R=(R*a)%m;
		}
		p/=2;
		a=(a*a)%m;
	}
	return R;
}
int main(){
sieve();
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    long long int p,q,d=((((-1)%m)+m)%m);
    scanf("%lld %lld",&p,&q);
    map<long long int,long long int>mp;
    for(int i=0;(prime[i]*prime[i])<=p && i<sz;i++){
        while(p%prime[i]==0){
            p/=prime[i];
            mp[prime[i]]+=q;
        }
    }if(p>1)mp[p]+=q;
    long long int ans=1;
    for(map<long long int,long long int>::iterator i=mp.begin();i!=mp.end();i++){
        long long int x=(BM(i->first,i->second+1)%m+d%m)%m;
        long long int y=BM((i->first%m+d),m-2)%m;
        ans*=((x%m)*(y%m))%m;
        ans%=m;
    }
    printf("Case %d: %lld\n",z,ans);
}
return 0;
}
