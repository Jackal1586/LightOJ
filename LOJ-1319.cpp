#include<bits/stdc++.h>
using namespace std;
int n;
int p[15],r[15];
long long EE(long long a,long long b,long long &x,long long &y){
    if(b==0){
        x=1, y=0;
        return a;
    }long long d = EE(b, a%b, y, x);
    y = y-(a/b)*x;
    return d;
}
long long IM(long long a,long long m){
    long long x, y, d;
    d = EE(a, m, x, y);
    if(d==1) return (x+m)%m;
    return -1;
}
int main(){
int t;
//freopen("input.txt","r",stdin);
//cout<<IM(2,2);
scanf("%d",&t);
for(int z=1;z<=t;z++){
    scanf("%d",&n);
    long long x[n],mul=1,y[n];
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i],&r[i]);
        mul*=p[i];
    }long long l=0;
    for(int i=0;i<n;i++){
        l+=((r[i]*(IM(mul/p[i],p[i])*((mul/p[i]))))%mul);
    }l%=mul;
    //l=IM(l,mul);
    cout<<"Case "<<z<<": "<<l<<"\n";
}
return 0;
}
