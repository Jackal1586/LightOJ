#include<bits/stdc++.h>
using namespace std;
int main(){
long long int n,i,sum,x;
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    scanf("%lld",&n);
    sum=0;
    x=sqrt(n);
    for(i=1;i<=x;i++){
        sum+=(n/i);
    }
    printf("Case %d: %lld\n",z,(sum<<1)-x*x);
}
return 0;
}
