#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
int main()
{
    int t;
    double x1,y1,r1,x2,y2,r2,x,y,r;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2,&x,&y,&r);
        double a=0,b;
        b=(y2-y1)*x/(x2-x1);
        if(y1>y2)
        {
            a+=((y-r)-b);
            x2-=r2;
            a+=(x2-x)/(2.0*pi*r);
        }
        else if(y1<y2)
        {
            a+=((y-r)-b);
            x1-=r1;
            a+=(x1-x)/(2.0*pi*r);
        }
        else if(y1==y2)a+=(y-r-y1);
        printf("Case %d: %.0lf\n",i,a);
    }
    return 0;
}
