#include<bits/stdc++.h>
using namespace std;
bool vis[10000010];
long long prime[664579+10];
long long sz;
void sieve(){
vis[0]=vis[1]=true;
prime[sz++]=2;
for(long long i=4;i<=10000000;i+=2){vis[i]=true;}
for(long long int i=3;i<=10000000;i+=2){
    if(vis[i]==false){
        prime[sz++]=i;
        for(long long int j=i*i;j<=10000000;j+=(i<<1))vis[j]=true;
    }
}
}
int main(){
    sieve();
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        long long n;
        scanf("%lld",&n);
        long long lim=sqrt(double(n)),ans=1,cnt;
        while(n>0 && (n%2==0)){
            n>>=1;
        }for(long long i=1;(prime[i])<=lim && i<sz;i++){
            cnt=1;
            while(n%prime[i]==0){
                    n/=prime[i];
                    cnt++;
            }ans*=cnt;
            lim=sqrt(double(n));
        }if(n>1)ans*=2;
        cout<<"Case "<<z<<": "<<(ans-1)<<"\n";
    }
    return 0;
}
