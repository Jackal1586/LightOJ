#include<iostream>
#include<string.h>
#include<stdio.h>
#include<wchar.h>
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
int mp[50010];
int main(){
    int t;
    t=RI();
    //scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n;
        n=RI();
        //scanf("%d",&n);
        int a;
        memset(mp,0,sizeof(mp));
        for(int i=0;i<n;i++){
            a=RI();
            //scanf("%d",&a);
            mp[a]++;
        }
        int th;
        for(int i=1;i<=n;i++){
            mp[i]+=mp[i-1];
            if(mp[i]==i){
                th=i;
                break;
            }
        }
        cout<<"Case "<<z<<": "<<th<<"\n";
    }
    return 0;
}

/**
4
1 1 2 3
**/

