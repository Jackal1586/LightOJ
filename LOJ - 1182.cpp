#include<bits/stdc++.h>
using namespace std;
int Bits(int i)
{
i = i - ((i >> 1) & 0x55555555);
i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        bool a=Bits(n)&1;
        if(a)printf("Case %d: odd\n",i);
        else printf("Case %d: even\n",i);
    }
    return 0;
}
