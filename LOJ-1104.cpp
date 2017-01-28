#include<bits/stdc++.h>
using namespace std;
int main() {
    register int t;
    scanf("%d",&t);
    for(register int z=1; z<=t; z++) {
        register double n;
        scanf("%lf",&n);
        register double p=1;
        register double x=n-1;
        register int d=1;
        while(p>0.5){
                p*=(x/n);
                x--;
                d++;
        }
        d--;
        cout<<"Case "<<z<<": "<<d<<"\n";
    }
    return 0;
}
