#include<bits/stdc++.h>
using namespace std;
inline int RI() {
    int  ret = 0, flag = 1,ip = getchar_unlocked();
    for(; ip < 48 || ip > 57; ip = getchar_unlocked()) {
        if(ip == 45) {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}
int main(){
    int t=RI();
    //scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int r=RI(),c=RI(),a,_xor=0;
        //scanf("%d%d",&r,&c);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                a=RI();//scanf("%d",&a);
                if((r+c-i-j)&1){
                    _xor^=a;
                }
            }
        }
        if(_xor)cout<<"Case "<<z<<": win\n";
        else cout<<"Case "<<z<<": lose\n";
    }
    return 0;
}
