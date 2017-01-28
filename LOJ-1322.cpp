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
    t=RI();
    //scanf("%d",&t);
    pair<int,int>arr[t];
    int in[t];
    for(int i=0;i<t;i++){
        arr[i].first=RI();
        //scanf("%d",&arr[i].first);
        in[i]=arr[i].first;
        arr[i].second=i;
    }
    sort(arr,arr+t);
    long long x=1,mod=10000;
    long long ans[t];
    for(long long i=1,j=0;i<=arr[t-1].first;i++){
        x=(1+i*x)%mod;
        while(i==arr[j].first){
            ans[arr[j].second]=x;
            j++;
        }
    }
    for(int i=0;i<t;i++){
        if(in[i]<=6)cout<<"Case "<<i+1<<": "<<ans[i]<<"\n";
        else printf("Case %d: %04lld\n",i+1,ans[i]);
    }
    return 0;
}

