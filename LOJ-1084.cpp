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
int n,k,l[100003],dp[100003];
int rec(int ii){
    if(ii==n)return 0;
    if(dp[ii]!=-1)return dp[ii];
    int ret=12345678,cnt=0;
    for(int i=ii+1;i<n && (l[i]-l[ii])<=k;i++){
        cnt++;
        if(cnt>=2){
            ret=min(ret,1+rec(i+1));
        }
    }
    return dp[ii]=ret;
}
int main(){
    int t;
    t=RI();//scanf("%d",&t);
    for(int z=1;z<=t;z++){
        n=RI(),k=RI();//scanf("%d%d",&n,&k);
        k<<=1;
        for(int i=0;i<n;i++){
            l[i]=RI();//scanf("%d",&l[i]);
        }
        sort(l,l+n);
        memset(dp,-1,sizeof(dp));
        //x=z;
        int ans=rec(0);
        if(ans>=12345678)ans=-1;
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

