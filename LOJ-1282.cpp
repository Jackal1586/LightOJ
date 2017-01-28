#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    long long n,k,fact,lead,trail,m;
    scanf("%lld %lld",&n,&k);
    m=n,fact=n%1000,trail=1;
    while(m){
        if(m&1)trail=((trail)*(fact))%1000;
        fact=(fact*fact)%1000;
        m>>=1;
    }
    double f=((double)(n))*(log((double)(k))/log(10.0));
    f=f-floor(f);
    f=pow(10,f);
    f*=1000.0;
    lead=((long long)(f));
    cout<<"Case "<<z<<": "<<lead<<" "<<trail<<"\n";
}
return 0;
}
