#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    int a=2,b,n,cnt=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&b);
        if(b>a)cnt+=(b-a+5)/5;
        a=b;
    }
    cout<<"Case "<<z<<": "<<cnt<<"\n";
}
return 0;
}
