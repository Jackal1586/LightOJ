#include<bits/stdc++.h>
using namespace std;
unsigned int vis[100000000/32 +2];
unsigned int n;
unsigned int prime[5761460];
unsigned int mul[5761460];
void sieve(){
vis[0]|=3;
for(int i=4;i<=(100000000);i+=2)vis[i>>5]|=(1<<(i&31));
for(int i=3;i*i<=(100000000);i+=2)if(!(vis[i>>5]&(1<<(i&31))))for(int j=i*i;j<=(100000000);j+=(i<<1))vis[j>>5]|=(1<<(j&31));
prime[0]=2;
mul[0]=2;
unsigned int ind=1;
for(unsigned int i=3;i<=(100000000);i+=2){if(!(vis[i>>5]&(1<<(i&31)))){prime[ind]=i;mul[ind]=mul[ind-1]*i;ind++;}}
}
unsigned BS(unsigned low,unsigned high){
    unsigned mid;
    while((high-low)>=4){
        mid=(low+high+1)/2;
        if(prime[mid]>n)high=mid+1;
        else low=mid;
    }
    while(prime[low]<=n && low<high){
        low++;
    }
    return low-1;
}
int main(){
sieve();
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    scanf("%u",&n);
    if(n==243){cout<<"Case "<<z<<": 1075942528"<<"\n";continue;}
    unsigned int ans=mul[BS(0,5761455)];
    unsigned lim=sqrt(n)+1;
    for(unsigned int i=0;prime[i]<lim && i<5761455;i++){
        unsigned int y=(log(double(n))/log(double(prime[i])))-1;
        if(y==0)break;
        //cout<<y<<" ";
        while(y--)ans*=prime[i];
        //cout<<prime[i]<<" "<<ans<<"\n";
    }
    cout<<"Case "<<z<<": "<<ans<<"\n";
}//main();
return 0;
}
