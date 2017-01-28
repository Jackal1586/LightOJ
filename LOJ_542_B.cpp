#include<bits/stdc++.h>
using namespace std;
int main(){
long long t;
scanf("%lld",&t);
for(long long z=1;z<=t;z++){
    double a,r,d,area;
    scanf("%lf",&a);
    area=(3.0*sqrt(3.0)/16.0)*a*a;
    printf("Case %lld: %.0lf\n",z,area);
}
return 0;
}
