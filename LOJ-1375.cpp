#include<bits/stdc++.h>
using namespace std;
int phi[3000004];
unsigned long long s2[3000004],ans[3000004];
void PHI() {
    for(register int i=4; i<=3000002; i+=2)phi[i]=i>>1;
    phi[1]=0;
    phi[2]=1;
    for(register int i=3; i<=3000002; i+=2)phi[i]=i;
    for(register int i=3; i<=3000002; i+=2) {
        if(phi[i]==i) {
            for(register int j=i+i; j<=3000002; j+=i) {
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
    for(register int i=1; i<=3000002; i++) {
        if(phi[i]==i)phi[i]--;
    }
}
void S2() {
    for(int i=1; i<=3000002; i++) {
        unsigned long long x=i,y=phi[i];
        for(int j=i; j<=3000002; j+=i) {
            s2[j]+=x*y/2*j;
        }
    }
}
void calc() {
    for(int i=1; i<=3000002; i++) {
        ans[i]=ans[i-1]+s2[i];
    }
}
int main() {
    PHI();
    S2();
    calc();
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        int n;
        scanf("%d",&n);
        cout<<"Case "<<z<<": "<<ans[n]<<"\n";
    }
    return 0;
}
