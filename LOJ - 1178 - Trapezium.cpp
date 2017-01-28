#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define eps 1e-8
int main()
{
    int t;
    double a,b,c,d,s,e,f;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        if(a<c)swap(a,c);
        s=a-c;
        e=acos((d*d+s*s-b*b)/(2.0*d*s));
        f=d*sin(e);
        printf("Case %d: %.6lf\n",i,0.5*f*(a+c)+eps);
    }
    return 0;
}
