#include<bits/stdc++.h>
using namespace std;
#define pi 2.0*acos(0.0)
int main()
{
    int T;
    double x1,y1,r1,x2,y2,r2;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2);
        double a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        double c=acos((a*a+r1*r1-r2*r2)/(2.0*r1*a));
        double d=acos((a*a+r2*r2-r1*r1)/(2.0*r2*a));
        if(c>(pi/2))c=pi-c;
        else if(c>pi)c-=pi;
        else if(c>(3.0*pi/2.0))c=2.0*pi-c;
        if(d>(pi/2))d=pi-d;
        else if(d>pi)d-=pi;
        else if(d>(3.0*pi/2.0))d=2.0*pi-d;
        cout<<c<<endl<<d<<endl;
        printf("Case %d: %.10lf\n",i,c*r1*r1/2.0 + d*r2*r2/2.0 - r1*r1*sin(c) - r2*r2*sin(d));
    }
    return 0;
}
