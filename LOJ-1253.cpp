#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int k,a,_xor=0,cnt=0;
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            scanf("%d",&a);
            if(a>1){
                cnt++;
            }
            _xor^=a;
        }
        cout<<"Case "<<z<<": ";
        if(cnt>0){
            if(_xor)puts("Alice");
            else puts("Bob");
        }else{
            if(_xor)puts("Bob");
            else puts("Alice");
        }
    }
    return 0;
}
