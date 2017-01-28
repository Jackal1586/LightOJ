#include<bits/stdc++.h>
using namespace std;
double pi = 2*acos(0.0);
int main()
{
    int T;
    double a,b,x;
    //printf("%.20lf",pi);
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        cin>>a;
        char c;
        cin>>c;
        cin>>b;
        x=400.0/(2.0*a + pi*b);
        printf("Case %d: %.8lf %.8lf\n",i,a*x,b*x);
    }
    return 0;
}
