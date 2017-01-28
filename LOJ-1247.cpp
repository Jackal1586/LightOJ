#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n,m;
        scanf("%d%d",&m,&n);
        long long _xor=0,a,b;
        for(int i=0;i<m;i++){
            a=0;
            for(int j=0;j<n;j++){
                scanf("%d",&b);
                a+=b;
            }
            _xor^=a;
        }
        if(_xor)cout<<"Case "<<z<<": Alice\n";
        else cout<<"Case "<<z<<": Bob\n";
    }
    return 0;
}

