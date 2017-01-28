#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
//freopen("input.txt","r",stdin);
scanf("%d",&t);
for(int z=1;z<=t;z++){
    long long w,x;
    scanf("%lld",&w);
    if(w&1){
        cout<<"Case "<<z<<": Impossible\n";
        continue;
    }
    x=w;
    while(!(w&1)){
        w/=2;
    }cout<<"Case "<<z<<": "<<w<<" "<<x/w<<"\n";
}
return 0;
}
