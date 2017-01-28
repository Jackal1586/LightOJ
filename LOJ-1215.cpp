#include<bits/stdc++.h>
using namespace std;
bool vis[1000010];
vector<long long int>prime;
void sieve()
{
    vis[0]=vis[1]=true;
    for(int i=4; i<=1000000; i+=2)vis[i]=true;
    for(int i=3; i*i<=1000000; i+=2)if(!vis[i])for(int j=i*i; j<=1000000; j+=i)vis[j]=true;
    for(int i=2; i<=1000000; i++)if(!vis[i])prime.push_back(i);
}
map<long long int,long long int>ma,mb,ml,mc;
map<long long int,long long int> divisor(long long int n)
{
    long long int x=sqrt(n);
    map<long long int,long long int>mp;
    for(int i=0; prime[i]<=x ; i++)
    {
        while(n%prime[i]==0)
        {
            n/=prime[i];
            mp[prime[i]]++;
        }
    }
    if(n>1)mp[n]++;
    return mp;
}
int main()
{
    sieve();
    int t;
    long long int a,b,l,c;
    scanf("%d",&t);
    for(int z=1; z<=t; z++)
    {
        scanf("%lld%lld%lld",&a,&b,&l);
        ma=divisor(a);
        mb=divisor(b);
        ml=divisor(l);
        c=1;
        for(map<long long int,long long int>::iterator i=ml.begin(); i!=ml.end(); i++)
        {
            if((ma[i->first]>i->second)||(mb[i->first]>i->second))
            {
                c=-1;
                break;
            }
            else if((ma[i->first]==i->second)||(mb[i->first]==i->second));
            else {for(int j=0;j<i->second;j++)c*=i->first;}
        }
        for(map<long long int,long long int>::iterator i=ma.begin(); i!=ma.end(); i++)
        {
            if(ml[i->first]<i->second)
            {
                c=-1;
                break;
            }
        }
        for(map<long long int,long long int>::iterator i=mb.begin(); i!=mb.end(); i++)
        {
            if(ml[i->first]<i->second)
            {
                c=-1;
                break;
            }
        }
        if(c!=-1)cerr<<"Case "<<z<<": "<<c<<"\n";
        else cerr<<"Case "<<z<<": impossible\n";
    }
    return 0;
}
