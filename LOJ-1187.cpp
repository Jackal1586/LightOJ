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
    int t;
    t=RI();//scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n,x,y=0;
        n=RI(),x=RI();//scanf("%d%d",&n,&x);
        for(int i=1;i<n;i++){
            x=RI();//scanf("%d",&x);
            if(x<=y)y++;
        }
        y=n-y;
        cout<<"Case "<<z<<": "<<y<<"\n";
    }
    return 0;
}

