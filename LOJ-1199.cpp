#include<bits/stdc++.h>
using namespace std;
int t,n,gn[10002],vis[10002],a,_xor;
int main(){
    for(int i=1;i<=10000;i++){
        for(int j=1;2*j<i;j++){
            vis[gn[j]^gn[i-j]]=i;
        }
        for(int j=0;;j++){
            if(vis[j]!=i){
                gn[i]=j;
                break;
            }
        }
    }
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d",&n);
        _xor=0;
        while(n--){
            scanf("%d",&a);
            _xor^=gn[a];
        }
        if(_xor)cout<<"Case "<<z<<": Alice\n";
        else cout<<"Case "<<z<<": Bob\n";
    }
    return 0;
}

