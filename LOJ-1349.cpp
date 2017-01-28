#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n,m,q;
        scanf("%d%d%d",&m,&n,&q);
        int x[m+1],y[n+1],tt,tm,a,b,c;
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        tt=0;
        for(int i=0;i<q;i++){
            scanf("%d%d%d",&a,&b,&c);
            x[a]+=c;
            y[b]+=c;
            tt+=c;
        }
        tm=0;
        for(int i=1;i<=m;i++){
            tm+=x[i];
            if((tm<<1)>=tt){
                a=i;
                break;
            }
        }
        tm=0;
        for(int i=1;i<=n;i++){
            tm+=y[i];
            if((tm<<1)>=tt){
                b=i;
                break;
            }
        }
        cout<<"Case "<<z<<": "<<a<<" "<<b<<"\n";
    }
    return 0;
}

