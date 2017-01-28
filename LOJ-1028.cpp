#include<bits/stdc++.h>
using namespace std;
bool flag[1000010];
vector<long long int>prime;
#define SIZE_N 1000000
void sieve()
{
    long long int i,j,val;
    for(i=2; i<=SIZE_N; i++) flag[i]=1;
    val=sqrt(SIZE_N)+1;
    for(i=2; i<val; i++)if(flag[i])for(j=i; j*i<=SIZE_N; j++)flag[i*j]=0;
    for(i=2; i<=SIZE_N; i++)if(flag[i])prime.push_back(i);
}
//long long int divisor(long long int n)
//{
//    //if(n<1000000 && flag[n])return 1;
//    long long int ans=1,cnt=1,val=(long long int)(sqrt((long double)(n))+1);
//    for(long long int i=0; prime[i]<=val && i<SIZE_N; i++)
//    {
//        cnt=1;
//        long long int x=prime[i];
//        //if(prime[i]>n)break;
//        while((n%prime[i])==0)
//        {
//            //cerr<<prime[i]<<endl;
//            n=n/prime[i];
//            cnt++;
//        }
//        ans*=cnt;
//        val=sqrt(n)+1;
//    }
//    if(n>1)ans*=2;
//    return ans;
//}
int main()
{
    sieve();
    long long int t;
    //cout<<(0%4)<<endl;
    scanf("%lld",&t);
    for(long long int z=1; z<=t; z++)
    {
        long long int n;
        scanf("%lld",&n);
        long long int ans=1,cnt=1,val=(long long int)(sqrt((long double)(n))+1);
        for(long long int i=0; prime[i]<=val && i<SIZE_N; i++)
        {
            cnt=1;
            long long int x=prime[i];
            //if(prime[i]>n)break;
            while((n%prime[i])==0)
            {
                //cerr<<prime[i]<<endl;
                n=n/prime[i];
                cnt++;
            }
            ans*=cnt;
            val=sqrt(n)+1;
        }
        if(n>1)ans*=2;
        printf("Case %lld: %lld\n",z,ans-1);
    }
    return 0;
}
