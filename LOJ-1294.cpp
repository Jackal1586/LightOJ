#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    long long int n,m;
    scanf("%lld %lld",&n,&m);
    n/=2;
    printf("Case %d: %lld\n",z,n*m);
}
return 0;
}
