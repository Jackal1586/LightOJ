#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
for(int z=1;z<=t;z++){
    long long int s,lp,hp,x,y,mp;
    cin>>s;
    lp=(long long int)(floor(sqrt((double)(s))));
    hp=(long long int)(ceil(sqrt((double)(s))));
    if(lp==hp){
        if(lp&1){
            x=lp,y=1;
        }else x=1,y=lp;
    }else{
        x=y=hp;
        mp=(hp*hp+lp*lp+1)/2;
        if(mp<s){
            if(hp&1){
                y-=(s-mp);
            }else x-=(s-mp);
        }else if(mp>s){
            if(hp&1){
                x-=(mp-s);
            }else y-=(mp-s);
        }
    }
    printf("Case %d: %lld %lld\n",z,y,x);
}
return 0;
}
