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
int n,q,p[100003],st[100003][17],k,v,lim,ans;
int main(){
    int t;
    t=RI();//scanf("%d",&t);
    for(int z=1;z<=t;z++){
        n=RI(),q=RI();//scanf("%d%d",&n,&q);
        memset(st,-1,sizeof(st));
        p[0]=1;
        for(int i=1;i<n;i++){
            st[i][0]=RI(),p[i]=RI();//scanf("%d%d",&st[i][0],&p[i]);
        }
        lim=0;
        for(int i=1;(1<<i)<=n;i++){
            lim++;
            for(int j=0;j<n;j++){
                if(st[j][i-1]!=-1){
                    st[j][i]=st[st[j][i-1]][i-1];
                }
            }
        }
        cout<<"Case "<<z<<":\n";
        while(q--){
            scanf("%d%d",&k,&v);
            for(int i=lim;i>=0;i--){
                if(st[k][i]!=-1 && p[st[k][i]]>=v){
                    k=st[k][i];
                }
            }
            cout<<k<<"\n";
        }
    }
    return 0;
}

