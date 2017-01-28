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
int n,m,a[102],c[102],nc[100005],ans;
bool vis[100005];
int main(){
    int t;
    t=RI();//scanf("%d",&t);
    for(int z=1;z<=t;z++){
        n=RI(),m=RI();//scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            a[i]=RI();//scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            c[i]=RI();//scanf("%d",&c[i]);
        }
        ans=0;
        memset(vis,0,sizeof(vis));
        vis[0]=1;
        for(register int i=0;i<n;i++){
            for(register int j=0;j<=m;j++){
                if(vis[j]==1)nc[j]=0;
                else nc[j]=1<<28;
            }
            for(register int j=0;j<=m;j++){
                if(vis[j]==1 && j+a[i]<=m && nc[j+a[i]]>nc[j]+1 && nc[j]<c[i]){
                    vis[j+a[i]]=1;
                    nc[j+a[i]]=nc[j]+1;
                }
            }
        }
        for(register int i=1;i<=m;i++){
            ans+=(vis[i]==1);
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

