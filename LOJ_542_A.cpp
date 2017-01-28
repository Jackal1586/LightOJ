#include<bits/stdc++.h>
using namespace std;
int main(){
long long int t,n,sum,m=1000000007,ans;
scanf("%lld",&t);
for(long long z=1;z<=t;z++){
    scanf("%lld",&n);
    sum=(n*(n+1))/2;
    sum%=m;
    ans=((sum%m)*(sum%m))%m;
    cout<<"Case "<<z<<": "<<ans<<"\n";
}
return 0;
}
