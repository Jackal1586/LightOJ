#include<bits/stdc++.h>
using namespace std;
int f(int a,int b,bool c){
    int sum=0;
    while(a){
        if(c && (a%b))break;
        if(c)sum++;
        else sum+=(a/b);
        a/=b;
    }return sum;
}
int main(){
int t,n,r,p,q;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    scanf("%d%d%d%d",&n,&r,&p,&q);
    printf("Case %d: %d\n",z,min((f(n,2,0)-(f(n-r,2,0)+f(r,2,0))+q*f(p,2,1)),(f(n,5,0)-(f(n-r,5,0)+f(r,5,0))+q*f(p,5,1))));
}
return 0;
}
