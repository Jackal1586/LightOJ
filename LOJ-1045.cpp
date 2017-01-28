#include<bits/stdc++.h>
using namespace std;
double arr[1000000+10];
void calc()
{
    arr[0]=0;
    for(int i=1; i<=1000000; i++)
    {
        arr[i]=(arr[i-1]+log((double)(i)));
    }
}
int main()
{
    calc();
    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        int a;
        double b;
        scanf("%d%lf",&a,&b);
        printf("Case %d: %.0f\n",i,floor(arr[a]/log(b))+1);
    }
    return 0;
}
