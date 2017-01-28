#include<bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
int t;
scanf("%d",&t);
for(int z=1;z<=t;z++){
    long long int ax,ay,bx,by;
    scanf("%lld%lld%lld%lld",&ax,&ay,&bx,&by);
    cout<<"Case "<<z<<": "<<__gcd(abs(ax-bx),abs(ay-by))+1<<"\n";
}
return 0;
}
