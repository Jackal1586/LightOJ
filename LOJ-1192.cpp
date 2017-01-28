#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int k;
        scanf("%d",&k);
        //k<<=1;
        int x,y,a=0;
        //scanf("%lld",&x);
        for(int i=0;i<k;i++){
            scanf("%d%d",&x,&y);
            a^=(y-x-1);
            //x=y;
        }
        if(a!=0)cout<<"Case "<<z<<": Alice\n";
        else cout<<"Case "<<z<<": Bob\n";
    }
    return 0;
}

