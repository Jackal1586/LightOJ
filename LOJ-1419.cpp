#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long BigMod(long long b,long long p){
    long long ret=1;
    while(p){
        if(p&1)ret=(ret*b)%mod;
        b=(b*b)%mod;
        p>>=1LL;
    }
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        long long n,k,ans=0;
        scanf("%lld%lld",&n,&k);
        for(int i=0;i<n;i++){
            ans=(ans+BigMod(k,__gcd((long long)i,n)))%mod;
        }
        ans*=BigMod(n,mod-2);
        ans%=mod;
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long BigMod(long long b,long long p){
    long long ret=1;
    while(p){
        if(p&1)ret=(ret*b)%mod;
        b=(b*b)%mod;
        p>>=1LL;
    }
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        long long n,k,ans=0;
        scanf("%lld%lld",&n,&k);
        for(int i=0;i<n;i++){
            ans=(ans+BigMod(k,__gcd((long long)i,n)))%mod;
        }
        ans*=BigMod(n,mod-2);
        ans%=mod;
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}
