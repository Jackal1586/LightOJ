#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define eps 1e-8
int main()
{
    int t;
    double r1,r2,h,p,r;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lf%lf%lf%lf",&r1,&r2,&h,&p);
        r=(p/h)*r1;
        printf("Case %d: %.6lf\n",i,(pi*p*(r*r+r*r2+r2*r2))/3.0+eps);
    }
    return 0;
}
