#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,n,x1,x2,y1,y2,z1,z2;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d",&n);
        int a=-1,b=-1,c=-1,d=1<<30,e=1<<30,f=1<<30;
        while(n--)
        {
            scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
            if(x1>a)a=x1;
            if(y1>b)b=y1;
            if(z1>c)c=z1;
            if(x2<d)d=x2;
            if(y2<e)e=y2;
            if(z2<f)f=z2;
        }
        int s=((d-a)*(e-b)*(f-c));
        printf("Case %d: %d\n",i,s<0?0:s);
    }
    return 0;
}
