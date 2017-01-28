#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
    register int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
	register int x;
        register unsigned char n;
        scanf("%d",&x);
	n=x;
        register unsigned char arr[n+1];
        for(int i=1; i<=n; i++) {
            scanf("%d",&x);
            arr[i]=x;
        }
        register int cnt=0;
        register unsigned char i,j;
        for( i=1; i<=n; i++){
            if(arr[i]!=i){
                for(j=i; j<=n; j++){
                    if(arr[j]==i){
                        swap(arr[i],arr[j]);
                        cnt++;
                        break;
                    }
                }
            }
        }
        cout<<"Case "<<z<<": "<<cnt<<"\n";
    }
    return 0;
}
