#include<bits/stdc++.h>
using namespace std;
unsigned long long ans[5000004];
int phi[5000004];
void PHI(){
    for(register int i=4;i<=5000002;i+=2)phi[i]=i>>1;
    phi[1]=0;
    phi[2]=1;
    for(register int i=3;i<=5000002;i+=2)phi[i]=i;
    for(register int i=3;i<=5000002;i+=2){
        if(phi[i]==i){
            for(register int j=i+i;j<=5000002;j+=i){
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
    for(register int i=1;i<=5000002;i++){
        if(phi[i]==i)phi[i]--;
        unsigned long long x=phi[i];
        ans[i]=ans[i-1]+x*x;
    }
}
int main() {
    PHI();
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int a,b;
        scanf("%d%d",&a,&b);
        cout<<"Case "<<z<<": "<<ans[b]-ans[a-1]<<"\n";
    }
    return 0;
}
