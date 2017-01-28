#include<bits/stdc++.h>
#define pi 2.0*acos(0.0)
using namespace std;
int main()
{
    int t;
    double h,p,r1,r2,r,ans;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lf%lf%lf%lf",&r1,&r2,&h,&p);
        r=(p*r1+(h-p)*r2)/h;
        ans=r*r+r*r2+r2*r2;
        ans*=((1.0/3.0)*pi*p);
        printf("Case %d: %.9lf\n",i,ans+1e-10);
    }
    return 0;
}
