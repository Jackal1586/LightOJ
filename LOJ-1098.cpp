#include<bits/stdc++.h>
using namespace std;
typedef long long j86;
int main(){
j86 n;
for(j86 z=1;scanf("%lld",&n)==1 && n;z++){
    j86 ans=0,sq=sqrt(n),low,high,diff;
    for(j86 i=2;i<=sq;i++){
        ans+=((n/i)-1)*i;
    }high=n;
    for(j86 i=1;i<=(sq+1);i++){
        low=(n/(i+1));
        low=max(low,sq);
        diff=high-low;
        ans+=(diff*(2*low+diff+1)/2)*(i-1);
        high=low;
    }
    printf("Case %lld: %lld\n",z,ans);
}
return 0;
}
