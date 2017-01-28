#include<bits/stdc++.h>
using namespace std;
const long long int mod=1000000007;
long long int arr[2000002];
inline long long BM(long long a,long long m) {
    long long ans=1;
    while(m>0) {
        if(m&1) {
            ans=(ans*a)%mod;
        }
        m>>=1;
        a=(a*a)%mod;
    }return ans;
}
int main() {
    //srand(time(NULL));
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    long long n,k;
    arr[0]=arr[1]=1;
    for(long long int i=2; i<=2000000; i++) {
        arr[i]=(i*(arr[i-1]))%mod;
    }
    for(int z=1;z<=t;z++) {
        //n=rand()%1000000;
        //k=(rand()%999999)+1;
        scanf("%lld%lld",&n,&k);
        cout<<"Case "<<z<<": "<<(arr[n+k-1]*BM((arr[k-1]*arr[n])%mod,mod-2))%mod<<"\n";
    }
    return 0;
}

