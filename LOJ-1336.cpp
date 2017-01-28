#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    long long  n,ans,s1,s2;
    scanf("%lld",&n);
        s1=sqrt(n);
        s2=n/2;
        s2=sqrt(s2);
        ans=n-s1-s2;
        printf("Case %d: %lld\n",z,ans);
}
return 0;
}
