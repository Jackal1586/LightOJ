#include<bits/stdc++.h>
using namespace std;
int t,n,a,_xor;
int rec(int x){
    if(x==1)return 0;
    if(x&1)return rec(x>>1);
    return x>>1;
}
int main(){
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d",&n);
        _xor=0;
        while(n--){
            scanf("%d",&a);
            _xor^=rec(a);
        }
        if(_xor)cout<<"Case "<<z<<": Alice\n";
        else cout<<"Case "<<z<<": Bob\n";
    }
    return 0;
}

