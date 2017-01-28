#include<bits/stdc++.h>
using namespace std;
bool prime[1009];
int m[1010];
void sieve()
{
    for(int i=2; i<=1005; i++)prime[i]=1;
    int k=2;
    for(int i=2; i*i<=1005; i++)
    {
        for(int j=k+k; j<=1005; j+=k)
            prime[j]=0;
        k++;
        for(; !prime[k]; k++);
    }
}
int div(int n)
{
    int a=1,b;
    int i=2;
    if(n==0)return numeric_limits<int>::max();
    else if(prime[n] || n==1)return 1;
    while(n!=1)
    {
        if(prime[i])
        {
            b=1;
            while(!(n%i))
            {
                b++;
                n/=i;
            }
            a*=b;
        }
        i++;
    }
    return a;
}
bool comp(int a,int b)
{
    bool s;
    int p,q;
    p=div(a);
    q=div(b);
    if(p<q)s=1;
    else if(p==q && a>b)s=1;
    else s=0;
    return s;
}
int main()
{
    for(int i=0; i<=1005; i++)m[i]=i;
    sieve();
    sort(m+2,m+1001,comp);
    int t,d;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        scanf("%d",&d);
        printf("Case %d: %d\n",i,m[d]);
    }
    return 0;
}
