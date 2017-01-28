#include<bits/stdc++.h>
using namespace std;
#define eps 1e-11
#define gm 0.57721566490153286060651209008240243104215933593992
double arr[1000005];
int main(){
arr[0]=1;
for(register int i=1;i<1000005;i++){
    arr[i]=arr[i-1]+((double)1/((double)(i+1)));
}
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    int n;
    scanf("%d",&n);
   if(n<1000005)printf("Case %d: %.10f\n",z,arr[n-1]+eps);
    else printf("Case %d: %.10f\n",z,eps+gm+(log(n)+log(n+1))/2);
}
return 0;
}
