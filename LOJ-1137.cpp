#include<bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;
double l,L,n,c,r,start,endp,mid;
bool flag=0;
bool ok() {
    double rat=((2.0*sin(mid/2))/mid);
    return rat>(l/L);
}
int main() {
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        double ans;
        scanf("%lf%lf%lf",&l,&n,&c);
        L=(1+n*c)*l;
        if((pi*l)>(L*2)) {
            start=0.0;
            endp=pi;
        } else if((pi*l)<(L*2)) {
            start=pi;
            endp=2*pi;
        } else {
            ans=l/2.0;
            printf("Case %d: %.8f\n",z,ans);
            continue;
        }
        mid=((start+endp)/2.0);
        for (int i=0; i<500; i++) {
            if(ok())start=mid;
            else endp=mid;
            mid=(start+endp)/2.0;
        }
        ans=(L/mid)*(1-cos(mid/2.0));
        printf("Case %d: %.8f\n",z,ans);
    }
    return 0;
}
