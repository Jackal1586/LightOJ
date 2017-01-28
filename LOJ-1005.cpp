#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    long long int n,k;
    scanf("%lld%lld",&n,&k);
    if(n<k)printf("Case %d: 0\n",z);
    else {
        long long int neu=1,den=1;
        for(int i=n;i>(n-k);i--)neu*=i;
        for(int i=1;i<=k;i++)den*=i;
        long long int ans=neu*(neu/den);
        printf("Case %d: %lld\n",z,ans);
    }
}
return 0;
}
