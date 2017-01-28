#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long lcm(long long a,long long b){return ((a*b)/__gcd(a,b));}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        long long n;
        int m;
        scanf("%lld%d",&n,&m);
        long long arr[m];
        for(int i=0;i<m;i++)scanf("%lld",&arr[i]);
        long long ans=0;
        for(int i=0;i<(1<<m);i++){
            long long x=1,y=0;
            for(int j=0;j<m;j++){
                if(i&(1<<j)){
                    y++;
                    x=lcm(x,arr[j]);
                    if(x>n)break;
                }
            }
            ans+=((1-2*(y&1))*(n/x));
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

